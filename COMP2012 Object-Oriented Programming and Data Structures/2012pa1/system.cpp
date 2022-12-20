#include <iostream>
#include <cstring>
#include "system.h"
#include "student.h"
#include "course.h"
#include "course_database.h"
#include "student_database.h"
#include "wait_list.h"
#include "swap_list.h"

using namespace std;

/*
The following 3 helper functions may be useful in add/swap/drop function. You may implement them if you find them useful.
If not, you can remove these 3 helper functions as we will NOT set any test case testing these helper functions.
*/

// Helper function: add the Student to the end of the waitlist of the Course.
void join_waitlist(const int student_id, Course* course) {
    Wait_List* list = course->get_wait_list();
    Student_ListNode* new_student = new Student_ListNode(student_id,nullptr);
        if (list->get_head() != nullptr){
            list->get_end()->next = new_student;
            list->set_end(new_student);
        }
        else{
            list->set_head(new_student);
            list->set_end(new_student);
        }
    // TODO
}

// Helper function: find the index of a course within the enrolled course list of a student.
int search_course_index(const Student* const student, const char* const course_name) {
    char** enrolled_course = student->get_enrolled_courses();
    for (int i=0;i<student->get_num_enrolled_course();i++){
        if(strcmp(enrolled_course[i],course_name)==0){
            return i;
        }
    }
    // TODO
    return -1;
}

// Helper function: find the index of the student_id in the enrolled student list
int search_student_id(const int student_id, const Course* const course) {
    int* student_enrolled = course->get_students_enrolled();
    for (int i=0;i<course->get_size();i++){
        if(student_enrolled[i] == student_id){
            return i;
        }
    }
    // TODO
    return -1;
}


System::System(const int max_num_course, const int max_num_student) {
    course_database = new Course_Database(max_num_course);
    student_database = new Student_Database(max_num_student);
}

System::System(const System& system) {
    
    this->course_database = new Course_Database(*system.course_database);
    
    this->student_database = new Student_Database(*system.student_database);
    
}

System::~System() {
    delete course_database;
    delete student_database;
}

void System::admit(const char* const name, const int student_id, const double gpa) {
    this->student_database->create_entry(name, student_id, gpa);
}

bool System::apply_overload(const int student_id, const int request_credit) {
    if (request_credit > 30){
        return false;
    }
    if (request_credit >= 24){
        if (student_database->get_student_by_id(student_id)->get_gpa() < 3.7){
            return false;
        }
    }
    if (request_credit > 18){
         if (student_database->get_student_by_id(student_id)->get_gpa() < 3.3){
            return false;
        }
    }
    student_database->get_student_by_id(student_id)->set_max_credit(request_credit);
    return true;
    // TODO
}

bool System::add(const int student_id, const char* const course_name) {
    Student* student = student_database->get_student_by_id(student_id);
    Course* course = course_database->get_course_by_name(course_name);
    if (student->get_curr_credit() + student->get_pending_credit() + course->get_num_credit() > student->get_max_credit()){
        return false;
    }
    
    if (course->get_size() + 1 <= course->get_capacity()){
        course->get_students_enrolled()[course->get_size()] = student_id;
        course->set_size(course->get_size()+1);
        student->get_enrolled_courses()[student->get_num_enrolled_course()] = new char[strlen(course_name)+1];
        strcpy(student->get_enrolled_courses()[student->get_num_enrolled_course()],course_name);
        student->set_num_enrolled_course(student->get_num_enrolled_course()+1);
        student->set_curr_credit(student->get_curr_credit()+course->get_num_credit());
    }
    else{
        student->set_pending_credit(student->get_pending_credit()+ course->get_num_credit());
        join_waitlist(student_id,course);
        
    }

    return true;
    // TODO
}

bool System::swap(const int student_id, const char* const original_course_name, const char* const target_course_name) {
    Student* student = student_database->get_student_by_id(student_id);
    Course* ori_course = course_database->get_course_by_name(original_course_name);
    Course* tar_course = course_database->get_course_by_name(target_course_name);
    
    if (student->get_curr_credit() + student->get_pending_credit() + (tar_course->get_num_credit()-ori_course->get_num_credit()) > student->get_max_credit()){
        return false;
    }
    
    if (tar_course->get_size() + 1 <= tar_course->get_capacity()){
        //enroll in course
        tar_course->get_students_enrolled()[tar_course->get_size()] = student_id;
        tar_course->set_size(tar_course->get_size()+1);
        
        student->get_enrolled_courses()[student->get_num_enrolled_course()] = new char[strlen(target_course_name)+1];
        
        strcpy(student->get_enrolled_courses()[student->get_num_enrolled_course()],target_course_name);
        
        
        student->set_num_enrolled_course(student->get_num_enrolled_course()+1);
        student->set_curr_credit(student->get_curr_credit()+tar_course->get_num_credit());

        //drop the original course
        
        drop(student_id,original_course_name);
        
    }
    else{
        if (tar_course->get_num_credit()-ori_course->get_num_credit()>0){
            student->set_pending_credit(student->get_pending_credit() + (tar_course->get_num_credit()-ori_course->get_num_credit()));
        }
        
        join_waitlist(student_id,tar_course);
        
        Swap_List* swap_list = student->get_swap_list();
        Swap* swap_action = new Swap(original_course_name,target_course_name,swap_list->get_head());
        swap_list->set_head(swap_action);
        
    }
    return true;
    // TODO
    
}

void System::drop(const int student_id, const char* const course_name) {

    Course* course = course_database->get_course_by_name(course_name);
    Student* student = student_database->get_student_by_id(student_id);
    
    
    //old student
    char** enrolled_course = student->get_enrolled_courses();
    int index_of_course = search_course_index(student,course_name);
    if (index_of_course == student->get_num_enrolled_course()-1){
        
        delete [] enrolled_course[index_of_course];
        enrolled_course[index_of_course] = nullptr;
    }
    else{
        char* new_course = new char[strlen(enrolled_course[student->get_num_enrolled_course()-1])+1];
        strcpy(new_course,enrolled_course[student->get_num_enrolled_course()-1]);
        delete [] enrolled_course[index_of_course];
        enrolled_course[index_of_course] = new_course;
        

        delete [] enrolled_course[student->get_num_enrolled_course()-1];
        enrolled_course[student->get_num_enrolled_course()-1] = nullptr;    
    }
    
    student->set_num_enrolled_course(student->get_num_enrolled_course()-1);
    student->set_curr_credit(student->get_curr_credit()-course->get_num_credit());
    
    //check if anyone waiting of course waitlist
    Wait_List* wait_list = course->get_wait_list();
    Student_ListNode* student_temp = wait_list->get_head();
    
    if (student_temp){
        Student* newly_enrolled_student = student_database->get_student_by_id(student_temp->student_id);
        Swap_List* check_swap_list = newly_enrolled_student->get_swap_list();
        //interchange the new guy and old guy, do for the course
        int index_drop_student = search_student_id(student_id,course);
        int* student_enrolled = course->get_students_enrolled();
        student_enrolled[index_drop_student] = newly_enrolled_student->get_student_id();

        //if use swap/add
        Swap* check_swap_list_temp = check_swap_list->get_head();
        bool swap_flag = false;
        while (check_swap_list_temp){
            if (strcmp(check_swap_list_temp->target_course_name,course_name)==0){swap_flag = true;break;}
            check_swap_list_temp = check_swap_list_temp->next;
        }
    
        if (swap_flag){
            int original_course_credit = course_database->get_course_by_name(check_swap_list_temp->original_course_name)->get_num_credit();
            int target_course_credit = course_database->get_course_by_name(check_swap_list_temp->target_course_name)->get_num_credit();
            
            
            
            if(target_course_credit-original_course_credit>0){
                
                newly_enrolled_student->set_pending_credit(newly_enrolled_student->get_pending_credit()-(target_course_credit-original_course_credit));
            }
            newly_enrolled_student->set_curr_credit(newly_enrolled_student->get_curr_credit()+(target_course_credit));
            newly_enrolled_student->get_enrolled_courses()[newly_enrolled_student->get_num_enrolled_course()] = new char[strlen(course_name)+1];
            
            strcpy(newly_enrolled_student->get_enrolled_courses()[newly_enrolled_student->get_num_enrolled_course()],course_name);
            newly_enrolled_student->set_num_enrolled_course(newly_enrolled_student->get_num_enrolled_course()+1);
            


            drop(newly_enrolled_student->get_student_id(),check_swap_list_temp->original_course_name);
            check_swap_list->set_head(check_swap_list_temp->next);
            delete check_swap_list_temp;
            check_swap_list_temp = nullptr;
            
            
            
              
        }
        else{
            newly_enrolled_student->set_pending_credit(newly_enrolled_student->get_pending_credit()-course->get_num_credit());
            newly_enrolled_student->set_curr_credit(newly_enrolled_student->get_curr_credit()+course->get_num_credit());
            newly_enrolled_student->get_enrolled_courses()[newly_enrolled_student->get_num_enrolled_course()] = new char[strlen(course_name)+1];
            strcpy(newly_enrolled_student->get_enrolled_courses()[newly_enrolled_student->get_num_enrolled_course()],course_name);
            newly_enrolled_student->set_num_enrolled_course(newly_enrolled_student->get_num_enrolled_course()+1);
            
        }
        wait_list->set_head(student_temp->next);
        delete student_temp;
        student_temp = nullptr;

        
        
    }
    
    //course
    else{
        int* student_enrolled = course->get_students_enrolled();
        int index_of_student = search_student_id(student_id,course);
        if (index_of_student != course->get_size()-1){
            student_enrolled[index_of_student] = student_enrolled[course->get_size()-1];
            student_enrolled[course->get_size()-1] = 0;
            course->set_size(course->get_size()-1);
        }
        else{
            student_enrolled[course->get_size()-1] = 0;
            course->set_size(course->get_size()-1);
        }
    }
    // TODO
}

void System::add_course(const char* const name, const int num_credit, const int course_capacity) {
    this->course_database->create_entry(name, num_credit, course_capacity);
}

void System::print_info() const {
    this->course_database->print_all_course();
    this->student_database->print_all_students();
}

Course_Database* System::get_course_database() const {
    return course_database;
}

Student_Database* System::get_student_database() const {
    return student_database;
}

void System::set_course_database(Course_Database* const course_database) {
    this->course_database = course_database;
}

void System::set_student_database(Student_Database* const student_database) {
    this->student_database = student_database;
}
