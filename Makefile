all:
	gcc src/neural_network.c -o bin/executable
run: # compile and run
	./bin/executable
debug:
	
	valgrind --leak-check=full ./bin/executable
