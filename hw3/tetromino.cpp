#include "tetromino.hpp"
#include <iostream>
using namespace std;
using namespace OSMAN;

Tetrominos::Tetrominos(){}
Tetrominos::Tetrominos(char types){
            typesOfTetrominos=types;
}
char Tetrominos::get_typesOfTetrominos(){
    return typesOfTetrominos;
}
void Tetrominos::set_temp(){
    int i,j;
    temp=new charArray[4]; //all tetrominos are kept here
    for(i=0;i<4;i++)
        temp[i]= new char[4];
    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
            temp[i][j] = ' ';
    }
    if(typesOfTetrominos == static_cast<char>(Tetros::I)){//whichever tetromino is chosen keeps it in the array
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                temp[i][j]=tetrominos_I[i][j];
        }
    }
    else if(typesOfTetrominos == static_cast<char>(Tetros::T)){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                temp[i][j]=tetrominos_T[i][j];
        }
    }  
    else if(typesOfTetrominos == static_cast<char>(Tetros::O)){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                temp[i][j]=tetrominos_O[i][j];
        }
    }
    else if(typesOfTetrominos == static_cast<char>(Tetros::J)){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                temp[i][j]=tetrominos_J[i][j];
        }
    }
    else if(typesOfTetrominos == static_cast<char>(Tetros::L)){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                temp[i][j]=tetrominos_L[i][j];
        }
    }
    else if(typesOfTetrominos == static_cast<char>(Tetros::Z)){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                temp[i][j]=tetrominos_Z[i][j];
        }
    }
    else if(typesOfTetrominos == static_cast<char>(Tetros::S)){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                temp[i][j]=tetrominos_S[i][j];
        }
    }
    else 
        cout <<"Your parameter is wrong" << endl;
}

void Tetrominos::set_position(){//detecting and positioning points with shapes
        int i,j,k=0;
    position=new intArray[4];
    for(i=0;i<4;i++)
        position[i]= new int[2];
    for(i=0;i<4;i++){
        for(j=0;j<2;j++)
            position[i][j] = 0;
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(temp[i][j]!=' '){      
                position[k][0]=i;
                position[k][1]=j;
                k++;
            }
        }
    }
    }

void Tetrominos:: rotate(char &direction,int &count){
    int i,j,a=0;
    charArray* arr;
    arr=new charArray[4]; //all rotated tetrominos are kept here
    for(i=0;i<4;i++)
        arr[i]= new char[4];
    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
            arr[i][j] = ' ';
    }
    for( i = 0; i < 4; i++ ){
        for( j = 0; j < 4; j++ )
            swap(arr[i][j],temp[i][j]);
    }
    cout << direction <<endl;
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
Tetrominos:: ~Tetrominos(){
    for(int i=0;i<4;i++)
        delete [] position[i];   //memory clearing
    delete [] position;
    cout << "Tetrominos position destructor worked";
    for(int i=0;i<4;i++)
        delete [] temp[i];   
    delete [] temp;
    cout << "Tetrominos temp destructor worked";
}


