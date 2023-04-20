#ifndef TETRISVECTOR
#define TETRISVECTOR

#include "AbstractTetris.hpp"



class TetrisVector : public AbstractTetris{
    protected:
        vector<vector<char>> map;
        vector<vector<int >> changing_position;
    public:
        TetrisVector(int h,int w);
        int get_height() const{return heigth;};
        int get_width() const{return width;};
        void set_map();
        void draw() const;
        void animate()const;
        void set_changing_position(const Tetrominos& obj,int& distance,char& location);
        void move(const Tetrominos& obj,int& distance,char& location);
        TetrisVector& operator +=(const Tetrominos& obj);
        void clean_map();
        vector<vector<char>> get_mapVec()const{return map;};
        vector<vector<int>> get_changing_positionVec()const{return changing_position;};
        int numberOfMoves()const{return nom;};
        void lastMove();
        void writeToFile(const string &filename)const;
        // void readFromFile(const string &filename)const;
        ~TetrisVector(){};
};

#endif
