#include "Tetrominos.h"

int main(){

    vector < vector <char>> map{
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, 
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        };
    int num_tetrominos;
    int i;
    bool result;
    cout << "How many tetrominos? ?" << endl;
    cin >> num_tetrominos;;
    cout << "What are types ?" << endl;
    vector<Tetrominos>t_vec;
    char tetrominoType[num_tetrominos];
    for(i=0;i<num_tetrominos;i++){
        cin >> tetrominoType[i];
        t_vec.push_back(tetrominoType[i]);
    }
    for(i=0;i<t_vec.size();i++){
        t_vec[i].set_temp();
        t_vec[i].set_position();
        t_vec[i].print();
        result=t_vec[i].canFit(map);
        create_map(t_vec[i],result,map);
        t_vec[i].rotate();
    }
    return 0;
}