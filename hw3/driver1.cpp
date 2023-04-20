#include "tetromino.hpp"
#include "tetris_board.hpp"

using namespace OSMAN;

int main(){

    int height=30,width=30;
    cout << "What is the height and width of the map?"<<endl;
    cout << "30" << endl;
    cout << "30" << endl;
    int num_tetrominos;
    int i;
    Tetris tetris_board(height,width);//constructor
    tetris_board.set_map();
    char tetrominoType;
    bool game=true;
    char direction;
    int count;
    int distance;
    char location;
    char *typeArr,*directionArr,*locationArr;
    int *countArr,*distanceArr;
    typeArr = new char[6];
    typeArr[0]='Z';
    typeArr[1]='S';
    typeArr[2]='R';
    typeArr[3]='T';
    typeArr[4]='q';
    typeArr[5]='q';
    directionArr = new char[6];
    directionArr[0]='R';
    directionArr[1]='L';
    directionArr[2]='R';
    directionArr[3]='L';
    directionArr[4]='R';
    directionArr[5]='R';
    locationArr = new char[6];
    locationArr[0]='L';
    locationArr[1]='R';
    locationArr[2]='L';
    locationArr[3]='L';
    locationArr[4]='L';
    locationArr[5]='R';
    countArr = new int[6];
    countArr[0]=3;
    countArr[1]=5;
    countArr[2]=3;
    countArr[3]=1;
    countArr[4]=2;
    countArr[5]=6;
    distanceArr = new int[6];
    distanceArr[0]=3;
    distanceArr[1]=5;
    distanceArr[2]=8;
    distanceArr[3]=1;
    distanceArr[4]=6;
    distanceArr[5]=7;
    int a=0;
    while(game==true){
        tetris_board.draw();
        cout << "What type do you want to choose ?" << endl;
         if (typeArr[a]=='R'){
            int random = (rand() % 7 + 1);//randomly selects characters
            switch (random)
            {
            case 1:
                typeArr[a]='I';
                break;
            case 2:
                typeArr[a]='O';
                break;
            case 3:
                typeArr[a]='J';
                break;
            case 4:
                typeArr[a]='L';
                break;
            case 5:
                typeArr[a]='S';
                break;
            case 6:
                typeArr[a]='T';
                break;
            case 7:
                typeArr[a]='Z';
                break;
            default:
                break;
            }
        }
        tetrominoType=typeArr[a];
        cout << tetrominoType<<endl;
        if(tetrominoType == 'q'){//ends when q is entered
            game=false;
        }
        else{
        cout << "which way to turn?('L' or 'R')" << endl;
        direction = directionArr[a];
        cout << "How many how many times does it turn?"<<endl;
        count = countArr[a];
        cout << "How far should it be from the center?" << endl;
        distance=distanceArr[a]; 
        cout << "Which region of the map would you choose?('L' or 'R')"<<endl;
        location= locationArr[a];
        Tetrominos c1(tetrominoType);
        c1.set_temp();
        c1.rotate(direction,count);
        c1.set_position();
        tetris_board.set_changing_position(c1,distance,location);
        while(tetris_board.changing_position[3][0]<tetris_board.get_height()-1){//loop for the map to go all the way down
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
    delete [] typeArr;//memory clearing
    delete [] directionArr;
    delete [] locationArr;
    delete [] countArr;
    delete [] distanceArr;
    return 0;
}