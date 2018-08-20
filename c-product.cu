#include "c-product.cuh"
#include <stdio.h>
#include <stdlib.h>

__global__
void product_iterator(unsigned char* set[], int size[], int count, long int all)
{
    int *index;
    index = (int *)malloc(count * sizeof(int));

    int *delta;
    delta = (int *)malloc(count * sizeof(int));

    // Block and thread params
    long int init = blockIdx.x * blockDim.x + threadIdx.x;
    int stride = blockDim.x * gridDim.x;
    updateIndex(delta, size, count, stride, all);
    updateIndex(index, size, count, init, all);

    for (long int i = init; i < all; i+= stride) {
        // update the index according to the blockDim.x and gridDim.x
        // process the subkeys
        for (int j = 0;j < count; j++){
            set[j][index[j]] += index[j];
        }
        // printf("\n");
        // printf("%d", i);
        if (i + stride < all){
            increment(index, size, count, delta);
        }
    }

    free(index);
    return;
}

__device__
void updateIndex(int index[], int size[], int count, long int num, long int all){
    long int weight = all;
    for (int i = 0; i < count; i++){
        weight /= size[i];
        index[i] = num / weight;
        num -= index[i] * weight;
    }
}

__device__
void increment(int index[], int size[], int count, int delta[]){
    for (int i = count-1; i >= 0; i--){
        index[i] += delta[i];
        while(index[i] >= size[i]){
            index[i] -= size[i];
            index[i-1]++;
        }
    }
}