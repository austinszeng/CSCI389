#pragma once

#include <cmath>

typedef struct
{
    bool mine;
    bool *partner;
} flags_t;

typedef struct
{
    flags_t flags;

    bool sense;
    unsigned int parity;
} thread_t;

void dissemination(int P);