
import java.util.Scanner;
import java.util.Random;
public class drive2 {
	public static void main(String[] args){
		int height,width;
		Scanner scan = new Scanner(System.in);	
	    System.out.println("What is the height and width of the map?");
	    height = scan.nextInt();
	    width = scan.nextInt();
	    tetris_board tetris = new tetris_board(height,width);
	    tetris.set_map();
	    char tetrominoType;
	    boolean game=true;
	    char direction;
	    int count;
	    int distance;
	    char location;
	    while(game==true){
	        tetris.draw();
	        System.out.println("What type do you want to choose ?");
	        tetrominoType = scan.next().charAt(0);
	        while(tetrominoType!='R' && tetrominoType!='L' && tetrominoType!='Z' && tetrominoType!='I' && tetrominoType!='T' && tetrominoType!='S' && tetrominoType!='J' && tetrominoType!='O' && tetrominoType!='q'){
	        	System.out.println("enter again");
	            tetrominoType = scan.next().charAt(0);
	        }
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
	        if(tetrominoType == 'q'){
	            game=false;
	        }
	        else{
		        System.out.println("which way to turn?('L' or 'R')");
		        direction = scan.next().charAt(0);
		        while(direction!='R' && direction!='L'){
		        	System.out.println("enter again");
		            direction = scan.next().charAt(0);
		        }
		        System.out.println("How many how many times does it turn?");
		        count = scan.nextInt();
		        System.out.println("How far should it be from the center?");
		        distance = scan.nextInt(); 
		        while((tetris.get_width()/2)-1+distance>tetris.get_width()-2 && tetris.get_width()/2-1-distance<2){
		        	System.out.println("distance greater than map size!!");
		            distance = scan.nextInt();
		        }
		        System.out.println("Which region of the map would you choose?('L' or 'R')");
		        location = scan.next().charAt(0);
		        while(location!='R' && location!='L'){
		        	System.out.println("enter again");
		        	location = scan.next().charAt(0);
		        }
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
	    }
	    scan.close();
	}
}
