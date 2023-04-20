#include "PFArray.cpp"
#include <algorithm>


int main(){
    int i;
    int cap=5;
    PFArray<int> obj(cap);
    PFArray<int> cpyObj(obj);
    int arr[] = {8,16,9,4,7};
    for(i=0;i<5;i++)
        obj.addElement(arr[i]);//adding element
    obj.print();//print all element
    cout << "Array size: " << obj.size() << endl;//printing size
    cout << "Deleting 3 elements in array!" << endl;
    int value[3] = {7,16,8};//numbers to be deleted
for (int i = 0; i < 3; i++) {//erasing process
    auto it = obj.begin();
    auto iter = obj.end();
    while (it != iter) {
        if (*it == value[i]) {
            obj.erase(it);
        } else {
            ++it;//if it finds the function, if it doesn't find it goes one
        }
    }
}
    cout << "The array is cleared !!" << endl;
    obj.clear();
    cout << obj.empty() << endl; 
    if(obj.empty()==0)
        cout << "Array is empty! " << endl;
    else
        cout << "Array is not empty!" << endl;
    obj.print();
    cout <<"------------------------- for char values------------------------------------------" <<endl;
    PFArray<char> obj1(cap);
    char charArr[] = {'O','S','M','A','N'};
    PFArray<char> testArr;
    testArr=std::move(obj1);
    for(i=0;i<5;i++)
        obj1.addElement(charArr[i]);
    obj1.print();
    cout << "Array size: " << obj1.size() << endl;
    cout << "Deleting 3 elements in array!" << endl;
    char charValue[3] = {'S','M','N'};
for (int i = 0; i < 3; i++) {
    auto it = obj1.begin();
    auto iter = obj1.end();
    while (it != iter) {
        if (*it == charValue[i]) {
            obj1.erase(it);
        } else {
            ++it;
        }
    }
}
    cout << "The array is cleared !!" << endl;
    obj1.clear();
    cout << obj1.empty() << endl; 
    if(obj1.empty()==0)
        cout << "Array is empty! " << endl;
    else
        cout << "Array is not empty!" << endl;
    obj1.print();
    return 0;
}