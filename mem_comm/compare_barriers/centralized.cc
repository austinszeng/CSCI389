#include "centralized.hh"

#include <atomic>

using namespace std;

void centralized(int P)
{
    int count = P;
    bool global_sense = true;
    bool local_sense = true;
    barrier(P, count, global_sense, local_sense);
}

void barrier(int P, int count, bool global_sense, bool local_sense)
{
    atomic<int> counter(count);
    local_sense = !local_sense;
    if (atomic_fetch_sub(&counter, 1) == 1)
    {
        counter = P;
        global_sense = local_sense;
    }
    else
    {
        while (global_sense != local_sense)
        { /* spin */
        }
    }
}