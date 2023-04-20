#ifndef TETROMINO
#define TETROMINO

#include <iostream>
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

enum class Tetros{I='I',T='T',O='O',J='J',L='L',S='S',Z='Z'};


class Tetrominos{// tetromino class and all tetrominos
    private:
        vector < vector <char>> tetrominos_I{
        {' ',' ',' ',' '},
        {'I','I','I','I'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    vector < vector <char>> tetrominos_T{
        {' ',' ',' ',' '},
        {'T','T','T',' '},
        {' ','T',' ',' '},
        {' ',' ',' ',' '},
    };
    vector < vector <char>> tetrominos_O{
        {' ',' ',' ',' '},
        {'O','O',' ',' '},
        {'O','O',' ',' '},
        {' ',' ',' ',' '},
    };
    vector < vector <char>> tetrominos_J{
        {' ',' ',' ',' '},
        {'J',' ',' ',' '},
        {'J',' ',' ',' '},
        {'J','J',' ',' '},
    };
    vector < vector <char>> tetrominos_L{
        {' ',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L','L',' ',' '},
    };
    vector < vector <char>> tetrominos_Z{
        {' ',' ',' ',' '},
        {'Z','Z',' ',' '},
        {' ','Z','Z',' '},
        {' ',' ',' ',' '},
    };
    vector < vector <char>> tetrominos_S{
        {' ',' ',' ',' '},
        {' ','S','S',' '},
        {'S','S',' ',' '}, 
        {' ',' ',' ',' '},
    };
        char typesOfTetrominos; //type of Tetromino
    public:
        vector < vector <char>> temp;// all tetrominos are kept here
        vector < vector <int>> position;// get position of full indexes
        Tetrominos(char types);
        void set_typesOfTetrominos(char types);
        char get_typesOfTetrominos();
        void set_temp();
        const vector<vector<char>> get_temp()const;
        void set_position();
        const vector<vector<int>> get_position()const;
        void rotate(char &direction,int &count);
};



#endif