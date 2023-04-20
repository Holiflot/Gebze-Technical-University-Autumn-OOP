

public class tetrominos {
      /**
     * The tetrominos_I variable is a 2D char array that represents the 'I' shape of a tetromino.
     */
	private char[][] tetrominos_I={
        {' ',' ',' ',' '},
        {'I','I','I','I'},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '},
    }; 
	private char[][] tetrominos_T={
	        {' ',' ',' ',' '},
	        {'T','T','T',' '},
	        {' ','T',' ',' '},
	        {' ',' ',' ',' '},
	};
	private char[][] tetrominos_O={
	        {' ',' ',' ',' '},
	        {'O','O',' ',' '},
	        {'O','O',' ',' '},
	        {' ',' ',' ',' '},
	};
	private char[][] tetrominos_J={
        {' ',' ',' ',' '},
        {'J',' ',' ',' '},
        {'J',' ',' ',' '},
        {'J','J',' ',' '},
    };
    private char[][] tetrominos_L={
        {' ',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L',' ',' ',' '},
        {'L','L',' ',' '},
    };
    private char[][] tetrominos_Z={
        {' ',' ',' ',' '},
        {'Z','Z',' ',' '},
        {' ','Z','Z',' '},
        {' ',' ',' ',' '},
    };
    private char[][] tetrominos_S={
        {' ',' ',' ',' '},
        {' ','S','S',' '},
        {'S','S',' ',' '}, 
        {' ',' ',' ',' '},
    };
    private char typesOfTetrominos; 
    public char[][] temp;
    public int[][] position;
    public tetrominos(){};
    public tetrominos(char types){
                typesOfTetrominos=types;
    };
    public char get_typesOfTetrominos(){
        return typesOfTetrominos;
    };
    /**

    *The class tetrominos is used to create tetromino shapes and their positions.
    *It has two private variables, temp and position, which are used to store the shape and positions of the tetromino.
    *It also has several private char arrays, tetrominos_I, tetrominos_T, tetrominos_O, tetrominos_J, tetrominos_L, tetrominos_Z, tetrominos_S, which are used to store the different shapes of the tetromino.
    *It also has a private char variable, typesOfTetrominos, which is used to store the type of tetromino.

    */
    public void set_temp(){
        int i,j;
        temp=new char[4][4]; 
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                temp[i][j] = ' ';
        }
        if(typesOfTetrominos == 'I'){
            for(i=0;i<4;i++){
                for(j=0;j<4;j++)
                    temp[i][j]=tetrominos_I[i][j];
            }
        }
        else if(typesOfTetrominos == 'T'){
            for(i=0;i<4;i++){
                for(j=0;j<4;j++)
                    temp[i][j]=tetrominos_T[i][j];
            }
        }  
        else if(typesOfTetrominos == 'O'){
            for(i=0;i<4;i++){
                for(j=0;j<4;j++)
                    temp[i][j]=tetrominos_O[i][j];
            }
        }
        else if(typesOfTetrominos == 'J'){
            for(i=0;i<4;i++){
                for(j=0;j<4;j++)
                    temp[i][j]=tetrominos_J[i][j];
            }
        }
        else if(typesOfTetrominos == 'L'){
            for(i=0;i<4;i++){
                for(j=0;j<4;j++)
                    temp[i][j]=tetrominos_L[i][j];
            }
        }
        else if(typesOfTetrominos == 'Z'){
            for(i=0;i<4;i++){
                for(j=0;j<4;j++)
                    temp[i][j]=tetrominos_Z[i][j];
            }
        }
        else if(typesOfTetrominos == 'S'){
            for(i=0;i<4;i++){
                for(j=0;j<4;j++)
                    temp[i][j]=tetrominos_S[i][j];
            }
        }
        else 
            System.out.println("Your parameter is wrong");
    };
    public char[][] getTemp(){
    	return temp;
    }

    public void set_position(){
        int i,j,k=0;
        position=new int [4][2];
        for(i=0;i<4;i++){
            for(j=0;j<2;j++)
                position[i][j] = 0;
        }
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(temp[i][j]!=' '){      
                    position[k][0]=i;
                    position[k][1]=j;
                    k++;
                }
            }
        }
    };
    public int[][] getPosition(){
    	return position;
    }
    /**
 * The rotate method rotates the tetromino in a given direction and count of times.
 *
 * @param direction The direction of rotation, either "left" or "right"
 * @param count The number of times to rotate the tetromino
 */
    public void  rotate(char direction,int count){
        int i,j,a=0;
        char [][] arr=new char [4][4]; 
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                arr[i][j] = ' ';
        }
        for( i = 0; i < 4; i++ ){
            for( j = 0; j < 4; j++ )
            	arr[i][j]=temp[i][j];
        }
        for( i = 0; i < 4; i++ ){
            for( j = 0; j < 4; j++ )
            	temp[i][j]=0;
        }
        if(direction == 'R'){
            while(a<count){
                for( i = 0; i < 4; i++ ){
                    for( j = 0; j < 4; j++ )
                    	temp[j][3-i]=arr[i][j];
                }
                a++;
            }
        }
        else{
            while(a<count){
                for( i = 0; i < 4; i++ ){
                    for( j = 0; j < 4; j++ )
                        temp[3-j][i]=arr[i][j];
                }
                a++;
            }
    }

    }
}
