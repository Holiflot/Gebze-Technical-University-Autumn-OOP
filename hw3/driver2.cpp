
#include "tetromino.hpp"
#include "tetris_board.hpp"

using namespace OSMAN;


int main(){

    int height,width;
    cout << "What is the height and width of the map?"<<endl;
    cin >> height;
    cin >> width;
    int num_tetrominos;
    int i;
    Tetris tetris_board(height,width);
    tetris_board.set_map();
    char tetrominoType;
    bool game=true;
    char direction;
    int count;
    int distance;
    char location;
    int a=0;
    while(game==true){
        tetris_board.draw();
        cout << "What type do you want to choose ?" << endl;
        cin >> tetrominoType;
        while(tetrominoType!='R' && tetrominoType!='L' && tetrominoType!='I' && tetrominoType!='T' && tetrominoType!='S' && tetrominoType!='J' && tetrominoType!='O' && tetrominoType!='q'){
            cout << "enter again" << endl;
            cin >>tetrominoType;
        }
        if (tetrominoType=='R'){
            int random = (rand() % 7 + 1);//randomly selects characters
            switch (random)
            {
            case 1:
                tetrominoType='I';
                break;
            case 2:
                tetrominoType='O';
                break;
            case 3:
                tetrominoType='J';
                break;
            case 4:
                tetrominoType='L';
                break;
            case 5:
                tetrominoType='S';
                break;
            case 6:
                tetrominoType='T';
                break;
            case 7:
                tetrominoType='Z';
                break;
            default:
                break;
            }
        }
        if(tetrominoType == 'q'){
            game=false;
        }
        else{
        cout << "which way to turn?('L' or 'R')" << endl;
        cin >> direction;
        while(direction!='R' && direction!='L'){
            cout << "enter again" << endl;
            cin >> direction;
        }
        cout << "How many how many times does it turn?"<<endl;
        cin >> count;
        cout << "How far should it be from the center?" << endl;
        cin >> distance;
        cout <<tetris_board.get_width()/2 << endl; 
        while((tetris_board.get_width()/2)-1+distance>tetris_board.get_width()-2 && tetris_board.get_width()/2-1-distance<2){
            cout << "distance greater than map size!!" << endl;
            cin >>distance;
        }
        cout <<distance<<endl;   
        cout << "Which region of the map would you choose?('L' or 'R')"<<endl;
        cin >> location;
        Tetrominos c1(tetrominoType);
        c1.set_temp();
        c1.rotate(direction,count);
        c1.set_position();
        tetris_board.set_changing_position(c1,distance,location);
        while(tetris_board.changing_position[3][0]<tetris_board.get_height()-1){
            tetris_board+=c1;//operator overloadiing
            tetris_board.move(c1,distance,location);
            if(a==tetris_board.changing_position[3][0])
                cout << ' ' <<endl;
            else
                tetris_board.clean_map();
        }
        tetris_board.animate();
        cout << a <<endl;
        a++;
        }
    }
    return 0;
}