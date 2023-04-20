#ifndef TETRIS_BOARD
#define TETRIS_BOARD
#include "tetromino.hpp"
#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;


namespace OSMAN{

typedef char* charArray;
typedef int* intArray; 
class Tetris{//tetris class
  private:
    int height;
    int width;
  public:
    charArray *map;
    Tetris(int h,int w);
    const int get_height()const;
    const int get_width()const;
    void set_map();
    intArray * changing_position;
    void set_changing_position(const Tetrominos& obj,int& distance,char& location);
    void move(const Tetrominos& obj,int& distance,char& location);
    ~Tetris();
    void draw()const;
    void animate()const;
    Tetris& operator +=(const Tetrominos& obj);
    void clean_map();
};

}


#endif