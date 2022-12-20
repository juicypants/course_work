#include <iostream>
#include <cstring>
#include "swap_list.h"

using namespace std;

Swap::Swap(const char* const original_course_name, const char* const target_course_name, Swap* const next) {
    this->original_course_name = new char[strlen(original_course_name)+1];
    strcpy(this->original_course_name,original_course_name);
    this->target_course_name = new char[strlen(target_course_name)+1];
    strcpy(this->target_course_name,target_course_name);
    this->next = next;
    // TODO
}

Swap::~Swap() {
    delete [] original_course_name;
    original_course_name = nullptr;
    delete [] target_course_name;
    target_course_name = nullptr;
    // TODO
}

Swap_List::Swap_List() {
    this->head = nullptr;
    // TODO
}

Swap_List::Swap_List(const Swap_List& swap_list) {
    Swap* t = swap_list.head;
    if(t){
        this->head = new Swap(t->original_course_name,t->target_course_name,nullptr);
        Swap* c = this->head;
        t = t->next;
        while(t){
            Swap* temp = new Swap(t->original_course_name,t->target_course_name,nullptr);
            c->next = temp;
            c = c->next;
            t = t->next;
        }
    }
    else{
        this->head = nullptr;
    }

    
    
    
    // TODO
}

Swap_List::~Swap_List() {
    Swap* temp = this->head;
    Swap* temp_next = nullptr;
    while (temp){
        temp_next = temp->next;
        delete temp;
        temp = nullptr;
        temp = temp_next;
    }
    // TODO
}

void Swap_List::print_list() const {
    Swap* temp = this->head;
    int index = 0;
    while(temp) {
        cout << "Swap: " << index++ << endl;
        cout << "Original Course: " << temp->original_course_name << endl;
        cout << "Target Course: " << temp->target_course_name << endl;
        temp = temp->next;
    }
}

Swap* Swap_List::get_head() const {
    return head;
}

void Swap_List::set_head(Swap* const head) {
    this->head = head;
}