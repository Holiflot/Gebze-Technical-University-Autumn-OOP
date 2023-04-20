
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <cstdlib>
using namespace std;


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
        vector < vector <char>> temp;// all tetrominos are kept here
        char typesOfTetrominos; //type of Tetromino
        vector < vector <int>> position;// get position of full indexes
    public:
        Tetrominos(char types);
        void set_typesOfTetrominos(char types);
        char get_typesOfTetrominos();
        void set_temp();
        const vector<vector<char>> get_temp()const;
    void set_position();
    const vector<vector<int>> get_position()const;
    friend class Tetris;
};
Tetrominos::Tetrominos(char types){
            typesOfTetrominos=types;
}
void Tetrominos::set_typesOfTetrominos(char types){
                typesOfTetrominos =types;
            }
char Tetrominos::get_typesOfTetrominos(){
                return typesOfTetrominos;
            }
void Tetrominos::set_temp(){
    if(typesOfTetrominos == static_cast<char>(Tetros::I))
        temp = tetrominos_I;
    else if(typesOfTetrominos == static_cast<char>(Tetros::T))
        temp = tetrominos_T;   
    else if(typesOfTetrominos == static_cast<char>(Tetros::O))
        temp = tetrominos_O;
    else if(typesOfTetrominos == static_cast<char>(Tetros::J))
        temp = tetrominos_J;
    else if(typesOfTetrominos == static_cast<char>(Tetros::L))
        temp = tetrominos_L;
    else if(typesOfTetrominos == static_cast<char>(Tetros::Z))
        temp = tetrominos_Z;
    else if(typesOfTetrominos == static_cast<char>(Tetros::S))
        temp = tetrominos_S;
    else 
        cout <<"Your parameter is wrong" << endl;
        }
const vector<vector<char>> Tetrominos::get_temp()const{
    return temp;
    }
void Tetrominos::set_position(){//detecting and positioning points with shapes
        int i,j;
    vector<int>a{0,0};
    for(i=0;i<temp.size();i++){
        for(j=0;j<temp[i].size();j++){
            if(temp[i][j]!=' '){      
                a.at(0)=i;
                a.at(1)=j;
                position.push_back(a);
            }
        }
    }
    } 
const vector<vector<int>> Tetrominos::get_position()const{
    return position;
    }
