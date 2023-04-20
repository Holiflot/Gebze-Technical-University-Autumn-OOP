#ifndef TETRISARRAY1D
#define TETRISARRAY1D

#include "AbstractTetris.hpp"

class TetrisArray1D : public AbstractTetris{
    protected:
        char *map;
        int *changing_position;
    public:
        TetrisArray1D(int h,int w);
        int get_height() const{return heigth;};
        int get_width() const{return width;};
        void set_map();
        void draw() const;
        void animate()const;
        void set_changing_position(const Tetrominos& obj,int& distance,char& location);
        void move(const Tetrominos& obj,int& distance,char& location);
        TetrisArray1D& operator +=(const Tetrominos& obj);
        void clean_map();
        char* get_map1d()const{return map;};
        int* get_changing_position1d()const{return changing_position;};
        int numberOfMoves()const{return nom;};
        void lastMove();
        void writeToFile(const string &filename)const;
        // void readFromFile(const string &filename)const;
        ~TetrisArray1D();
};


#endif
