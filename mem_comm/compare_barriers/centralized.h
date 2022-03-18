#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct Centralized {
    int counter; // initialize to 1
    bool sense;
};

void barrier(int P);