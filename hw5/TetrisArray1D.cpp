
#include "TetrisArray1D.hpp"

TetrisArray1D:: TetrisArray1D(int h,int w):AbstractTetris(h,w){}

void TetrisArray1D:: set_map(){
    int i;
    map = new char[heigth*width];
    for(i=0;i<width;i++)
        map[i]='X';
    for(i=heigth*width-width;i<heigth*width;i++)
        map[i] = 'X';
    for(i=0;i<heigth*width;i++){
        if(i%width == 0 || i%width == width-1)
            map[i]='X';
        if(map[i]!='X')
            map[i]=' ';
    }
}
void TetrisArray1D::animate()const{//printing map in an animated way
    for (int i = 0; i < heigth*width; i++){
        if(i%width == 0)
            cout << endl;
        cout << map[i];
    }
    cout << endl;
    usleep(50000);//sleeping
    system("clear");// clear terminal
            cout << endl;
    
}
void TetrisArray1D::draw()const{//printing map
    for (int i = 0; i < heigth*width; i++){
        if(i%width == 0)
            cout << endl;
        cout << map[i];
    }
    cout << endl;    
}
void TetrisArray1D ::set_changing_position(const Tetrominos& obj,int& distance,char& location){//takes the positions of the filled places
    int i,j;
    changing_position = new int[8];
    for(i=0;i<8;i++)
        changing_position[i]=0;
    int a=0;
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            changing_position[a]=obj.position[i][j];//copies tetrominos's own position
            a++;
        }
    }
    if(location == 'R'){
        for(i=0;i<4;i++){
        changing_position[i*2+1] = changing_position[i*2+1]+(width/2-1+distance);//put right of center
        }
    }
    else{
        for(i=0;i<4;i++){
        changing_position[i*2+1] = changing_position[i*2+1]+(width/2-1-distance);//put left of center
        }
    }
    lastm.first=location;
}
TetrisArray1D& TetrisArray1D:: operator +=(const Tetrominos& obj){//placing tetrmino on the map
    if(changing_position[0]==0){
        for(int i=0;i<4;i++)
            changing_position[i*2]++;//adjustment
        }
    for(int i=0;i<4;i++){//adding a shape to the map
        if(map[changing_position[i*2]*width+changing_position[i*2+1]] == ' '){//accepting and printing non-empty indexes
            map[changing_position[i*2]*width+changing_position[i*2+1]] = obj.temp[obj.position[i][0]][obj.position[i][1]];
        }
    }
    return *this;
}
void TetrisArray1D::move(const Tetrominos& obj,int& distance,char& location){//Allows downward movement
    int i;
    animate();
    for(i=0;i<4;i++)
        changing_position[i*2]++;//Each row is scrolled down one
    nom++;
    lastm.first=location;
}
void TetrisArray1D::clean_map(){
        for(int i=0;i<4;i++){//delete past position
            map[changing_position[i*2]*width-width+changing_position[i*2+1]]=' ';
        }
}
void TetrisArray1D::lastMove(){
        lastm.second = nom;
        cout <<"Last move: " << lastm.first << "," << lastm.second << endl;
}
void TetrisArray1D::writeToFile(const string &filename)const{
    ofstream out;
    out.open(filename);
    out << lastm.first << endl;
    out << lastm.second << endl;
    out.close();
};
// void TetrisArray1D::readFromFile(const string &filename)const{
//     ifstream in;
//     in.open(filename);
//     in >> lastm.first;
//     in >> lastm.second;
//     in.close();
// };
TetrisArray1D:: ~TetrisArray1D(){
    delete [] changing_position;
    delete [] map;
}