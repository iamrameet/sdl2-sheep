#pragma once

#define let auto
#define function auto

function calc(){
  let a = 10, b = 20;
  return a + b;
}

template<typename Type> class Array{
  Type array[];
public:
  struct length{
    private: int value;
    public: length& operator =(int value){
      this->value = value;
      return *this;
    }
  } length;
  Array(unsigned int size): array(Type[size]){}
  void push(Type element){
    array[length] = element;
  }
};

Array<int> array(10);