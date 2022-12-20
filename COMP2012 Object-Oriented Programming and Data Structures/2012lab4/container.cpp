#include "container.h"
#include <iostream>

void Container::addObject(Object *object)   //Task 1&3
{   
    if(object->getSize().x+ object->getPosition().x <= this->getSize().x &&
        object->getSize().y+ object->getPosition().y <= this->getSize().y){
        if(_num_object < MAX_OBJECT_NUM){
            _objects[_num_object] = object;
            _objects[_num_object]->setParent(this);
            _num_object++;
        }
    }
    else{
        std::cout<< "The object " << object->getName() << " is too large and cannot be added to "<< this->getName() <<endl;
    }
}

void Container::display() const //Task 1
{   
    std::cout << "\nContainer";
    this->displayBasic();
    std::cout <<"\n\t\t";
    if (_num_object>0)
        std::cout<<"#objects: "<<_num_object;

    for (int i=0;i<_num_object;i++){
        _objects[i]->display();
    }
}

Container::Container() 
{
    for (int i = 0; i < MAX_OBJECT_NUM; i++)
        _objects[i] = nullptr;

    _num_object = 0;
}

Container::~Container()  //Task 1
{
    std::cout<<"\nDestructing Container "<< getName();
    for (int i=0;i<_num_object;i++){
        delete _objects[i];
        _objects[i] = nullptr;
    }
    
}