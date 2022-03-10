#include "update_locations.h"

// Create a list of 'size' floating point numbers in the range [-bound, bound]
vec_t* generate_random_list(int size, int bound){
	vec_t* ls = (vec_t*) malloc(size * sizeof(vec_t));
	for(int i = 0; i < size; i++){
		ls[i] = (rand() % (2 * bound + 1)) - bound;
	}
	return ls;
}

// Update position by velocity, one time-step
// Use size as a variable since len(xs) = size
void update_coords(vec_t* xs, vec_t* ys, vec_t* zs, vec_t* vx, vec_t* vy, vec_t* vz, int size){
	for(int i = 0; i < size; i++){
		xs[i] = xs[i] + vx[i];
		ys[i] = ys[i] + vy[i];
		zs[i] = zs[i] + vz[i];
	}
}

// Replicates sum() command in Python
vec_t sum(vec_t* arr, int size){
	vec_t total = 0;
	for(int i = 0; i < size; i++){
		total += arr[i];
	}
	return total;
}

/////////////// Main:
int main(int argc, char** argv){
	
	if(argc != 3){
		printf("Required arguments: vector_length(N) and iterations_num(M)\n");
		exit(-1);
	}

	int size = atoi(argv[1]); 
	int iters = atoi(argv[2]); 
    srand(size); //seed the RNG used by rand()
	vec_t* xs = generate_random_list(size, 1000);
	vec_t* ys = generate_random_list(size, 1000);
	vec_t* zs = generate_random_list(size, 1000);
	vec_t* vx = generate_random_list(size, 1);
	vec_t* vy = generate_random_list(size, 1);
	vec_t* vz = generate_random_list(size, 1);

    double total_time = 0;
    for(int i = 0; i < iters; i++){
        clock_t start = clock();
        update_coords(xs, ys, zs, vx, vy, vz, size);
        clock_t end = clock();
        double time_taken = (end-start + 0.0)/CLOCKS_PER_SEC; 
        total_time += time_taken;
    }

	vec_t chksum = sum(xs, size) + sum(ys, size) + sum(zs, size);
	printf("Mean time per coordinate: %f us\n", (1000000 * total_time) / (size * iters)); 
	printf("Final checksum is: %f\n", chksum);
	free(xs); free(ys); free(zs); free(vx); free(vy); free(vz);
	exit(0);
}