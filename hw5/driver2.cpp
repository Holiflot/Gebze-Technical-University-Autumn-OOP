#include "AbstractTetris.hpp"
#include "Tetromino.hpp"
#include "TetrisAdapter.cpp"
#include "TetrisVector.hpp"
#include "TetrisArray1D.hpp"




int main(){
    string filename="myfile.txt";
    int height=24,width=24;
    cout << "What is the height and width of the map?"<<endl;
    bool stop=true;
    int n=0;
    while(stop==true){
    int choosen[]={1,2,3,4};
    char *typeArr,*directionArr,*locationArr;
    int *countArr,*distanceArr;
    typeArr = new char[6];
    typeArr[0]='Z';
    typeArr[1]='S';
    typeArr[2]='I';
    typeArr[3]='T';
    typeArr[4]='L';
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
    int p=0;
    int o=0;
    int y=0;
    cout << "Tetris vector:1, Tetris array 1d:2, Tetris Adapter 3" << endl;
    if(choosen[n]==4){
        stop=false;
    }
    else{
    if(choosen[n] == 1){
        TetrisVector ad(height,width);
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
        tetrominoType=typeArr[p];
        while(tetrominoType!='R' && tetrominoType!='L' && tetrominoType!='I' && tetrominoType!='T' && tetrominoType!='Z' && tetrominoType!='S' && tetrominoType!='J' && tetrominoType!='O' && tetrominoType!='q'){
            cout << "enter again" << endl;
            cin >>tetrominoType;
        }
        if(tetrominoType == 'q'){
            game=false;
        }
        else{
        cout << "which way to turn?('L' or 'R')" << endl;
        direction=directionArr[p];
        while(direction!='R' && direction!='L'){
            cout << "enter again" << endl;
            cin >> direction;
        }
        cout << "How many how many times does it turn?"<<endl;
        count=countArr[p];
        cout << "How far should it be from the center?" << endl;
        distance=distanceArr[p];
        while((ad.get_width()/2)-1+distance>ad.get_width()-2 && ad.get_width()/2-1-distance<2){
            cout << "distance greater than map size!!" << endl;
            cin >>distance;
        }
        cout <<distance<<endl;   
        cout << "Which region of the map would you choose?('L' or 'R')"<<endl;
        location=locationArr[p];
        Tetrominos c1(tetrominoType);
        c1.set_temp();
        c1.rotate(direction,count);
        c1.set_position();
        ad.set_changing_position(c1,distance,location);
        if(ad.get_changing_positionVec()[3][0] == ad.get_changing_positionVec()[2][0] && ad.get_changing_positionVec()[3][0]!= ad.get_changing_positionVec()[1][0] && ad.get_changing_positionVec()[3][2]!= ad.get_changing_positionVec()[0][0]){
            while(ad.get_mapVec()[ad.get_changing_positionVec()[3][0]][ad.get_changing_positionVec()[3][1]]==' ' && ad.get_mapVec()[ad.get_changing_positionVec()[2][0]][ad.get_changing_positionVec()[2][1]]==' '){
            //d+=c1;//operator overloadiing
            ad+=c1;
            ad.move(c1,distance,location);
            cout <<"Number of moves: " <<ad.numberOfMoves() << endl;
            ad.lastMove();
            ad.writeToFile(filename);
            //ad.readFromFile(filename);
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
        p++;
    }
    }
    else if(choosen[n] == 2){
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
        tetrominoType=typeArr[y];
        while(tetrominoType!='R' && tetrominoType!='L' && tetrominoType!='I' && tetrominoType!='T' && tetrominoType!='Z' && tetrominoType!='S' && tetrominoType!='J' && tetrominoType!='O' && tetrominoType!='q'){
            cout << "enter again" << endl;
            cin >>tetrominoType;
        }
        if(tetrominoType == 'q'){
            game=false;
        }
        else{
        cout << "which way to turn?('L' or 'R')" << endl;
        direction=directionArr[y];
        while(direction!='R' && direction!='L'){
            cout << "enter again" << endl;
            cin >> direction;
        }
        cout << "How many how many times does it turn?"<<endl;
        count=countArr[y];
        cout << "How far should it be from the center?" << endl;
        distance=distanceArr[y];
        while((ad.get_width()/2)-1+distance>ad.get_width()-2 && ad.get_width()/2-1-distance<2){
            cout << "distance greater than map size!!" << endl;
            cin >>distance;
        }
        cout <<distance<<endl;   
        cout << "Which region of the map would you choose?('L' or 'R')"<<endl;
        location=locationArr[y];
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
        y++;
    }
    }
    else{
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
        tetrominoType=typeArr[o];
        while(tetrominoType!='R' && tetrominoType!='L' && tetrominoType!='I' && tetrominoType!='T' && tetrominoType!='Z' && tetrominoType!='S' && tetrominoType!='J' && tetrominoType!='O' && tetrominoType!='q'){
            cout << "enter again" << endl;
            cin >>tetrominoType;
        }
        if(tetrominoType == 'q'){
            game=false;
        }
        else{
        cout << "which way to turn?('L' or 'R')" << endl;
        direction=directionArr[o];
        while(direction!='R' && direction!='L'){
            cout << "enter again" << endl;
            cin >> direction;
        }
        cout << "How many how many times does it turn?"<<endl;
        count=countArr[o];
        cout << "How far should it be from the center?" << endl;
        distance=distanceArr[o];
        while((ad.get_width()/2)-1+distance>ad.get_width()-2 && ad.get_width()/2-1-distance<2){
            cout << "distance greater than map size!!" << endl;
            cin >>distance;
        }
        cout <<distance<<endl;   
        cout << "Which region of the map would you choose?('L' or 'R')"<<endl;
        location=locationArr[o];
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
        o++;
    }
    }
    }
    n++;
    }
    return 0;
}
