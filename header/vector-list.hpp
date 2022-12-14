#pragma once
#include <vector>

template <typename Type> class VectorList{
private:
  std::vector<Type> items;
  int selected = -1;
public:
  // return_type (* identifier)(parameters...)
  void (*onSelect)(Type *item, int index);
  void (*onUnselect)(Type *item, int index);
  int length(){
    return items.size();
  }
  void addItem(Type item, int index = -1){
    if(index < 0)
      items.insert(items.end() - index - 1, item);
    else
      items.insert(items.begin() + index, item);
  }
  void removeItem(int index){
    items.erase(items.begin() + index);
  }
  Type * getItem(int index){
    if(index >= 0 && index < items.size())
      return &items[index];
    return nullptr;
  }
  Type * operator [](int index){
    if(index >= 0 && index < items.size())
      return &items[index];
    return nullptr;
  }
  auto begin(){
    return items.begin();
  }
  auto end(){
    return items.end();
  }
};