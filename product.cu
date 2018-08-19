#include "c-product.cuh"
#include <stdio.h>

#define THREADS 256
#define BLOCKS 16

int main()
{
    int count = 15;
    int elements_count = 4;

    // The sets' pointer
    unsigned char **set;
    cudaMallocManaged(&set, count * sizeof(unsigned char *));

    // // The real sets
    int* size;
    cudaMallocManaged(&size, count * sizeof(int));

    for (int i = 0;i < count; i++){
        size[i] = elements_count;
        cudaMallocManaged(&(set[i]), size[i] * sizeof(unsigned char));
        for (int j = 0; j < size[i]; j++){
            set[i][j] = 0x11 * j;
        }
    }

    long int all = 1;
    for (int i = 0; i < count; i++) {
        all *= size[i];
    }

    printf("%ld\n", all);

    product_iterator<<<BLOCKS, THREADS>>>(set, size, count, all);
    cudaDeviceSynchronize();

    // Free memory
    for (int i = 0;i < count; i ++){
        cudaFree(set[i]);
    }
    cudaFree(set);
}