# Comparing Barriers
## Program Overview:
- Implement the following barriers: 
    1. Centralized Barrier
    2. Dissemination Barrier
    3. MCS Barrier
- The barriers should take as input the number of threads that will synchronize upon creation
- When running an instance of the barrier, you should take as input the thread ID of the thread calling the barrier function

## Implementation
- The timing method I am to measure the latency of reading a byte from memory of a buffer is the C library function clock_t clock()
- In order to obtain a measureable amount of time, each buffer of N bytes is iterated 100000 times with there being four reads/ copies of a byte per iteration
- Since I am using a list of ints as the buffer, a buffer of N bytes actually only has N/4 ints in the list and this is accounted for in the calculations of mean latency time

## Mean Latency per Memory Read (ns) vs. Buffer Size (KB) Graph
![Graph](graph.JPG)
- This data was collected using the buffer sizes (KB) of 1, 10, 100, and 1000

## Analysis
| CPU Caches    | Size              |
| ------------- |:-----------------:|
| L1            | 64 KB (per core)  |
| L2            | 256 KB (per core) |
| L3            | 12 MB (shared)    |
