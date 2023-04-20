#include "TetrisVector.hpp"

TetrisVector :: TetrisVector(int h,int w): AbstractTetris(h,w){}

void TetrisVector:: set_map(){
    int i,j;
     vector<char> temp1;
     vector<char> temp2;
     temp1.push_back('X');
    for(j=0;j<get_width()-2;j++)
        temp1.push_back(' ');
    temp1.push_back('X');
    for(j=0;j<get_width();j++)
        temp2.push_back('X');
    map.push_back(temp2);
    for(i=0;i<get_height()-2;i++)
        map.push_back(temp1);
    map.push_back(temp2);
} 
void TetrisVector::animate()const{//printing map in an animated way
    for (int i = 0; i < map.size(); i++){
        for (int j = 0; j < map[i].size(); j++){
                cout << map[i][j];
            }           
            cout << endl;
    }
    usleep(50000);//sleeping
    system("clear");// clear terminal
            cout << endl;
    
}
void TetrisVector::draw()const{//printing map
    for (int i = 0; i < map.size(); i++){
        for (int j = 0; j < map[i].size(); j++){
                cout << map[i][j];
            }           
            cout << endl;
    }
}
void TetrisVector ::set_changing_position(const Tetrominos& obj,int& distance,char& location){//takes the positions of the filled places
    int i,j;
    vector <int> a{0,0};
    for(i=0;i<4;i++)
        changing_position.push_back(a);
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
    lastm.first=location;
}
TetrisVector& TetrisVector:: operator +=(const Tetrominos& obj){//placing tetrmino on the map
    if(changing_position[0][0]==0){
            changing_position[0][0]++;//adjustment
            changing_position[1][0]++;
            changing_position[2][0]++;
            changing_position[3][0]++;
        }
    for(int i=0;i<4;i++){//adding a shape to the map
                if(map[changing_position[i][0]][changing_position[i][1]]==' '){//accepting and printing non-empty indexes
                    map[changing_position[i][0]][changing_position[i][1]]=obj.temp[obj.position[i][0]][obj.position[i][1]];
                }
    }
    
    return *this;
}

    void TetrisVector::move(const Tetrominos& obj,int& distance,char& location){//Allows downward movement
    int i,j;
    int k,l;
    animate();
            changing_position[0][0]++;//Each row is scrolled down one
            changing_position[1][0]++;
            changing_position[2][0]++;
            changing_position[3][0]++;
    nom++;
}
void TetrisVector::clean_map(){
    for(int i=0;i<4;i++){//delete past position
        map[changing_position[i][0]-1][changing_position[i][1]]=' ';
    }
}
void TetrisVector::lastMove(){
        lastm.second = nom;
        cout <<"Last move: " << lastm.first << "," << lastm.second << endl;
}
void TetrisVector::writeToFile(const string &filename)const{
    ofstream out;
    out.open(filename);
    out << lastm.first << endl;
    out << lastm.second << endl;
    out.close();
};
// void TetrisVector::readFromFile(const string &filename)const{
//     ifstream in;
//     in.open(filename);
//     in >> lastm.first;
//     in >> lastm.second;
//     in.close();
// };