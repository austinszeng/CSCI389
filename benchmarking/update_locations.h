#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef float vec_t;

vec_t* generate_random_list(int size, int bound);

void update_coords(vec_t* xs, vec_t* ys, vec_t* zs, vec_t* vx, vec_t* vy, vec_t* vz, int size);

vec_t sum(vec_t* arr, int size);

int main(int argc, char** argv);


