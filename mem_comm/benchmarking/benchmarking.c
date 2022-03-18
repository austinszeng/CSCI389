#include "benchmarking.h"

// Create a list of 'size' ints within range of INT_MAX
vec_t* generate_random_list(int size){
    int byte_size = floor(size/4); // int is 4 bytes, but buffer is N bytes
	vec_t* ls = (vec_t*) malloc(byte_size * sizeof(vec_t));
	for(int i = 0; i < byte_size; i++){
		ls[i] = (rand() % INT_MAX);
	}
	return ls;
}

/////////////// Main:
int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Required arguments: buffer_length(N)\n");
        exit(-1);
    }

    int size = atoi(argv[1]);
    srand(size); //seed the RNG used by rand()

    printf("Buffer Length:  Mean time per coordinate (us):\n");
    // Vary buffer size to compare how that impacts the latency
    for (int i = 0; i < 4; i++){
        vec_t* buffer = generate_random_list(size);

        // Timing 
        // use to choose random int from buffer
        int max_buffer_size = floor(size/4);
        int ind_0 = rand() % max_buffer_size; 
        int ind_1 = rand() % max_buffer_size;
        int ind_2 = rand() % max_buffer_size;
        int ind_3 = rand() % max_buffer_size;
        vec_t w, x, y, z;
        double total_time = 0;
        int iters = 100000;
        for (int i = 0; i < iters; i++){
            clock_t start = clock();
            w = buffer[ind_0];
            x = buffer[ind_1];
            y = buffer[ind_2];
            z = buffer[ind_3];
            clock_t end = clock();
            double time_taken = (end-start + 0.0)/CLOCKS_PER_SEC; 
            total_time += time_taken;
        }

        // divide by 16 because copied 4 times and each copy is 4 bytes, not 1
        double mean_time_0 = (1000000 * total_time) / (size * iters);
        double mean_time = mean_time_0 / 16;
        printf("%13i   %f\n", size, mean_time); 
        size = size * 10;

        free(buffer); // free memory
    }
    
    exit(0);
}