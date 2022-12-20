#include <iostream>
#include "wait_list.h"

using namespace std;

Student_ListNode::Student_ListNode(const int student_id, Student_ListNode* const next) {
    this->student_id = student_id;
    this->next = next;
    // TODO
}

Wait_List::Wait_List() {

    this->head = nullptr;
    this->end = nullptr;
    // TODO

}

Wait_List::Wait_List(const Wait_List& wait_list) {
    Student_ListNode* t = wait_list.head;
    if(t){
        this->head = new Student_ListNode(t->student_id,nullptr);
        Student_ListNode* c = this->head;
        t = t->next;
        while(t){
            Student_ListNode* temp = new Student_ListNode(t->student_id,nullptr);
            c->next = temp;
            c = c->next;
            t = t->next;
        }
        this->end = c;
    }
    else{
        this->head = nullptr;
    }
    
    // TODO
}

Wait_List::~Wait_List() {
    Student_ListNode* temp = this->head;
    Student_ListNode* temp_next = nullptr;
    while(temp){
        temp_next = temp->next;
        delete temp;
        temp = nullptr;
        temp = temp_next;
    }
    // TODO
}

void Wait_List::print_list() const {

    Student_ListNode* temp = this->head;
    int index = 0;
    while(temp) {
        cout << "Waitlist Number: " << index++ << endl;
        cout << temp->student_id << endl;
        temp = temp->next;
    }

}

Student_ListNode* Wait_List::get_head() const {
    return head;
}

Student_ListNode* Wait_List::get_end() const {
    return end;
}

void Wait_List::set_head(Student_ListNode* const head) {
    this->head = head;
}

void Wait_List::set_end(Student_ListNode* const end) {
    this->end = end;
}