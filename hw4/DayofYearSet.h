#ifndef _Tetrominos_H_
#define _Tetrominos_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <list>   
#include <fstream>
#include <sstream>
#include <iterator>
#include <list>
using namespace std;

//namespace OSMAN{


class DayofYearSet
{
public:
	class DayofYear
	{
	public:
		DayofYear(int d, int m);//DayofYear constructors
		DayofYear(int d);
		DayofYear();
		void controlDate(int d, int m);//controling date true value
		int getDay() const {return day;} //getters
		int getMonth() const {return month;}
	private:
		int day;
		int month;
	};
	
	DayofYearSet(list<DayofYear> &l);
	DayofYearSet();
	int getNumofElements() const {return numberOfElement;}
	DayofYearSet operator+(DayofYearSet::DayofYear &date);//adding element
	void remove(int position);
    int size() const {return numberOfElement;}//size of set
	void testRemove(); 
    friend ostream & operator <<(ostream &out, const DayofYearSet &obj);//operator overloadings
    bool operator==(const DayofYearSet &obj) const; 
    bool operator!=(const DayofYearSet &obj) const;
    DayofYearSet operator+(const DayofYearSet &obj) const;
    DayofYearSet operator-(const DayofYearSet &obj) const;
    DayofYearSet operator^(const DayofYearSet &obj) const;
    DayofYearSet operator!();
    DayofYearSet::DayofYear operator[](int position);
    ~DayofYearSet();//destructors
private:
	DayofYear *sets = nullptr;
	int numberOfElement=0;	
};


//}
#endif /* _DayofYearSet_H_ */