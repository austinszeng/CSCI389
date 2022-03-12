output: benchmarking.o
	g++
	 -Wall -Werror -Wextra -pedantic -O0 -O3 -S -g benchmarking.o -o output

benchmarking.o: benchmarking.cc
	g++ -cc benchmarking.cc

clean:
	rm *.o output