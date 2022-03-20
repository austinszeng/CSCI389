#include "benchmarking.hh"
#include <iostream>
#include <chrono>
using namespace std;

vec_t* generate_string(int size, char letter){
    vec_t* string_buffer = new char[size];
    for (int i = 0; i < size; i++){
        string_buffer[i] = 'a';
    }
	return string_buffer;
}

/////////////// Main:
int main(int argc, char *argv[]){

    if (argc != 2){
        cout << "Required arguments: buffer_length(N)\n";
        exit(-1);
    }

    int size = atoi(argv[1]);
    int size_copy = size;
    srand(size); //seed the RNG used by rand()

    cout << "Buffer Length:  Mean time per coordinate (us):\n";

    // Vary buffer size to compare how that impacts the latency
    for (int i = 0; i < 4; i++){
        vec_t* buffer = generate_string(size, 'a');
        // Timing 
        vec_t x;
        double total_time = 0;
        int iters = 10;
        for (int i = 0; i < iters; i++){
            auto start = chrono::steady_clock::now();
            x = buffer[1];
            x = buffer[2];
            x = buffer[3];
            x = buffer[4];
            auto end = chrono::steady_clock::now();
            double time_taken = (chrono::duration_cast<chrono::nanoseconds>(end - start).count())/4;
            total_time += time_taken;
        }

        double mean_time = (total_time) / (iters);
        
        cout << size << "           " << mean_time << "\n"; 
        size = size * 10;

        free(buffer); // free memory
    }
    
    exit(0);
}