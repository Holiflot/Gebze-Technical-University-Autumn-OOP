#include "AbstractTetris.hpp"
#include "Tetromino.hpp"
#include "TetrisAdapter.cpp"
#include "TetrisVector.hpp"
#include "TetrisArray1D.hpp"




int main(){
    string filename="myfile.txt";
    int height,width;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout <<"New driver" << endl;
    cout << "What is the height and width of the map?"<<endl;
    cin >> height;
    cin >> width;
    int choosen;
    cout << "Tetris vector:1, Tetris array 1d:2, Tetris Adapter 3" << endl;
    cin >> choosen;
    if(choosen == 1){//if you choose 1 create TetrisVector
        TetrisVector ad(height,width);
        ad.set_map();//create map
    int num_tetrominos;
    int i;
    char tetrominoType;
    bool game=true;
    char direction;
    int count;
    int distance;
    char location;
    while(game==true){
        ad.draw();
        cout << "What type do you want to choose ?" << endl;
        cin >> tetrominoType;
        while(tetrominoType!='L' && tetrominoType!='I' && tetrominoType!='T' && tetrominoType!='Z' && tetrominoType!='S' && tetrominoType!='J' && tetrominoType!='O' && tetrominoType!='q'){
            cout << "enter again" << endl;
            cin >>tetrominoType;
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
        while((ad.get_width()/2)-1+distance>ad.get_width()-2 && ad.get_width()/2-1-distance<2){
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
        ad.set_changing_position(c1,distance,location);
        //controlling clean add and move 
        if(ad.get_changing_positionVec()[3][0] == ad.get_changing_positionVec()[2][0] && ad.get_changing_positionVec()[3][0]!= ad.get_changing_positionVec()[1][0] && ad.get_changing_positionVec()[3][2]!= ad.get_changing_positionVec()[0][0]){
            while(ad.get_mapVec()[ad.get_changing_positionVec()[3][0]][ad.get_changing_positionVec()[3][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[2][0]][ad.get_changing_positionVec()[2][1]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;
            ad.move(c1,distance,location);//move down in board
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);//writing file
            //ad.readFromFile(filename);//reading file
            //control cleaning
            if(ad.get_changing_positionVec()[3][0]!=ad.get_height()-1 && ad.get_mapVec()[ad.get_changing_positionVec()[3][0]][ad.get_changing_positionVec()[3][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[2][0]][ad.get_changing_positionVec()[2][1]]==' '){
                ad.clean_map();
            }
        }
        }
        else if(ad.get_changing_positionVec()[3][0] == ad.get_changing_positionVec()[2][0] && ad.get_changing_positionVec()[3][0]== ad.get_changing_positionVec()[1][0] && ad.get_changing_positionVec()[3][0]!= ad.get_changing_positionVec()[0][0]){
            while(ad.get_mapVec()[ad.get_changing_positionVec()[3][0]][ad.get_changing_positionVec()[3][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[2][0]][ad.get_changing_positionVec()[2][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[1][0]][ad.get_changing_positionVec()[1][1]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);
            //ad.readFromFile(filename);
            if(ad.get_changing_positionVec()[3][0]!=ad.get_height()-1 && ad.get_mapVec()[ad.get_changing_positionVec()[3][0]][ad.get_changing_positionVec()[3][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[2][0]][ad.get_changing_positionVec()[2][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[1][0]][ad.get_changing_positionVec()[1][1]]==' '){
                ad.clean_map();
            }
        }
        }
        else if(ad.get_changing_positionVec()[3][0] == ad.get_changing_positionVec()[2][0] && ad.get_changing_positionVec()[3][0]== ad.get_changing_positionVec()[1][0] && ad.get_changing_positionVec()[3][0]== ad.get_changing_positionVec()[0][0]){
            while(ad.get_mapVec()[ad.get_changing_positionVec()[3][0]][ad.get_changing_positionVec()[3][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[2][0]][ad.get_changing_positionVec()[2][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[1][0]][ad.get_changing_positionVec()[1][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[0][0]][ad.get_changing_positionVec()[0][1]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;;
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);
            //ad.readFromFile(filename);
            if(ad.get_changing_positionVec()[3][0]!=ad.get_height()-1 && ad.get_mapVec()[ad.get_changing_positionVec()[3][0]][ad.get_changing_positionVec()[3][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[2][0]][ad.get_changing_positionVec()[2][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[1][0]][ad.get_changing_positionVec()[1][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[0][0]][ad.get_changing_positionVec()[0][1]]==' '){
                ad.clean_map();
            }
        }
        }
        else{
            while(ad.get_mapVec()[ad.get_changing_positionVec()[3][0]][ad.get_changing_positionVec()[3][1]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);
            //ad.readFromFile(filename);
            if(ad.get_changing_positionVec()[3][0]!=ad.get_height()-1 && ad.get_mapVec()[ad.get_changing_positionVec()[3][0]][ad.get_changing_positionVec()[3][1]]==' '){
                ad.clean_map();
            }
            }
        }

        }
    }
    }
    else if(choosen == 2){//if you choose 2 create TetrisArray1D
       TetrisArray1D ad(height,width);
        ad.set_map();
    int num_tetrominos;
    int i;
    char tetrominoType;
    bool game=true;
    char direction;
    int count;
    int distance;
    char location;
    while(game==true){
        ad.draw();
        cout << "What type do you want to choose ?" << endl;
        cin >> tetrominoType;
        while(tetrominoType!='L' && tetrominoType!='I' && tetrominoType!='T' && tetrominoType!='Z' && tetrominoType!='S' && tetrominoType!='J' && tetrominoType!='O' && tetrominoType!='q'){
            cout << "enter again" << endl;
            cin >>tetrominoType;
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
        while((ad.get_width()/2)-1+distance>ad.get_width()-2 && ad.get_width()/2-1-distance<2){
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
        ad.set_changing_position(c1,distance,location);
        if(ad.get_changing_position1d()[6] == ad.get_changing_position1d()[4] && ad.get_changing_position1d()[6]!= ad.get_changing_position1d()[2] && ad.get_changing_position1d()[6]!= ad.get_changing_position1d()[0]){
            while(ad.get_map1d()[ad.get_changing_position1d()[6]*ad.get_height()+ad.get_changing_position1d()[7]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[4]*ad.get_height()+ad.get_changing_position1d()[5]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);
            //ad.readFromFile(filename);
            if(ad.get_changing_position1d()[6]!=ad.get_height()-1 && ad.get_map1d()[ad.get_changing_position1d()[6]*ad.get_height()+ad.get_changing_position1d()[7]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[4]*ad.get_height()+ad.get_changing_position1d()[5]]==' '){
                ad.clean_map();
            }
        }
        }
        else if(ad.get_changing_position1d()[6] == ad.get_changing_position1d()[4] && ad.get_changing_position1d()[6]== ad.get_changing_position1d()[2] && ad.get_changing_position1d()[6]!= ad.get_changing_position1d()[0]){
            while(ad.get_map1d()[ad.get_changing_position1d()[6]*ad.get_height()+ad.get_changing_position1d()[7]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[4]*ad.get_height()+ad.get_changing_position1d()[5]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[2]*ad.get_height()+ad.get_changing_position1d()[3]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);
            //ad.readFromFile(filename);
            if(ad.get_changing_position1d()[6]!=ad.get_height()-1 && ad.get_map1d()[ad.get_changing_position1d()[6]*ad.get_height()+ad.get_changing_position1d()[7]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[4]*ad.get_height()+ad.get_changing_position1d()[5]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[2]*ad.get_height()+ad.get_changing_position1d()[3]]==' '){
                ad.clean_map();
            }
        }
        }
        else if(ad.get_changing_position1d()[6] == ad.get_changing_position1d()[4] && ad.get_changing_position1d()[6]== ad.get_changing_position1d()[2] && ad.get_changing_position1d()[6]== ad.get_changing_position1d()[0]){
            while(ad.get_map1d()[ad.get_changing_position1d()[6]*ad.get_height()+ad.get_changing_position1d()[7]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[4]*ad.get_height()+ad.get_changing_position1d()[5]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[2]*ad.get_height()+ad.get_changing_position1d()[3]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[0]*ad.get_height()+ad.get_changing_position1d()[1]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;;
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);
            //ad.readFromFile(filename);
            if(ad.get_changing_position1d()[6]!=ad.get_height()-1 && ad.get_map1d()[ad.get_changing_position1d()[6]*ad.get_height()+ad.get_changing_position1d()[7]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[4]*ad.get_height()+ad.get_changing_position1d()[5]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[2]*ad.get_height()+ad.get_changing_position1d()[3]]==' ' && ad.get_map1d()[ad.get_changing_position1d()[0]*ad.get_height()+ad.get_changing_position1d()[1]]==' '){
                ad.clean_map();
            }
        }
        }
        else{
            while(ad.get_map1d()[ad.get_changing_position1d()[6]*ad.get_height()+ad.get_changing_position1d()[7]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);
            //ad.readFromFile(filename);
            if(ad.get_changing_position1d()[6]!=ad.get_height()-1 && ad.get_map1d()[ad.get_changing_position1d()[6]*ad.get_height()+ad.get_changing_position1d()[7]]==' '){
                ad.clean_map();
            }
            }
        }

        }
    }
    }
    else{//if you choose 3 create TetrisAdapter
        TetrisAdapter<deque<char>> ad(height,width);
        ad.set_map();
    int num_tetrominos;
    int i;
    char tetrominoType;
    bool game=true;
    char direction;
    int count;
    int distance;
    char location;
    while(game==true){
        ad.draw();
        cout << "What type do you want to choose ?" << endl;
        cin >> tetrominoType;
        while(tetrominoType!='L' && tetrominoType!='I' && tetrominoType!='T' && tetrominoType!='Z' && tetrominoType!='S' && tetrominoType!='J' && tetrominoType!='O' && tetrominoType!='q'){
            cout << "enter again" << endl;
            cin >>tetrominoType;
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
        while((ad.get_width()/2)-1+distance>ad.get_width()-2 && ad.get_width()/2-1-distance<2){
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
        ad.set_changing_position(c1,distance,location);
        if(ad.get_changing_positionAdapter()[6] == ad.get_changing_positionAdapter()[4] && ad.get_changing_positionAdapter()[6]!= ad.get_changing_positionAdapter()[2] && ad.get_changing_positionAdapter()[6]!= ad.get_changing_positionAdapter()[0]){
            while(ad.get_map()[ad.get_changing_positionAdapter()[6]*ad.get_height()+ad.get_changing_positionAdapter()[7]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[4]*ad.get_height()+ad.get_changing_positionAdapter()[5]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;
            //d.move(c1,distance,location);
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            if(ad.get_changing_positionAdapter()[6]!=ad.get_height()-1 && ad.get_map()[ad.get_changing_positionAdapter()[6]*ad.get_height()+ad.get_changing_positionAdapter()[7]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[4]*ad.get_height()+ad.get_changing_positionAdapter()[5]]==' '){
                ad.clean_map();
            }
        }
        }
        else if(ad.get_changing_positionAdapter()[6] == ad.get_changing_positionAdapter()[4] && ad.get_changing_positionAdapter()[6]== ad.get_changing_positionAdapter()[2] && ad.get_changing_positionAdapter()[6]!= ad.get_changing_positionAdapter()[0]){
            while(ad.get_map()[ad.get_changing_positionAdapter()[6]*ad.get_height()+ad.get_changing_positionAdapter()[7]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[4]*ad.get_height()+ad.get_changing_positionAdapter()[5]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[2]*ad.get_height()+ad.get_changing_positionAdapter()[3]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);
            //ad.readFromFile(filename);
            if(ad.get_changing_positionAdapter()[6]!=ad.get_height()-1 && ad.get_map()[ad.get_changing_positionAdapter()[6]*ad.get_height()+ad.get_changing_positionAdapter()[7]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[4]*ad.get_height()+ad.get_changing_positionAdapter()[5]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[2]*ad.get_height()+ad.get_changing_positionAdapter()[3]]==' '){
                ad.clean_map();
            }
        }
        }
        else if(ad.get_changing_positionAdapter()[6] == ad.get_changing_positionAdapter()[4] && ad.get_changing_positionAdapter()[6]== ad.get_changing_positionAdapter()[2] && ad.get_changing_positionAdapter()[6]== ad.get_changing_positionAdapter()[0]){
            while(ad.get_map()[ad.get_changing_positionAdapter()[6]*ad.get_height()+ad.get_changing_positionAdapter()[7]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[4]*ad.get_height()+ad.get_changing_positionAdapter()[5]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[2]*ad.get_height()+ad.get_changing_positionAdapter()[3]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[0]*ad.get_height()+ad.get_changing_positionAdapter()[1]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;;
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);
            //ad.readFromFile(filename);
            if(ad.get_changing_positionAdapter()[6]!=ad.get_height()-1 && ad.get_map()[ad.get_changing_positionAdapter()[6]*ad.get_height()+ad.get_changing_positionAdapter()[7]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[4]*ad.get_height()+ad.get_changing_positionAdapter()[5]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[2]*ad.get_height()+ad.get_changing_positionAdapter()[3]]==' ' && ad.get_map()[ad.get_changing_positionAdapter()[0]*ad.get_height()+ad.get_changing_positionAdapter()[1]]==' '){
                ad.clean_map();
            }
        }
        }
        else{
            while(ad.get_map()[ad.get_changing_positionAdapter()[6]*ad.get_height()+ad.get_changing_positionAdapter()[7]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);
            //ad.readFromFile(filename);
            if(ad.get_changing_positionAdapter()[6]!=ad.get_height()-1 && ad.get_map()[ad.get_changing_positionAdapter()[6]*ad.get_height()+ad.get_changing_positionAdapter()[7]]==' '){
                ad.clean_map();
            }
            }
        }

        }
    }
    }
    
    return 0;
}
