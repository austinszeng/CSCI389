#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

typedef int vec_t; // int is 4 bytes

vec_t* generate_random_list(int size);

void update_coords(vec_t* xs, vec_t* ys, vec_t* zs, vec_t* vx, vec_t* vy, vec_t* vz, int size);

int main(int argc, char *argv[]);