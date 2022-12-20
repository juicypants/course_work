#include "hash_table.h"
#include <cmath>
#include <iostream>

int HashTable::hashFunction(const std::string &name, int base, int table_size) {
  int res = 0;
  for (unsigned int i = 0; i < name.size(); i++) {
    res = (base*res + name[i] - 'a') % table_size;
  }
  return res;
}

int HashTable::getNextHashTableSize(int now_hash_table_size) {
  int res = now_hash_table_size*2;
  bool is_prime = false;
  while (true) {
    is_prime = true;
    int sq = sqrt(res);
    for (int i = 2; i <= sq; i++) {
      if (res % i == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
      break;
    res++;
  }
  return res;
}

HashTable::HashTable(int init_size, int maximum_probe_num,
                     ProbeMode probe_mode)  {  // Task 1
      this->hash_table_size_ = init_size;
      this->maximum_probe_num_ = maximum_probe_num;
      this->probe_mode_ = probe_mode;              
      
      this->base_1_ = 37;
      this->base_2_ = 41;
      this->table_ = new HashCell[init_size];
      for (int i=0;i<init_size;i++){
        table_[i].state = HashCellState::Empty;
        table_[i].student = nullptr;
      }

        
        if(probe_mode == ProbeMode::Linear){
        
          this->probe_func_ = [](int hash_value1, int hash_value2, int num_probe, int hash_table_size) {
            
            return (hash_value1+num_probe)%hash_table_size;
          };
        }
        else if(probe_mode == ProbeMode::Quadratic){

          this->probe_func_ = [](int hash_value1, int hash_value2, int num_probe, int hash_table_size) -> int {
            int p = (hash_value1+(num_probe)*(num_probe))%hash_table_size;
            std::cout << "Probing for the position: " << p << std::endl;
            return p;
          };
        }
        else if(probe_mode == ProbeMode::DoubleHash){
        
          this->probe_func_ = [](int hash_value1, int hash_value2, int num_probe, int hash_table_size) -> int {
            int p = (hash_value1+num_probe*hash_value2)%hash_table_size;
            std::cout << "Probing for the position: " << p << std::endl;
            return p;
          };
         
        }
      
}

HashTable::~HashTable() {  // Task 1
  
  delete [] table_;
}

bool HashTable::add(const std::string &name, int score) {  // Task 2 & 5
  
  int hash_value1 = hashFunction(name,base_1_,hash_table_size_);
  int hash_value2 = 0;
  if(this->probe_mode_ == ProbeMode::DoubleHash){
    hash_value2 = hashFunction(name,base_2_,hash_table_size_);
    if (hash_value2 == 0){
      hash_value2 = 1;
    }
  }
  int position = 0;
  for (int i=0;i<maximum_probe_num_;i++){
    position = probe_func_(hash_value1,hash_value2,i,hash_table_size_);
    if(table_[position].state == HashCellState::Active && !name.compare(table_[position].student->name())){
      return false;
    }
    else if (table_[position].state == HashCellState::Empty || table_[position].state == HashCellState::Deleted){
      table_[position].state = HashCellState::Active;
      table_[position].student = new Student(name,score);
      return true;
      
    }
  }
  
  reHashUntilSuccess();
  add(name,score);
  return true;
}

int HashTable::search(const std::string &name) const {  // Task 3
  int hash_value1 = hashFunction(name,base_1_,hash_table_size_);
  int hash_value2 = 0;
  if(this->probe_mode_ == ProbeMode::DoubleHash){
    hash_value2 = hashFunction(name,base_2_,hash_table_size_);
    if (hash_value2 == 0){
      hash_value2 = 1;
    }
  }
  int position = 0;
  for (int i=0;i<hash_table_size_;i++){
    position = probe_func_(hash_value1,hash_value2,i,hash_table_size_);
    if (table_[position].state == HashCellState::Deleted){
      continue;
    }
    else if (table_[position].state == HashCellState::Active){
      if(!name.compare(table_[position].student->name())){
        return table_[position].student->score();
      }
    }
    else if(table_[position].state == HashCellState::Empty){
      return -1;
    }
    
  }
  return -1;
}

bool HashTable::remove(const std::string &name) {  // Task 4
  int hash_value1 = hashFunction(name,base_1_,hash_table_size_);
  int hash_value2 = 0;
  if(this->probe_mode_ == ProbeMode::DoubleHash){
    hash_value2 = hashFunction(name,base_2_,hash_table_size_);
    if (hash_value2 == 0){
      hash_value2 = 1;
    }
  }
  int position = 0;
  for (int i=0;i<hash_table_size_;i++){
    position = probe_func_(hash_value1,hash_value2,i,hash_table_size_);
    if (table_[position].state == HashCellState::Deleted){
      continue;
    }

    if (table_[position].state == HashCellState::Active){
      if(!name.compare(table_[position].student->name())){
        delete table_[position].student;
        table_[position].student = nullptr;
        table_[position].state = HashCellState::Deleted;
        return true;
      }
    }

    else if(table_[position].state == HashCellState::Empty){
      return false;
    }

    

  }
  return false;
}

void HashTable::reHashUntilSuccess() {
  int next_hash_table_size = getNextHashTableSize(hash_table_size_);
  while (true) {
    
    if (reHash(next_hash_table_size)) {
      
      return;
    }
    
    next_hash_table_size = getNextHashTableSize(next_hash_table_size);
  }
}

bool HashTable::reHash(int rehash_table_size) {  // Task 5
  
  HashCell* temp = new HashCell[rehash_table_size];
  for (int i=0;i<rehash_table_size;i++){
    temp[i].state = HashCellState::Empty;
    temp[i].student = nullptr;
  }
  
  for(int i=0;i<hash_table_size_;i++){
    
    if(table_[i].state == HashCellState::Active){
      
      bool flag = false;
      int hash_value1 = hashFunction(table_[i].student->name(),base_1_,rehash_table_size);
      int hash_value2 = 0;
      if(this->probe_mode_ == ProbeMode::DoubleHash){
        hash_value2 = hashFunction(table_[i].student->name(),base_2_,rehash_table_size);
        if (hash_value2 == 0){
          hash_value2 = 1;
        }
      }
      int position = 0;
      for (int j=0;j<maximum_probe_num_;j++){
        position = probe_func_(hash_value1,hash_value2,j,rehash_table_size);
        
        if(temp[position].state == HashCellState::Active){
          continue;
        }
        else if (temp[position].state == HashCellState::Empty){
          
          temp[position].state = HashCellState::Active;
          
          temp[position].student = new Student(*table_[i].student);
          
          flag = true;
          break;
        }
      }
      if (flag == false){
        
        delete [] temp;
        return false;
      }
    } 
  }
  
  
  
  
  
  delete [] table_;
  table_ = nullptr;
  table_ = temp;
  
  hash_table_size_ = rehash_table_size;

  return true;





}

void HashTable::print() const {
  std::cout << "hash_table_size:" << hash_table_size_ << std::endl;
  for (int i = 0; i < hash_table_size_; i++) {
    std::cout << i << ": state = ";
    if (table_[i].state == HashCellState::Empty) {
      std::cout << "Empty" << std::endl;
    } 
    else if (table_[i].state == HashCellState::Deleted) {
      std::cout << "Deleted" << std::endl;
    } 
    else if (table_[i].state == HashCellState::Active) {
      std::cout << "Active ";
      std::cout << "Student = (" << table_[i].student->name() << ", "
                << table_[i].student->score() << ")" << std::endl;
    }
  }
}

