#include <iostream>
#include "technician.h"
#include "computer.h"
#include "electronics.h"

const int MAX_NUM_TECHNICIAN = 10;

// TODO: initialize the static varibles of class Technician

int Technician::num_technician = 0;
Technician* Technician::technician_list[MAX_NUM_TECHNICIAN] {nullptr};


// TODO: Implement the constructor
Technician::Technician(std::string name, Diagnosis_Tool* diagnosis_tool): name(name), num_order_finished(0), diagnosis_tool(diagnosis_tool)
{
    technician_list[num_technician] = this;
    num_technician++;
}

Technician::~Technician(){
    delete diagnosis_tool;
}

CPU* Technician::acquire_CPU(CPU_Model model) const {
    return new CPU(model);
}

MEM* Technician::acquire_MEM(MEM_Model model) const {
    return new MEM(model);
}

// TODO: implement repair function
void Technician::repair(Computer* computer){
    if(!diagnosis_tool->diagnose(computer->cpu)){
        CPU_Model model = diagnosis_tool->get_CPU_Model(computer->cpu);
        computer->cpu->defect_count++;
        delete computer->cpu;
        computer->cpu = acquire_CPU(model);
        
    }

    if(!diagnosis_tool->diagnose(computer->mem)){
        MEM_Model model = diagnosis_tool->get_MEM_Model(computer->mem);
        computer->mem->defect_count++;
        delete computer->mem;
        computer->mem = acquire_MEM(model);
    }
    num_order_finished++;

}

void Technician::print_report(){
    std::cout << "----------------------" << std::endl;
    std::cout << "REPORT FOR TECHNICIANS" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout.width(20);
    std::cout << std::left << "NAME" << "ORDERS_COMPLETED" << std::endl;
    for(int i = 0; i < num_technician; ++i){
        std::cout.width(20);
        std::cout << std::left << technician_list[i]->name << technician_list[i]->num_order_finished << std::endl;
    }
}
