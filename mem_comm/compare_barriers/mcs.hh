#pragma once

#include <cmath>

typedef struct
{
    uint8_t parentsense;
    uint8_t *parent;
    uint8_t *children[2];

    union
    {
        uint8_t single[4];
        uint32_t all;
    } havechild;

    union
    {
        uint8_t single[4];
        uint32_t all;
    } childnotready;

    uint8_t sense;
    uint8_t dummy;
    unsigned int id;
} thread_t;

struct MCS
{
};

void barrier(int tid);