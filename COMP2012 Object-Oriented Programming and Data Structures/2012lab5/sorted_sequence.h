#ifndef __SORTED_SEQUENCE__
#define __SORTED_SEQUENCE__

#include <iostream>
#include <sstream>
#include <string>

template <typename T>
class SortedSequence{
  public:
    SortedSequence() : capacity_(0), size_(0), data_(nullptr) {}
    ~SortedSequence() { delete[] data_; }

    void add(const T &a) {  // Task 2 - To Do

      if(this->size_ + 1 > this->capacity_){
        if (this->data_ == nullptr){
          this->data_ = new T[1];
          this->capacity_ = 1;
          this->data_[0] = a;
          this->size_ = 1;
          
        }
        else{
          T* n = new T[2*this->capacity_];
          for (int i=0;i<this->size_;i++){
              n[i] = this->data_[i];
          }
          delete [] this->data_;
          this->data_ = nullptr;
          this->capacity_ = 2*this->capacity_;
          n[size_] = a;
          for (int i=this->size_-1;i>=0;i--){
              T temp = n[i+1];
              if (temp < n[i]){
                n[i+1] = n[i];
                n[i] = temp;
              }
          }
          this->size_++;
          this->data_ = n;  
          
        }
      }
      else{

        this->data_[size_] = a;
        for (int i = this->size_-1;i>=0;i--){
            T temp = data_[i+1];
            if (temp < data_[i]){
              data_[i+1] = data_[i];
              data_[i] = temp;
            }
        }
        this->size_++;
      }
    }
    std::string toString() const {
      std::stringstream ss;
      ss << "capacity: " << capacity_ << ", size: " << size_
        << ", data: " << std::endl;
      if (data_ == nullptr) {
        ss << "None";
      } else {
        for (int i = 0; i < size_; i++) {
          ss << data_[i] << " ";
        }
      }
      return ss.str();
    }

  private:
    int capacity_;
    int size_;
    T *data_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const SortedSequence<T>& t) {
  os << t.toString();
  return os;
}

#endif 