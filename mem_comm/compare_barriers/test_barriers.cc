#include "test_barriers.hh"

#include <cmath>
#include <thread>

void centralized()
{
    /* test barrier */
}

void dissemination()
{
    /* test barrier */
}

void mcs()
{
    /* test barrier */
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Required arguments: num_threads(P)\n");
        exit(-1);
    }

    int P = atoi(argv[1]);

    // Testing
    centralized();
    dissemination();
    mcs();

    return 0;
}