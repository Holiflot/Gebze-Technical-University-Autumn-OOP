#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <cstdlib>
using namespace std;


class Tetris{
  private:
    vector<vector<char>> map;
    int height;
    int width;
  public:
    Tetris(int h,int w);
    const int get_height()const;
    const int get_width()const;
    void set_map();
    void move(const Tetrominos& obj);
    //void sleep(Tetrominos& obj){
   //}
    void print()const;
    
};
Tetris::Tetris(int h,int w){
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
     vector<char> temp1;
     vector<char> temp2;
     temp1.push_back('X');
    for(j=0;j<width-2;j++)
        temp1.push_back(' ');
    temp1.push_back('X');
    for(j=0;j<width;j++)
        temp2.push_back('X');
    map.push_back(temp2);
    for(i=0;i<height-2;i++)
        map.push_back(temp1);
    map.push_back(temp2);
 }
    
    void Tetris::move(const Tetrominos& obj){//Allows downward movement
    int i,j;
    int k,l;
    vector <int> a;
    vector < vector <int>> changing_position{//takes the changing position
        {0,0},
        {0,0},
        {0,0},
        {0,0},
    };
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            changing_position[i][j]=obj.position[i][j];//copies tetrominos's own position
        }
    }
        changing_position[0][1] = obj.position[0][1]+(width/2-1);//algorithm to reveal the shape
        changing_position[1][1] = obj.position[1][1]+(width/2-1);
        changing_position[2][1] = obj.position[2][1]+(width/2-1);
        changing_position[3][1] = obj.position[3][1]+(width/2-1);
        int count; 
        for(count=obj.position[3][0];count < height-1;count ++){//resets the map every time
            for(k=1;k<map.size()-1;k++){
                for(l=1;l<map[k].size()-1;l++){
                    map[k][l]=' ';
                }
            }
            for(i=0;i<obj.position.size();i++){//adding a shape to the map
                if(map[changing_position[i][0]][changing_position[i][1]]==' '){//accepting and printing non-empty indexes
                    map[changing_position[i][0]][changing_position[i][1]]=obj.temp[obj.position[i][0]][obj.position[i][1]];
                }
            }
            changing_position[0][0]++;//Each row is scrolled down one
            changing_position[1][0]++;
            changing_position[2][0]++;
            changing_position[3][0]++;
            print();
        }
        
}
    void Tetris::print()const{//printing map
    for (int i = 0; i < map.size(); i++){
        for (int j = 0; j < map[i].size(); j++){
                cout << map[i][j];
            }           
            cout << endl;
    }
    usleep(500000);//sleeping
    system("clear");// clear terminal
            cout << endl;
    
}
