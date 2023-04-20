#ifndef _Tetrominos_H_
#define _Tetrominos_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;


enum class Tetros{I='I',T='T',O='O',J='J',L='L',S='S',Z='Z'};


class Tetrominos{
    private:
        vector < vector <char>> tetrominos_I{
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
        {'I','I','I','I'},
    };
    vector < vector <char>> tetrominos_T{
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
        {'T','T','T',' '},
        {' ','T',' ',' '},
    };
    vector < vector <char>> tetrominos_O{
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
        {'O','O',' ',' '},
        {'O','O',' ',' '},
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
        {' ',' ',' ',' '},
        {'Z','Z',' ',' '},
        {' ','Z','Z',' '},
    };
    vector < vector <char>> tetrominos_S{
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
        {' ','S','S',' '}, 
        {'S','S',' ',' '},
    };
        vector < vector <char>> temp;
        char typesOfTetrominos;
        vector < vector <int>> position;
        vector < vector <char>> rotated_tetrominos{
            {' ',' ',' ',' '},
            {' ',' ',' ',' '},
            {' ',' ',' ',' '}, 
            {' ',' ',' ',' '},
        };
        
    public:
    Tetrominos(char types);
    void set_typesOfTetrominos(char types);
    char get_typesOfTetrominos();
    void set_temp();
    vector<vector<char>> get_temp();
    void print();
    void rotate();
    void set_position();
    vector<vector<int>> get_position();
    bool canFit(vector < vector <char>>& map);
};
void create_map(Tetrominos& obj,bool result,vector < vector <char>>& map);
#endif /* _Tetrominos_H_ */