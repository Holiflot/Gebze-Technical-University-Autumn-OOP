#ifndef TETROMINO
#define TETROMINO



namespace OSMAN{
typedef char* charArray;
typedef int* intArray; 


enum class Tetros{I='I',T='T',O='O',J='J',L='L',S='S',Z='Z'};


class Tetrominos{// tetromino class and all tetrominos
    private:
    char tetrominos_I[4][4]{
        {' ',' ',' ',' '},
        {'I','I','I','I'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    };
    char tetrominos_T[4][4]{
        {' ',' ',' ',' '},
        {'T','T','T',' '},
        {' ','T',' ',' '},
        {' ',' ',' ',' '},
    };
    char tetrominos_O[4][4]{
        {' ',' ',' ',' '},
        {'O','O',' ',' '},
        {'O','O',' ',' '},
        {' ',' ',' ',' '},
    };
    char tetrominos_J[4][4]{
        {' ',' ',' ',' '},
        {'J',' ',' ',' '},
        {'J',' ',' ',' '},
        {'J','J',' ',' '},
    };
    char tetrominos_L[4][4]{
        {' ',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L','L',' ',' '},
    };
    char tetrominos_Z[4][4]{
        {' ',' ',' ',' '},
        {'Z','Z',' ',' '},
        {' ','Z','Z',' '},
        {' ',' ',' ',' '},
    };
    char tetrominos_S[4][4]{
        {' ',' ',' ',' '},
        {' ','S','S',' '},
        {'S','S',' ',' '}, 
        {' ',' ',' ',' '},
    };
        char typesOfTetrominos; //type of Tetromino
        
    public:
        intArray *position;// get position of full indexes
        charArray *temp;
        Tetrominos(char types);
        Tetrominos();
        char get_typesOfTetrominos();
        void set_temp();
        void set_position();
        void rotate(char &direction,int &count);
        ~Tetrominos();
};
}

#endif