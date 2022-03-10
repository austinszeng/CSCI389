- learn how to push and pull on github to work on multiple devices
- compile with flags to catch errors and debug: gcc -Wall -Werror -Wextra -pedantic -O0 -g
- compile: gcc -flags -filename.c -o outputname

- Two main function formats

  - int main (void) { body }
  - int main (int argc, char \*argv[]) { body }
    - argc is the number of arguments
    - argv is an array of pointers to character arrays of the arguments
      - first argument is the name of the binary
    - Return value is 0 or EXIT_SUCCESS for success, EXIT_FAILURE (different #) for failure

- Variables are defined at the start of functions in C, then initialization

  - definition with initialization is ok (int a = 10) as long as its not like int a = b + c

- Array Allocation

  - statically sized arrays can be allocated like normal vars
    ex) int c[5]
  - dynamically sized arrays must be allocated on the heap
    ex) float f[b]
    - memory allocation with malloc and calloc
      - both allocate bytes, but calloc sets all bytes to 0
      - for every allocation, there must be a corresponding free

- Stack vs Heap

  - Stack
    - where default variable allocation occurs
    - data is assigned on a per-function basis
    - size must be known ahead of time
    - variables disappear on function completion
  - Heap
    - specifically managed
    - size specified when allocated
    - can reallocate and change pointers
    - data stays alive until freed
    - unfreed data can cause memory leaks

-
