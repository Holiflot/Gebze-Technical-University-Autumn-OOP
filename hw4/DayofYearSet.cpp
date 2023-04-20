#include "DayofYearSet.h"

//using namespace OSMAN;

DayofYearSet::DayofYearSet(list<DayofYear> &l)
{
	sets = new DayofYear[l.size()+1];//make enough space
	list<DayofYear>::iterator it;// we need to use iterator for lists
	int i=0;
	for(it = l.begin(); it != l.end(); ++it)
    {
    	sets[i].controlDate(it->getDay(), it->getMonth());
		i++;
    }
}

DayofYearSet::DayofYearSet() 
{ 
	sets = new DayofYear[1];//if it is emyty
	if (sets == NULL)
	{
		cerr << "No available memory!\n";
		exit(1);
	}
}


DayofYearSet::DayofYear::DayofYear(int d, int m){
    day=d;
    month=m;
}

DayofYearSet::DayofYear::DayofYear(int d){
    day = d;
    month=1;
}

DayofYearSet::DayofYear::DayofYear(){
    day=1;
    month=1;
}

void DayofYearSet::DayofYear::controlDate(int d, int m)
{
	if ((d < 1) || (d > 31) || (m < 1) || (m > 12))//checks the accuracy of the days 
	{
		cout << "There is no such day!" << endl;
		exit(1);
	}
	else
	{
		day = d;
		month = m;
	}
}

DayofYearSet DayofYearSet::operator+(DayofYearSet::DayofYear &date)//adding elements
{
    int i;
    list<DayofYear> dates;

    for (i = 0; i < numberOfElement; i++)
        dates.push_back(sets[i]);
	delete [] sets;
    sets = new DayofYear[numberOfElement + 1];//A new list is created and added, then deleted and a new one is created by increasing the size.
	list<DayofYear>::iterator it;
	int a=0;
	for(it = dates.begin(); it != dates.end(); ++it)//adding elemets in new set
    {
        sets[a] = *it;
		a++;
    }
    sets[numberOfElement].controlDate(date.getDay(),date.getMonth());
    
    numberOfElement++;
    return *this;
};

void DayofYearSet::remove(int position)//delete element from desired location
{
    int i;
    list<DayofYear> dates;
    for (i = 0; i < numberOfElement; ++i)
        dates.push_back(sets[i]);
    delete [] sets;
    sets = new DayofYear[numberOfElement];//A new list is created and added, then deleted and a new one is created
	list<DayofYear>::iterator it;
	int a=0;
	list<DayofYear>::iterator ite=dates.begin();
    if(position!=0){ //I divided the head into 3 as the end and the middle and checked it.
        advance(ite,position);
        for(it = dates.begin(); it != ite; ++it)
        {
            sets[a] = *it;
            a++;
        }
        for (it = ite;it != dates.end(); ++it)
        {
            sets[a] = *it;
            a++;
        }
    }
    else if(position==numberOfElement-1){
        advance(ite,numberOfElement-2);
        for(it = dates.begin(); it != ite; ++it)
        {
            sets[a] = *it;
            a++;
        }
    }
    else{
        advance(ite,position+1);
        for(it = ite; it != dates.end(); ++it)
    {
        sets[a] = *it;
		a++;
    }
    }
    --numberOfElement;
    cout << "The date in position " << position <<" ahas been deleted from the set" << endl;
    cout << sets[position].getDay()<<','<< sets[position].getMonth() << endl;
    cout << "There are " << numberOfElement << " elements in set now." << endl;
};

void DayofYearSet::testRemove()//remove dates for object1 and object 2
{
	cout << "Removed dates:" << endl;  
 	remove(0);
 	remove(1);
}
ostream & operator <<(ostream & out, const DayofYearSet &obj)// << operator overloading
{
	for(int i=0; i<obj.getNumofElements(); ++i)
		 out << obj.sets[i].getDay() << "," << obj.sets[i].getMonth() << endl;
	return out;
}
bool DayofYearSet:: operator==(const DayofYearSet &obj) const{//== operator overloading
    int count = 0;
    if(numberOfElement != obj.getNumofElements())//Two sets with unequal number of elements cannot be equal.
        return false;
    for(int i=0; i<obj.getNumofElements(); ++i){
        if(sets[i].getDay()==obj.sets[i].getDay() && sets[i].getMonth() == obj.sets[i].getMonth())//looks at the number of equals and if they are equal to the number of elements then these two sets are equal
            count ++;
    }
    if(count == obj.getNumofElements()){
        return true;
    }
	return false;
}
bool DayofYearSet:: operator!=(const DayofYearSet &obj) const{//!= operator overloading
    int count = 0;
    if(numberOfElement != obj.getNumofElements())
        return false;
    for(int i=0; i<obj.getNumofElements(); ++i){
        if(sets[i].getDay()!=obj.sets[i].getDay() && sets[i].getMonth() != obj.sets[i].getMonth())
            count ++;
    }
    if(count != obj.getNumofElements()){
        return false;
    }
	return true;
}
DayofYearSet DayofYearSet::operator+(const DayofYearSet &obj) const{
    DayofYearSet unionSet;
    for(int i=0; i<numberOfElement; ++i){//Adds two sets with or without the same elements
        for(int j=0; j<obj.getNumofElements(); ++j){
            if(sets[i].getDay()!=obj.sets[j].getDay() && sets[i].getMonth() != obj.sets[j].getMonth()){
                DayofYearSet::DayofYear a(obj.sets[j].getDay(),obj.sets[j].getMonth());
                unionSet=unionSet+a;
            }
        }
        DayofYearSet::DayofYear b(sets[i].getDay(),sets[i].getMonth());
        unionSet=unionSet+b;
    }
    for(int k=0; k<unionSet.getNumofElements(); k++){//deletes the same elements
        for(int l=1; l<unionSet.getNumofElements(); l++){
            if(k!=l && unionSet.sets[k].getDay()==unionSet.sets[l].getDay() && unionSet.sets[k].getMonth()==unionSet.sets[l].getMonth())
                unionSet.remove(k);
        }
    }
    return unionSet;
}
DayofYearSet DayofYearSet::operator-(const DayofYearSet &obj) const{
    DayofYearSet unionSet;
    int i;
    for (i=0; i < numberOfElement; ++i)
	{
		DayofYearSet::DayofYear a(sets[i].getDay(), sets[i].getMonth());
		unionSet=unionSet+a;//transferred to empty object
	}
    for(i=0; i<numberOfElement; ++i){
        for(int j=0; j<obj.getNumofElements(); ++j){//two sets have equal elements and are deleted
            if(sets[i].getDay()==obj.sets[j].getDay() && sets[i].getMonth() == obj.sets[j].getMonth()){
                unionSet.remove(i);
            }
        }
    }
    return unionSet;//the rest is returned
}
DayofYearSet DayofYearSet::operator^(const DayofYearSet &obj) const{
    DayofYearSet intersectionSet;
    int i;
    for(i=0; i<numberOfElement; ++i){
        for(int j=0; j<obj.getNumofElements(); ++j){
            if(sets[i].getDay()==obj.sets[j].getDay() && sets[i].getMonth() == obj.sets[j].getMonth()){//equals in two sets are returned
                DayofYearSet::DayofYear a(obj.sets[j].getDay(),obj.sets[j].getMonth());
                intersectionSet=intersectionSet+a;
            }
        }
    }
    return intersectionSet;
}
DayofYearSet DayofYearSet::operator!(){
    ofstream outStream;
	outStream.open("complementSet.txt");//open file
    DayofYearSet complementSet;
    for(int j=1;j<=12;j++){
        if(j==4 || j==6 || j==9 || j==11){//Organized by 365 days
        for(int i=1;i<=30;i++){
            if((i!=sets[0].getDay() && j!=sets[0].getMonth()) && (i!=sets[1].getDay() && j!=sets[1].getMonth()) && (i!=sets[2].getDay() && j!=sets[2].getMonth()) && (i!=sets[3].getDay() && j!=sets[3].getMonth()) && (i!=sets[4].getDay() && j!=sets[4].getMonth()) && (i!=sets[5].getDay() && j!=sets[5].getMonth())){
                outStream << i << "," << j << endl; //writing file
                DayofYearSet::DayofYear a(i,j);
                complementSet=complementSet+a;
            }
                }
        }
        else if(j==2){
            for(int i=1;i<=28;i++){
                    if((i!=sets[0].getDay() && j!=sets[0].getMonth()) && (i!=sets[1].getDay() && j!=sets[1].getMonth()) && (i!=sets[2].getDay() && j!=sets[2].getMonth()) && (i!=sets[3].getDay() && j!=sets[3].getMonth()) && (i!=sets[4].getDay() && j!=sets[4].getMonth()) && (i!=sets[5].getDay() && j!=sets[5].getMonth())){
                        outStream << i << "," << j << endl;
                        DayofYearSet::DayofYear a(i,j);
                        complementSet=complementSet+a;
                    }
            }
        }
        else{
            for(int i=1;i<=31;i++){
                    if((i!=sets[0].getDay() && j!=sets[0].getMonth()) && (i!=sets[1].getDay() && j!=sets[1].getMonth()) && (i!=sets[2].getDay() && j!=sets[2].getMonth()) && (i!=sets[3].getDay() && j!=sets[3].getMonth()) && (i!=sets[4].getDay() && j!=sets[4].getMonth()) && (i!=sets[5].getDay() && j!=sets[5].getMonth())){
                        outStream << i << "," << j << endl;
                        DayofYearSet::DayofYear a(i,j);
                        complementSet=complementSet+a;
                    }
            }
        }
    }
    outStream << endl;
    return complementSet;
}
DayofYearSet::DayofYear DayofYearSet::operator[](int position){
    if (position >= numberOfElement) {
        cout << "Your index bigger than array size."<<endl;
        exit(0);
    }
    return sets[position];//the desired element is returned
}


DayofYearSet::~DayofYearSet(){
    //delete [] sets;
}

