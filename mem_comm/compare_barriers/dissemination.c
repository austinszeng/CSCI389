#include "dissemination.h"

const int rounds = ceil(log2(P));
bool flags[P][2][rounds]; // allocated in local storage per thread
local bool sense = false;
local int parity = 0;
void barrier()
{
    for (i = 0; i < rounds - 1; i++)
    {
        partner = (tid + 2 ^ i) % P;
        flags[partner][parity][i] = !sense;
        while (flags[tid][parity][i] == sense)
        { /* spin */
        }
    }
    if (parity == 1)
    {
        sense = !sense;
    }
    parity = 1 – parity;
}