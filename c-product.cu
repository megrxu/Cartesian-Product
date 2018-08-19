#include "c-product.cuh"
#include <stdio.h>

__global__
void product_iterator(unsigned char* set[], int size[], int count, long int all)
{
    int *index;
    index = (int *)malloc(count * sizeof(int));

    // Block and thread params
    long int init = blockIdx.x * blockDim.x + threadIdx.x;
    int stride = blockDim.x * gridDim.x;

    // init the index list
    long int num = init;
    updateIndex<<<1, 1>>>(index, size, count, num, all);

    for (int i = 0; i < all; i++) {
        // process the subkeys
        for (int j = 0;j < count; j++){
            // do something;
        }
        // update the index according to the blockDim.x and gridDim.x
        num += stride;
        updateIndex<<<1, 1>>>(index, size, count, num, all);

        // update the index list
        i = all;
    }

    free(index);
    return;
}

__global__
void updateIndex(int index[], int size[], int count, long int num, long int all){
    long int weight = all;
    for (int i = 0; i < count; i++){
        weight /= size[i];
        index[i] = num / weight;
        num -= index[i] * weight;
    }
}