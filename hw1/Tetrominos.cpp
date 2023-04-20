#include "Tetrominos.h"


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
vector<vector<char>> Tetrominos::get_temp(){
    return temp;
    }
void Tetrominos::print(){
    for (int i = 0; i < temp.size(); i++){
        for (int j = 0; j < temp[i].size(); j++)
            {
                cout << temp[i][j];
            }           
            cout << endl;
    }
            cout << endl;
        }
void Tetrominos::rotate(){
    int i,j;
    for( i = 0; i < 4; i++ )
    {
        for( j = 0; j < 4; j++ )
                {
                    //Clockwise rotation
                    swap(rotated_tetrominos[j][3-i],temp[i][j]);
                }
            }
            for ( i = 0; i < rotated_tetrominos.size(); i++){
                for ( j = 0; j < rotated_tetrominos[i].size(); j++)
                {
                    cout << rotated_tetrominos[i][j];
                }           
                cout << endl;
            }
            cout << endl;
        }
void Tetrominos::set_position(){
        int i,j;
    vector<int>a{0,0};
    for(i=0;i<temp.size();i++){
        for(j=0;j<temp[i].size();j++){
            if(temp[i][j]!='*'){      
                a.at(0)=i;
                a.at(1)=j;
                position.push_back(a);
            }
        }
    }
    } 
vector<vector<int>> Tetrominos::get_position(){
            return position;
        }
bool Tetrominos:: canFit(vector < vector <char>>& map){
    int i,j;
    int a=0;
        for(i=0;i<position.size();i++){
        if(map[position[i][0]][position[i][1]]=='*'){//accepting and printing non-empty indexes
            a+=1;
        }
        }
        if(a==4){//Since there are 4 full indexes, it returns the correct value when it returns 4, otherwise it gives an error.
            return true;
        }
        else{
            return false;
        } 
}   
void create_map(Tetrominos& obj,bool result,vector < vector <char>>& map){//creating map
            int i,j;
            if(result == 1){
                
                for(i=0;i<obj.get_position().size();i++)//if true the mape is printed
                    map[obj.get_position()[i][0]][obj.get_position()[i][1]]=obj.get_temp()[obj.get_position()[i][0]][obj.get_position()[i][1]];
                for(i=0;i<map.size();i++){
                    for(j=0;j<map[i].size();j++){
                        cout<<map[i][j];
                    }
                    cout<< endl;
                }
            }
            else{
                for(i=0;i<obj.get_position().size();i++){
                    obj.get_position()[i][1]+=1 ;//if false, indexes are shifted aside
                }
            }
        }