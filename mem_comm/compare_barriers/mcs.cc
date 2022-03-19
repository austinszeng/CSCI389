#include "mcs.hh"

using namespace std;

// This is currently the rough implementation of a tournament barrier
void barrier(int tid)
{
    int round;
    for (round = 0; // wait for children (depth == first 1)
         ((P | tid) & (1 << round)) == 0; round++)
    {
        while (flags[tid][round] != sense)
        { /* spin */
        }
    }
    if (round < log2(P))
    { // signal + wait for parent (all but root)
        int parent = tid & ~((1 << (round + 1)) - 1);
        flags[parent][round] = sense;
        while (flags[tid][round] != sense)
        { /* spin */
        }
    }
    while (round-- > 0)
    { // wake children
        int child = tid | (1 << round);
        flags[child][round] = sense;
    }
    sense = !sense;
}