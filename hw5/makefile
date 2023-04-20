all: clear driver2 driver1 

clear:
	@clear

driver2:
	@g++ driver2.cpp Tetromino.cpp AbstractTetris.cpp TetrisVector.cpp TetrisArray1D.cpp TetrisAdapter.cpp -o main1.out
	@./main1.out

driver1:
	@g++ driver1.cpp Tetromino.cpp AbstractTetris.cpp TetrisVector.cpp TetrisArray1D.cpp TetrisAdapter.cpp -o main2.out
	@./main2.out

