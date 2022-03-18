#include "barriers.h"

// Centralized Barrier 
int counter = 1;
bool sense = false;
void cent_barrier(int P){
    bool local_sense = !sense;
    if (fetch_and_increment(&counter) == P){
        counter = 1;
        sense = local_sense;
    } else{
        while (sense != local_sense){/* spin */}
    }

}

// Dissemination Barrier
const int rounds = ceil(log2(P));
bool flags[P][2][rounds]; // allocated in local storage per thread
local bool sense = false;
local int parity = 0;
void diss_barrier() {
    for (i = 0; i < rounds-1; i++) {
        partner = (tid + 2^i) % P;
        flags[partner][parity][i] = !sense;
        while (flags[tid][parity][i] == sense)
            { /* spin */ }
    }
    if (parity == 1) {
        sense = !sense;
    }
    parity = 1 – parity;
}

// Tournament Barrier (change to fit MCS)
// for simplicity, assume P power of 2
void barrier(int tid) {
    int round;
    for (round = 0; // wait for children (depth == first 1)
            ((P | tid) & (1 << round)) == 0; round++) {
        while (flags[tid][round] != sense) { /* spin */ }
    }
    if (round < log2(P)) { // signal + wait for parent (all but root)
        int parent = tid & ~((1 << (round+1)) - 1);
        flags[parent][round] = sense;
        while (flags[tid][round] != sense) { /* spin */ }
    }
    while (round-- > 0) { // wake children
        int child = tid | (1 << round);
        flags[child][round] = sense;
    }
    sense = !sense;
}


int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Required arguments: num_threads(P)\n");
        exit(-1);
    }

    int P = atoi(argv[1]);

    return 0;
}