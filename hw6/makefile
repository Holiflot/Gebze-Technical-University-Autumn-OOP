all: clean compile run

compile: main.cpp PFArray.cpp 
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ -o test main.cpp PFArray.cpp 

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
