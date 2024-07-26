#include<time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Record the start memory usage
    struct rusage usage_start;
    getrusage(RUSAGE_SELF, &usage_start);

    // Place your code to measure memory usage here
    // For example, let's allocate some memory
    int *array = (int *)malloc(1000000 * sizeof(int));

    // Record the end memory usage
    struct rusage usage_end;
    getrusage(RUSAGE_SELF, &usage_end);

    // Calculate memory usage in kilobytes
    long memory_used = usage_end.ru_maxrss - usage_start.ru_maxrss;

    printf("Memory Used: %ld KB\n", memory_used);

    // Free the allocated memory
    free(array);

    return 0;
}