/**
 * The tetris_board class is responsible for creating and managing the game board for the Tetris game.
 * It includes methods to create the map, place Tetromino on the map, and clean full rows.
 */


public class tetris_board {
	private int height;
	private int width;
	public char[][] map;
	public int [][] changing_position;
	/**
     * Constructor for the tetris_board class
     * @param h the height of the map
     * @param w the width of the map
     */
	public tetris_board(int h,int w){
	    height=h;
	    width = w;
	};
	 /**
     * Getter method for the height of the map
     * @return the height of the map
	 * @return the width of the map
     */
	public int get_height(){
	    return height;
	}   
	public int get_width(){
	    return width;
	}
	/**
     * Method to create the map with the given height and width, and X's on the outer boundaries
     */
	public void set_map(){
		int i,j;
	    map=new char[height][width];
	    for(i=0;i<height;i++){
	        for(j=0;j<width;j++)
	            map[i][j] = ' ';
	    }
	    for(i=0;i<width;i++)
	        map[0][i] = 'X';
	    for(i=0;i<width;i++)
	        map[height-1][i]='X';
	    for(i=1;i< height-1;i++)
	        map[i][0] = 'X';
	    for(i=1;i< height-1;i++)
	        map[i][width-1]='X';
	};
	/**
     * Getter method for the map
     * @return the current state of the map
     */
	public char[][] getMap(){
		return map;
	}
	/**
     * Method to set the current position of the Tetromino on the map
     * @param obj the Tetromino object
     * @param distance the distance from the center of the map
     * @param location the location of the Tetromino ('L' or 'R')
     */
	public void set_changing_position(tetrominos obj,int distance,char location){//takes the positions of the filled places
	    int i,j;
	    changing_position =new int[4][2];
	    //takes the changing position
	    for(i=0;i<4;i++){
	        for(j=0;j<2;j++){
	            changing_position[i][j]=obj.position[i][j];//copies tetrominos's own position
	        }
	    }
	    if(location == 'R'){
	        changing_position[0][1] = obj.position[0][1]+(width/2-1+distance);//put right of center
	        changing_position[1][1] = obj.position[1][1]+(width/2-1+distance);
	        changing_position[2][1] = obj.position[2][1]+(width/2-1+distance);
	        changing_position[3][1] = obj.position[3][1]+(width/2-1+distance);
	    }
	    else{
	        changing_position[0][1] = obj.position[0][1]+(width/2-1-distance);//put left of center
	        changing_position[1][1] = obj.position[1][1]+(width/2-1-distance);
	        changing_position[2][1] = obj.position[2][1]+(width/2-1-distance);
	        changing_position[3][1] = obj.position[3][1]+(width/2-1-distance);
	    }
	};
	/**
     * Getter method for the current position of the Tetromino on the map
     * @return the current position of the Tetromino
     */
	public int[][] get_changing_position(){
    	return changing_position;
    };
	/**
     * Method to add a Tetromino to the map
     * @param obj the Tetromino object
     * @return the updated tetris_board object
     */
	public tetris_board  addTetromino(tetrominos obj){
	    for(int i=0;i<4;i++){
	        if(changing_position[0][0]==0){
	            changing_position[0][0]++;
	            changing_position[1][0]++;
	            changing_position[2][0]++;
	            changing_position[3][0]++;
	        }
	        	if(map[changing_position[i][0]][changing_position[i][1]]==' '){
	        		map[changing_position[i][0]][changing_position[i][1]]=obj.getTemp()[obj.getPosition()[i][0]][obj.getPosition()[i][1]];
	            }
	    }
	    return this;
	};
	/**
 * Method to clear the full rows in the map
 */
	public void clean_map(){
	    for(int i=0;i<4;i++){
	        map[changing_position[i][0]-1][changing_position[i][1]]=' ';
	    }
	};
	/**
 * Method to move the Tetromino down on the map
 */
	public void move(){
	    animate();
	            changing_position[0][0]++;
	            changing_position[1][0]++;
	            changing_position[2][0]++;
	            changing_position[3][0]++;
	};

	public void animate(){
		for (int i = 0; i < height; i++) {
		    for (int j = 0; j < width; j++) {
		        System.out.print(map[i][j]);
		    }
		    System.out.println();
		}
		try {
		    Thread.sleep(50);
		} catch (InterruptedException e) {
		    e.printStackTrace();
		}
		System.out.print("\033[H\033[2J");  
		System.out.flush();  
	    System.out.println();
	    
	};
	/**
 * Method to draw the current state of the map
 */
	public void draw(){
		for (int i = 0; i < height; i++) {
		    for (int j = 0; j < width; j++) {
		        System.out.print(map[i][j]);
		    }
		    System.out.println();
		}
	}
};
