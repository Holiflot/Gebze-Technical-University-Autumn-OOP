
import java.util.Scanner;
import java.util.Random;
/**
 * This class is for a game of Tetris using the Java programming language.
 * It initializes a Tetris board of height and width 24, and then sets the map. 
 * The code then declares several variables, including a char array to store the types of Tetrominoes, 
 * a char array to store the direction to turn the Tetrominoes, and int arrays to store the count and distance of the Tetrominoes. 
 * The while loop at the end of the code is the main game loop, where it draws the board, 
 * prompts the user to choose a type of Tetromino, and then displays the Tetromino on the board based on the user's input. 
 * The game continues until the user inputs 'q' to quit the game.
 */
public class drive1 {
	public static void main(String[] args){
		int height=24,width=24;
		/**
         * Initialize a Tetris board with height and width of 24.
         */
	    System.out.println("What is the height and width of the map?");
	    tetris_board tetris = new tetris_board(height,width);
        tetris.set_map();
        /**
         * Declare a char variable to store the type of Tetromino the user chooses.
         */
        char tetrominoType;
        /**
         * Declare a boolean variable to control the game loop.
         */
        boolean game=true;
        /**
         * Declare a char variable to store the direction the user wants to turn the Tetromino.
         */
        char direction;
        /**
         * Declare an int variable to store the count of Tetromino.
         */
        int count;
        /**
         * Declare an int variable to store the distance of Tetromino.
         */
        int distance;
        /**
         * Declare a char variable to store the location of Tetromino.
         */
        char location;
        int a = 0;
        /**
         * Declare a char array to store the types of Tetrominoes.
         */
        char [] typeArr = new char[9];
        typeArr[0]='Z';
        typeArr[1]='S';
        typeArr[2]='I';
        typeArr[3]='T';
        typeArr[4]='L';
        typeArr[5]='O';
		typeArr[6]='O';
        typeArr[7]='O';
        typeArr[8]='q';
        /**
         * Declare a char array to store the direction to turn the Tetrominoes.
         */
        char [] directionArr = new char[9];
        directionArr[0]='R';
        directionArr[1]='L';
        directionArr[2]='R';
        directionArr[3]='L';
        directionArr[4]='R';
        directionArr[5]='R';
		directionArr[6]='L';
        directionArr[7]='R';
        directionArr[8]='R';
        /**
         * Declare a char array to store the location of Tetrominoes.
         */
		char [] locationArr = new char[9];
		locationArr[0]='L';
		locationArr[1]='R';
		locationArr[2]='L';
		locationArr[3]='L';
		locationArr[4]='L';
		locationArr[5]='R';
		locationArr[6]='L';
		locationArr[7]='L';
		locationArr[8]='R';
		/**
         * Declare an int array to store the count of Tetrominoes.
         */
        int [] countArr = new int[9];
        countArr[0]=3;
        countArr[1]=5;
        countArr[2]=3;
        countArr[3]=1;
        countArr[4]=2;
        countArr[5]=6;
		countArr[6]=1;
        countArr[7]=2;
        countArr[8]=6;
        /**
         * Declare an int array to store the distance of Tetrominoes.
         */
        int [] distanceArr = new int[9];
        distanceArr[0]=3;
        distanceArr[1]=5;
        distanceArr[2]=8;
        distanceArr[3]=1;
        distanceArr[4]=6;
        distanceArr[5]=7;
		distanceArr[6]=1;
        distanceArr[7]=6;
        distanceArr[8]=7;
        /**
         * Main game loop. Continues until the user inputs 'q' to quit the game.
         */
        while(game==true){
            /**
             * Draw the current state of the Tetris board on the screen.
             */
            tetris.draw();
            /**
             * Ask the user to choose a type of Tetromino.
             */
            System.out.println("What type do you want to choose ?");
            tetrominoType = typeArr[a];
            /**
             * Validate the user's input to ensure it is a valid Tetromino type.
             */
            while(tetrominoType!='R' && tetrominoType!='L' && tetrominoType!='Z' && tetrominoType!='I' && tetrominoType!='T' && tetrominoType!='S' && tetrominoType!='J' && tetrominoType!='O' && tetrominoType!='q'){
                System.out.println("enter again");
                tetrominoType = typeArr[a];
            }
            /**
             * If the user chooses the 'R' option, randomly select a Tetromino type.
             */
            if (tetrominoType=='R'){
                Random rand =new Random();
                int random = (rand.nextInt(8));//randomly selects characters
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
            /**
             * If the user chooses 'q', set the game variable to false to exit the game loop.
             */
			if(tetrominoType == 'q'){
	            game=false;
	        }
	        else{
		        System.out.println("which way to turn?('L' or 'R')");
		        direction = directionArr[a];
		        while(direction!='R' && direction!='L'){
		        	System.out.println("enter again");
		            direction = directionArr[a];
		        }
		        System.out.println("How many how many times does it turn?");
		        count = countArr[a];
		        System.out.println("How far should it be from the center?");
		        distance = distanceArr[a]; 
		        while((tetris.get_width()/2)-1+distance>tetris.get_width()-2 && tetris.get_width()/2-1-distance<2){
		        	System.out.println("distance greater than map size!!");
		            distance = distanceArr[a];
		        }
		        System.out.println("Which region of the map would you choose?('L' or 'R')");
		        location = locationArr[a];
		        while(location!='R' && location!='L'){
		        	System.out.println("enter again");
		        	location = locationArr[a];
		        }
				/**
             	* This code is continuing to move and rotate the Tetromino on the board based on the user's input.
				* It creates a new Tetromino object called 'c1' and assigns it the type chosen by the user. 
				* It then sets the temporary position of the Tetromino, rotates it according to the user's input, and sets its final position on the board.
				*The code then checks for the position of the Tetromino and if the blocks of Tetromino are in the same row, it will move down the Tetromino until it reach to the bottom of the board.
				* If the row is completely filled with Tetromino, it will clean the row.
             	*/
		        tetrominos c1 = new tetrominos(tetrominoType);
		        c1.set_temp();
		        c1.rotate(direction,count);
		        c1.set_position();
		        tetris.set_changing_position(c1,distance,location);
		        if(tetris.get_changing_position()[3][0] == tetris.get_changing_position()[2][0] && tetris.get_changing_position()[3][0]!= tetris.get_changing_position()[1][0] && tetris.get_changing_position()[3][0]!= tetris.get_changing_position()[0][0]){
		            while(tetris.getMap()[tetris.get_changing_position()[3][0]][tetris.get_changing_position()[3][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[2][0]][tetris.get_changing_position()[2][1]]==' '){
			            tetris.addTetromino(c1);
			            tetris.move();//move down in board
			            //control cleaning
			            if(tetris.get_changing_position()[3][0]!=tetris.get_height()-1 && tetris.getMap()[tetris.get_changing_position()[3][0]][tetris.get_changing_position()[3][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[2][0]][tetris.get_changing_position()[2][1]]==' '){
			                tetris.clean_map();
			            }
			        }
		        }
		        else if(tetris.get_changing_position()[3][0] == tetris.get_changing_position()[2][0] && tetris.get_changing_position()[3][0]== tetris.get_changing_position()[1][0] && tetris.get_changing_position()[3][0]!= tetris.get_changing_position()[0][0]){
		            while(tetris.getMap()[tetris.get_changing_position()[3][0]][tetris.get_changing_position()[3][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[2][0]][tetris.get_changing_position()[2][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[1][0]][tetris.get_changing_position()[1][1]]==' '){
			            tetris.addTetromino(c1);
			            tetris.move();
			            if(tetris.get_changing_position()[3][0]!=tetris.get_height()-1 && tetris.getMap()[tetris.get_changing_position()[3][0]][tetris.get_changing_position()[3][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[2][0]][tetris.get_changing_position()[2][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[1][0]][tetris.get_changing_position()[1][1]]==' '){
			                tetris.clean_map();
			            }
			        }
		        }
		        else if(tetris.get_changing_position()[3][0] == tetris.get_changing_position()[2][0] && tetris.get_changing_position()[3][0]== tetris.get_changing_position()[1][0] && tetris.get_changing_position()[3][0]== tetris.get_changing_position()[0][0]){
		            while(tetris.getMap()[tetris.get_changing_position()[3][0]][tetris.get_changing_position()[3][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[2][0]][tetris.get_changing_position()[2][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[1][0]][tetris.get_changing_position()[1][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[0][0]][tetris.get_changing_position()[0][1]]==' '){
			            tetris.addTetromino(c1);
			            tetris.move();
			            if(tetris.get_changing_position()[3][0]!=tetris.get_height()-1 && tetris.getMap()[tetris.get_changing_position()[3][0]][tetris.get_changing_position()[3][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[2][0]][tetris.get_changing_position()[2][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[1][0]][tetris.get_changing_position()[1][1]]==' ' && tetris.getMap()[tetris.get_changing_position()[0][0]][tetris.get_changing_position()[0][1]]==' '){
			                tetris.clean_map();
			            }
			        }
		        }
		        else{
		            while(tetris.getMap()[tetris.get_changing_position()[3][0]][tetris.get_changing_position()[3][1]]==' '){
			            tetris.addTetromino(c1);
			            tetris.move();
			            if(tetris.get_changing_position()[3][0]!=tetris.get_height()-1 && tetris.getMap()[tetris.get_changing_position()[3][0]][tetris.get_changing_position()[3][1]]==' '){
			                tetris.clean_map();
			            }
		            }
		        }
	        }
			a++;
	    }
	}
}
