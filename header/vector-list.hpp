#pragma once
#include <vector>

template <typename Type> class VectorList{
private:
  std::vector<Type> items;
  int selected = -1;
public:
  // return_type (* identifier)(parameters...)
  void (*onSelect)(Type *item);
  void (*onUnselect)(Type *item);
  int length(){
    return items.size();
  }
  void addItem(Type item){
    items.push_back(item);
  }
  void removeItem(int index){
    items.erase(items.begin() + index);
  }
  Type * getItem(int index){
    if(index >= 0 && index < items.size())
      return &items[index];
    return nullptr;
  }
  Type * getSelectedItem(){
    if(selected >= 0 && selected < items.size())
      return &items[selected];
    return nullptr;
  }
  void selectItem(int index){
    onUnselect(&items[selected]);
    // if(index < 0)
    //   index = items.size() - index - 1;
    selected = index % items.size();
    if(selected <= items.size())
      onSelect(&items[selected]);
  }
  void selectNextItem(){
    onUnselect(&items[selected]);
    selected = (selected + 1) % items.size();
    onSelect(&items[selected]);
  }
  void selectPrevItem(){
    onUnselect(&items[selected]);
    selected--;
    if(selected < 0)
      selected = items.size() - 1;
    onSelect(&items[selected]);
  }
  void clearSelection(){
    onUnselect(&items[selected]);
    selected = -1;
  }
  // Type * operator [](int index){
  //   if(index >= 0 && index < items.size())
  //     return &items[index];
  //   return nullptr;
  // }
  auto begin(){
    return items.begin();
  }
  auto end(){
    return items.end();
  }
};