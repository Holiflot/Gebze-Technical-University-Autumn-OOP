all: clean compile run

compile: main.cpp Tetrominos.cpp Tetrominos.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ -o test main.cpp Tetrominos.cpp

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	./test
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
