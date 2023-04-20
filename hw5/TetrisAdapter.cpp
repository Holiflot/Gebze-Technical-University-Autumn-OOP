#include "AbstractTetris.hpp"


template <class Type>//template class
class TetrisAdapter : public AbstractTetris{
    protected:
        Type map;
        int* changing_position;
    public:
        TetrisAdapter(int h,int w): AbstractTetris(h,w){}
        int get_height() const{return heigth;};
        int get_width() const{return width;};
        void set_map();//create map
        void draw() const;//print map
        void animate()const;//animate map
        void set_changing_position(const Tetrominos& obj,int& distance,char& location);
        TetrisAdapter<Type>& operator +=(const Tetrominos& obj);//adding tetrominos map
        void move(const Tetrominos& obj,int& distance,char& location);//move in board
        void clean_map();//clean old locations
        int* get_changing_positionAdapter()const{return changing_position;};
        Type get_map()const{return map;};
        int numberOfMoves()const{return nom;};
        void lastMove();//write my number of move and last location Tetromino's in map
        void writeToFile(const string &filename)const;//writing file
        // void readFromFile(const string &filename)const;
        ~TetrisAdapter(){//destructer
            delete [] changing_position; 
        };
};


template<class Type>
void TetrisAdapter<Type>:: set_map(){
    int i,j;
    for(j=0;j<width-2;j++)
        map.push_back('X');
    for(i=0;i<width*(heigth-1);i++){
        if(i%width == 0 || i%width == width-1)
            map.push_back('X');
        if(map[i]!='X')
            map.push_back(' ');
    }
    for(j=0;j<width;j++)
        map.push_back('X');
}

template<class Type>
void TetrisAdapter<Type>:: draw()const{
    for (int i = 0; i < heigth*width; i++){
        if(i%width == 0)
            cout << endl;
        cout << map[i];
    }
    cout << endl;
}
template<class Type>
void TetrisAdapter<Type>::animate()const{//printing map in an animated way
    for (int i = 0; i < heigth*width; i++){
        if(i%width == 0)
            cout << endl;
        cout << map[i];
    }
    cout << endl;
    usleep(50000);//sleeping
    system("clear");// clear terminal
            cout << endl;
    
}

template<class Type>
void TetrisAdapter<Type>::set_changing_position(const Tetrominos& obj,int& distance,char& location){
    int i,j;
    changing_position = new int[8];
    for(i=0;i<8;i++)
        changing_position[i]=0;
    int a=0;
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            changing_position[a]=obj.position[i][j];//copies tetrominos's own position
            a++;
        }
    }
    if(location == 'R'){
        for(i=0;i<4;i++){
        changing_position[i*2+1] = changing_position[i*2+1]+(width/2-1+distance);//put right of center
        }
    }
    else{
        for(i=0;i<4;i++){
        changing_position[i*2+1] = changing_position[i*2+1]+(width/2-1-distance);//put left of center
        }
    }
    lastm.first=location;
}
template<class Type>
TetrisAdapter<Type>& TetrisAdapter<Type>:: operator +=(const Tetrominos& obj){//placing tetrmino on the map
    if(changing_position[0]==0){
        for(int i=0;i<4;i++)
            changing_position[i*2]++;//adjustment
        }
    for(int i=0;i<4;i++){//adding a shape to the map
        if(map[changing_position[i*2]*width+changing_position[i*2+1]] == ' '){//accepting and printing non-empty indexes
            map[changing_position[i*2]*width+changing_position[i*2+1]] = obj.temp[obj.position[i][0]][obj.position[i][1]];
        }
    }
    return *this;
}
template<class Type>
void TetrisAdapter<Type>::move(const Tetrominos& obj,int& distance,char& location){//Allows downward movement
    int i;
    animate();
    for(i=0;i<4;i++)
        changing_position[i*2]++;//Each row is scrolled down one
        nom++;
}
template<class Type>
void TetrisAdapter<Type>::clean_map(){
        for(int i=0;i<4;i++){//delete past position
            map[changing_position[i*2]*width-width+changing_position[i*2+1]]=' ';
        }
}
template<class Type>
void TetrisAdapter<Type>::lastMove(){
        lastm.second = nom;
        cout <<"Last move: " << lastm.first << "," << lastm.second << endl;
}
template<class Type>
void TetrisAdapter<Type>::writeToFile(const string &filename)const{
    ofstream out;
    out.open(filename);
    out << lastm.first << endl;
    out << lastm.second << endl;
    out.close();
};
// template<class Type>
// void TetrisAdapter<Type>::readFromFile(const string &filename)const{
//     ifstream in;
//     in.open(filename);
//     in >> lastm.first;
//     in >> lastm.second;
//     in.close();
// };