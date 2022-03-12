#include "benchmarking.hh"

#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Required arguments: buffer_length(N)\n");
        exit(-1);
    }
    int N = atoi(argv[1]);

    char *buffer = new char[N];

    // timing stuff
    for (int i = 0; i < N; i++)
    {
        auto start = chrono::steady_clock::now();
        // do stuff (time to copy a single byte from the buffer)
        char firstByte = buffer[0];
        auto length_buffer = 0;
        auto end = chrono::steady_clock::now();
        cout << length_buffer << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
    }

    // free memory
    delete[] buffer;
    return 0;
}