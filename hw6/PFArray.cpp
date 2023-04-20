
#include <iostream>
#include <memory>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class PFArray {
public:
  // Constructors
  PFArray();
  PFArray(T capacityValue);
  int getCapacity()const{return *capacity;};// get function
  PFArray(const PFArray& obj);//copy constructer
  ~PFArray();//destructer
  class iterator {
  public:
    iterator(T* p) : ptr(p) {} // Constructor
    iterator& operator++() { ++ptr; return *this; } // Prefix increment 
    iterator operator++(int) { iterator temp(*this); operator++(); return temp; } // Postfix increment 
    bool operator==(const iterator& rigthside) { return ptr == rigthside.ptr; } // Equality 
    bool operator!=(const iterator& rightside) { return ptr != rightside.ptr; } // Inequality 
    iterator& operator=(const iterator& otherObject) {//= operator
      ptr = otherObject.ptr;
      return *this;
    }
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }  
  private:
    T* ptr;
  };
  // Iterator functions
  iterator begin() { return iterator(data.get()); }
  iterator end() { return iterator(data.get() + getCapacity()); }
  const iterator cbegin()const{ return iterator(data.get()); };
  const iterator cend() const{ return iterator(data.get() + getCapacity()); };
PFArray &operator=(const PFArray<T> &other);//= operator overloading 
  bool empty() const;// control array empty or not
  int size() const;// return size
  void clear();//clear all erray
  void addElement(T &n);//adding element in array
  void print();
  void erase(iterator &position);// erase element on array
  PFArray(PFArray&& other) : data(move(other.data)), capacity(move(other.capacity)) {//move function
  other.data = nullptr;
  other.capacity = nullptr;
}

private:
  shared_ptr<T> data;
  shared_ptr<T> capacity;
};
template <typename T>
PFArray<T>::PFArray(){//constructer
    capacity.reset(new T(1));
    data.reset(new T[getCapacity()]); 
    for (int i = 0; i < getCapacity(); i++)
      data.get()[i]=0;
};
template <typename T>//constructer
PFArray<T>::PFArray(T capacityValue){
    capacity.reset(new T(capacityValue));
    data.reset(new T[getCapacity()]);
    for (int i = 0; i < getCapacity(); i++)
      data.get()[i]=0;
  };
template <typename T>// delete memory
PFArray<T>::~PFArray(){
    capacity.reset();
    data.reset();
  };
template <typename T>
PFArray<T>& PFArray<T>::operator=(const PFArray<T> &otherObject)
{
   if (this != &otherObject)
   {
      shared_ptr<T> newData(new T(otherObject.size()));//crate new memory
      for (int i = 0; i < otherObject.size(); i++)
        newData.get()[i] = otherObject.data.get()[i];//values in array are transferred to new array
      data = move(newData);//using move
      capacity = otherObject.capacity;
   }
   return *this;
}

template <class T>
PFArray<T>::PFArray(const PFArray& obj){//copy constructer
  capacity.reset(new T(obj.getCapacity( )));
  data.reset(new T[getCapacity()]);
  for (int i = 0; i < getCapacity(); i++)
    data.get()[i] = obj.data.get()[i];
}
template <class T>
bool PFArray<T>::empty()const{//if capacity 0 return true if not capacity return false
  try {
    if (capacity == 0) {
      return true;
    }
    return false;
  } catch (const std::exception& e) {
    cout << "Empty error! " << e.what() << endl;
    return false;
  }
}
template <class T>//return capacity for size
int PFArray<T>::size()const{
  return *capacity;
} 
template <class T>
void PFArray<T>::clear(){// all thing deleting
try{
  data.reset();
  data=nullptr;
  capacity.reset(new T(0));
}catch (const std::exception& e) {
    cout << "clear error! " << e.what() << endl;
  }
}
template <class T>
void PFArray<T>::addElement(T& n){//adding element like push_back
  static int count=0;
    data.get()[count]=n;
  shared_ptr<T[]> newData(new T[count+1]);//A new array is created with 1 more capacity than the array
  for(int i=0;i<count+1;i++){
    newData.get()[i]=data.get()[i];//values from old array are transferred
  }
  data.reset(new T[count+1]); //the old array reopens as one more
    for (int i = 0; i < count+1; i++)
      data.get()[i]=newData.get()[i];//values from old array are transferred
  newData.reset();// new data deleting
  capacity.reset(new T(count+1));////the old array capacity reopens as one more
  count++;
}

template <class T>
void PFArray<T>::print(){// printing using iterator
  cout << "Elements of array: ";
  for (iterator it = begin(); it != end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

template <class T>
void PFArray<T>::erase(iterator &position) {
try{
  shared_ptr<T[]> newData(new T[getCapacity() - 1]);//new arrays open
  int a=0;
  for(iterator it = begin();it != position;++it){//transferred from the old array to the new array until it reaches the position
    newData.get()[a] = *it;
    a++;
  }
  position++;//desired position is skipped
  for (iterator it = position;it != end();++it) {//retransmitted until finished
  newData.get()[a] = *it;
  a++;
  }
  capacity.reset(new T(getCapacity() - 1));// capacity is changed to 1 minus
  data.reset();
  data.reset(new T[getCapacity()]);//old array reopens with new capacity
  for (int i = 0; i < getCapacity(); i++){
    data.get()[i] = newData.get()[i];//transfered new data 
  }
  newData.reset();//delete new data
  print();
  cout << "Array size:" << size() << endl;
} catch (const std::exception& e) {
    cout << "erase error: " << e.what() << endl;
  }
}





