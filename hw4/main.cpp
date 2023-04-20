#include "DayofYearSet.h"
//using namespace OSMAN;
int main()
{
	// Objects sets
	DayofYearSet obj1,obj2,obj3, obj4,obj5, obj6, obj7;
	
    DayofYearSet::DayofYear k(14, 6);
    DayofYearSet::DayofYear l(9, 6);
    DayofYearSet::DayofYear m(7, 11);
 	cout << "Object 1:" << endl;//creating object
    obj1=obj1+k;//adding element
    obj1=obj1+l;
    obj1=obj1+m;
    cout << obj1;
    cout << "First obj size is " << obj1.size()<< "."<< endl;//find array size
    obj1.testRemove();//delete element on funciton
    cout << "The remained set: " << endl;//remaining set
    cout << obj1;	//<< operator is tested
    //I create same object to test == or != overloading 
    cout << "Object 2:" << endl;
    obj2=obj2+k;
    obj2=obj2+l;
    obj2=obj2+m;
    cout << obj2;
    cout << "Second obj size is " << obj2.size()<< "."<< endl;
    obj2.testRemove();
    cout << "The remained set: " << endl;
    cout << obj2;	//<< operator is tested
    cout << "Operator == test is running!" << endl;
    if(obj1==obj2){// testing == overloading
        cout <<"object1: "<< obj1 << endl;
        cout <<"object2: "<< obj2 << endl; 
        cout << "These classes have same values"<< endl;
    }
    else{
        cout <<"object1: "<< obj1 << endl;
        cout <<"object2: "<< obj2 << endl; 
        cout << "These classes have different values"<<endl;
    }
    cout << "Operator =! test is running!" << endl;
    if(obj1!=obj2){// testing != overloading
        cout <<"object1: "<< obj1 << endl;
        cout <<"object2: "<< obj2 << endl; 
        cout << "These classes have different values"<< endl;
    }
    else{
        cout <<"object1: "<< obj1 << endl;
        cout <<"object2: "<< obj2 << endl; 
        cout << "These classes have same values"<<endl;
    }
    DayofYearSet::DayofYear a(1, 12);
    DayofYearSet::DayofYear b(24, 10);
    cout << "New object2 sets: "<< endl;
    obj2=obj2+a;//adding new elements
    obj2=obj2+b;
    cout << obj2;
    cout << "union of two sets Object 3:" << endl;
    obj3=obj1+obj2;// merge two sets and testing + overloading
    cout << obj3;
    cout << "Object 3:" << endl; 
    cout << obj3;
    cout << "Object 1:" << endl;
    cout << obj1;
    cout << "Object 3 - Object 1"<< endl;// find diffrence set and testing - overloading
    obj4=obj3-obj1;
    cout << "Result of removing:" << endl;
    cout << obj4;// result
    DayofYearSet::DayofYear x(3, 9);
    DayofYearSet::DayofYear y(9, 6);
    DayofYearSet::DayofYear z(23, 10);
    obj3=obj3+x;//adding new elements
    obj4=obj4+y;
    obj3=obj3+z;
    cout << "New object3 set: "<< endl;
    cout << obj3;
    cout << "New object4 set: "<< endl;
    cout << obj4;
    obj5 = obj4^obj3;//intersections of two sets and testing ^overloading
    cout << "Result of intersection set:" << endl;
    cout << obj5;
    cout << "union set of all classes: " << endl;
    obj6 = obj3+obj4;//Union of all onjects
    cout << obj6;
    cout << "---------------------------------------------------------"<< endl;
    obj7=!obj6;//subtract union set from universal set
    cout << "Given position is second index.\n Second index array: ";
    DayofYearSet::DayofYear s(obj6[2]); //[] operator overloading
    cout << s.getDay() << "," << s.getMonth() << endl;
    cout << endl;
    return 0;
}