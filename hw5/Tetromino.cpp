#include "Tetromino.hpp"

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
void Tetrominos:: rotate(char &direction,int &count){
    int i,j,a=0;
    vector<vector <char>> arr{
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    for( i = 0; i < temp.size(); i++ ){
        for( j = 0; j < temp[i].size(); j++ )
            arr[i][j]=temp[i][j];
    }
    if(direction == 'R'){
        while(a<count){
            for( i = 0; i < 4; i++ ){
                for( j = 0; j < 4; j++ )
                    swap(temp[j][3-i],arr[i][j]);
            }
            a++;
        }
    }
    else{
        while(a<count){
            for( i = 0; i < 4; i++ ){
                for( j = 0; j < 4; j++ )
                    swap(temp[3-j][i],arr[i][j]);
            }
            a++;
        }
    }
}
