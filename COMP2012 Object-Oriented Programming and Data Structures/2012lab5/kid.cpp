#include "kid.h"

#include <cstring>

Kid::Kid() : height_(0), gender_(Gender::Female), name_(nullptr), weight_(0) {}

Kid::Kid(int height, Gender gender, const char* name, int weight)
    : height_(height), gender_(gender), name_(nullptr), weight_(weight) {
  name_ = new char[strlen(name) + 1];
  strcpy(name_, name);
}

Kid::Kid(const Kid& other)
    : Kid(other.height(), other.gender(), other.name(), other.weight()) {}

Kid::~Kid() { delete[] name_; }

int Kid::height() const { return height_; }
Gender Kid::gender() const { return gender_; }
const char* Kid::name() const { return name_; }
int Kid::weight() const {return weight_;}

bool Kid::operator<(const Kid& other) const {  // Task 1 - To Do
  if (this->height_ < other.height()){
    return true;
  }
  else if (this->height_ > other.height()){
    return false;
  }
  else{
    if (this->gender_ == 0 && other.gender() == 1){return true;}
    else if (this->gender_ == 1 && other.gender() == 0){return false;}
    else{
      if (strcmp(this->name_,other.name())!=0){
        return (strcmp(this->name_,other.name())<0) ? true:false;
      }
      else{
        return (this->weight_>other.weight()) ? true:false;
      }
    }
  }
}

Kid& Kid::operator=(const Kid& other) {
  height_ = other.height();
  gender_ = other.gender();
  delete[] name_;
  name_ = new char[strlen(other.name()) + 1];
  strcpy(name_, other.name());
  weight_ = other.weight();
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Kid& k) {
  os << "(Height:" << k.height();
  os << ", Gender:" << (k.gender() == Female ? "Female" : "Male");
  os << ", Name:" << k.name();
  os << ", weight:" << k.weight() << ")";
  return os;
}
