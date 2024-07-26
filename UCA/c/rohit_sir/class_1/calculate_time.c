
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start_time, end_time;
    double cpu_time_used;

    // Record the start time
    start_time = clock();

    // Place your code to measure execution time here
    // For example, let's simulate some computation
    int sum = 0;
    for (int i = 1; i <= 1000000; ++i) {
        sum += i;
    }

    // Record the end time
    end_time = clock();

    // Calculate the CPU time used in seconds
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Sum: %d\n", sum);
    printf("CPU Time Used: %f seconds\n", cpu_time_used);

    return 0;
}