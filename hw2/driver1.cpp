#include <vector>
#include <cstdlib>
#include <iostream>
#include "Tetromino.cpp"
#include "Tetris.cpp"
#include <unistd.h>

int main(){

    int height=16,width=16;
    cout << "What is the height and width of the map?"<<endl;
    cout << "16" << endl;
    cout << "16" << endl;
    int num_tetrominos=3;
    int i,j,k;
    bool result;
    char tetrominoType[num_tetrominos];
    cout << "How many tetrominos? ?" << endl;
    cout << "3" << endl;
    cout << "What are types ?" << endl;
    tetrominoType[0]='R';
    tetrominoType[1]='J';
    tetrominoType[2]='T';
    vector<Tetrominos>t_vec;
    for(i=0;i<num_tetrominos;i++){
        if (tetrominoType[i]=='R'){
            int random = (rand() % 7 + 1);//randomly selects characters
            switch (random)
            {
            case 1:
                tetrominoType[i]='I';
                break;
            case 2:
                tetrominoType[i]='O';
                break;
            case 3:
                tetrominoType[i]='J';
                break;
            case 4:
                tetrominoType[i]='L';
                break;
            case 5:
                tetrominoType[i]='S';
                break;
            case 6:
                tetrominoType[i]='T';
                break;
            case 7:
                tetrominoType[i]='Z';
                break;
            default:
                break;
            }
        }
        t_vec.push_back(tetrominoType[i]);
    }
    Tetris tetris_board(height,width);
    tetris_board.set_map();
    vector<vector<int>> temp;
    for(i=0;i<t_vec.size();i++){
        t_vec[i].set_temp();
        t_vec[i].set_position();
        tetris_board.move(t_vec[i]);
    }
    //tetris_board.print();
    return 0;
}
