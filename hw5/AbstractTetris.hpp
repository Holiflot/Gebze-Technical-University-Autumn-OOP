#ifndef ABSTRACTTETRIS
#define ABSTRACTTETRIS

#include <iostream>
#include<vector>
#include <unistd.h>
#include <cstdlib>
#include <deque>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
using std :: cout;
using std :: cin;
using std :: cout;
using std :: vector;
using std :: endl;
using std :: swap;
using std :: deque;
using std :: pair;
using std :: string;
using std :: ifstream;
using std :: ofstream;

#include "Tetromino.hpp"

class AbstractTetris{
    protected : 
        int heigth,width;
        int nom=0;
        pair<char,int> lastm;
    public:
        AbstractTetris(int h, int w);//constructers
        AbstractTetris(int h);
        AbstractTetris();
        virtual int get_height() const = 0;//virtual functions
        virtual int get_width() const = 0;
        virtual void draw()const = 0;//print map
        virtual void animate()const = 0;//animate map
        virtual void set_map()= 0;//create map
        virtual void set_changing_position(const Tetrominos& obj,int& distance,char& location) = 0;
        virtual void move(const Tetrominos& obj,int& distance,char& location) = 0;//move down tetromino in board
        virtual void clean_map() = 0;//cleaning old tetrmino's location
        virtual int numberOfMoves()const = 0;//returns how many times tetromino move in board 
        virtual void lastMove() = 0;//write my number of move and last location Tetromino's in map
        virtual void writeToFile(const string &filename)const = 0;//write file some variables
        //virtual void readFromFile(const string &filename)const = 0;
};





#endif
