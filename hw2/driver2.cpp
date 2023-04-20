#include <vector>
#include <cstdlib>
#include <iostream>
#include "Tetromino.cpp"
#include "Tetris.cpp"
#include <unistd.h>




int main(){

    int height,width;
    cout << "What is the height and width of the map?"<<endl;
    cin >> height;
    cin >> width;
    int num_tetrominos;
    int i;
    char tetrominoType[num_tetrominos];
    cout << "How many tetrominos? ?" << endl;
    cin >> num_tetrominos;
    cout << "What are types ?" << endl;
    vector<Tetrominos>t_vec;
    for(i=0;i<num_tetrominos;i++){
        cin >> tetrominoType[i];
        if (tetrominoType[i]=='R'){// random choosing
            int random = (rand() % 7 + 1);
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
    for(i=0;i<t_vec.size();i++){
        t_vec[i].set_temp();
        t_vec[i].set_position();
        tetris_board.move(t_vec[i]);
    }
    return 0;
}