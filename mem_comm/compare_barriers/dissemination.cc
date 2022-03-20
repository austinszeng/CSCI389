#include "dissemination.hh"

using namespace std;

void dissemination(int P)
{
    const int rounds = ceil(log2(P));
    bool flags[P][2][rounds]; // allocated in local storage per thread
    bool local_sense = false;
    int local_parity = 0;
}

void barrier(int P, const int rounds, bool local_sense, int local_parity)
{
    for (int i = 0; i < rounds - 1; i++)
    {
        partner = (tid + 2 ^ i) % P;
        flags[partner][parity][i] = !local_sense;
        while (flags[tid][parity][i] == local_sense)
        { /* spin */
        }
    }
    if (local_parity == 1)
    {
        local_sense = !local_sense;
    }
    local_parity = 1 – local_parity;
}