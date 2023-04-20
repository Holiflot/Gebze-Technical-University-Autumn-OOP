#include "tetris_board.hpp"
using namespace OSMAN;

Tetris::Tetris(int h,int w){//constructor
    height=h;
    width = w;
}
    const int Tetris::get_height()const{
    return height;
}   
    const int Tetris::get_width()const{
    return width;
}
    void Tetris::set_map(){//creating map
    int i,j;
    cout << width<<endl;
    map=new charArray[height];
    for(i=0;i<height;i++)
        map[i]= new char[width];
    for(i=0;i<height;i++){
        for(j=0;j<width;j++)
            map[i][j] = ' ';
    }
    for(i=0;i<width;i++)
        map[0][i] = 'X';
    for(i=0;i<width;i++)
        map[height-1][i]='X';
    for(i=1;i< height-1;i++)
        map[i][0] = 'X';
    for(i=1;i< height-1;i++)
        map[i][width-1]='X';
}
void Tetris::set_changing_position(const Tetrominos& obj,int& distance,char& location){//takes the positions of the filled places
    int i,j;
    changing_position =new intArray[4];
    for(i=0;i<4;i++)
        changing_position[i]= new int[2];
    //takes the changing position
    for(i=0;i<4;i++){
        for(j=0;j<2;j++)
            changing_position[i][j] = 0;
    }
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            changing_position[i][j]=obj.position[i][j];//copies tetrominos's own position
        }
    }
    if(location == 'R'){
        changing_position[0][1] = obj.position[0][1]+(width/2-1+distance);//put right of center
        changing_position[1][1] = obj.position[1][1]+(width/2-1+distance);
        changing_position[2][1] = obj.position[2][1]+(width/2-1+distance);
        changing_position[3][1] = obj.position[3][1]+(width/2-1+distance);
    }
    else{
        changing_position[0][1] = obj.position[0][1]+(width/2-1-distance);//put left of center
        changing_position[1][1] = obj.position[1][1]+(width/2-1-distance);
        changing_position[2][1] = obj.position[2][1]+(width/2-1-distance);
        changing_position[3][1] = obj.position[3][1]+(width/2-1-distance);
    }
}
Tetris& Tetris:: operator +=(const Tetrominos& obj){//placing tetrmino on the map
    for(int i=0;i<4;i++){//adding a shape to the map
        if(changing_position[0][0]==0){
            changing_position[0][0]++;//adjustment
            changing_position[1][0]++;
            changing_position[2][0]++;
            changing_position[3][0]++;
        }
                if(map[changing_position[i][0]][changing_position[i][1]]==' '){//accepting and printing non-empty indexes
                    map[changing_position[i][0]][changing_position[i][1]]=obj.temp[obj.position[i][0]][obj.position[i][1]];
                }
    }
    
    return *this;
}
void Tetris::clean_map(){
    for(int i=0;i<4;i++){//delete past position
        map[changing_position[i][0]-1][changing_position[i][1]]=' ';
    }
}
    void Tetris::move(const Tetrominos& obj,int& distance,char& location){//Allows downward movement
    int i,j;
    int k,l;
    animate();
            changing_position[0][0]++;//Each row is scrolled down one
            changing_position[1][0]++;
            changing_position[2][0]++;
            changing_position[3][0]++;
}


    void Tetris::animate()const{//printing map in an animated way
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
                cout << map[i][j];
            }           
            cout << endl;
    }
    usleep(50000);//sleeping
    system("clear");// clear terminal
            cout << endl;
    
}
void Tetris::draw()const{//printing map
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
                cout << map[i][j];
            }           
            cout << endl;
    }
}
Tetris:: ~Tetris(){
    for(int i=0;i<height;i++)//memory clearing
        delete [] map[i];   
    delete [] map;
    for(int i=0;i<4;i++)
        delete [] changing_position[i];   
    delete [] changing_position;
}