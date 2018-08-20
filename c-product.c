#include "c-product.h"
#include <stdio.h>
#include <string.h>

void product_iterator(unsigned char* set[], int size[], int count, long int all)
{
    int* index;
    index = (int*)malloc(sizeof(int) * count);
    int* delta;
    delta = (int*)malloc(sizeof(int) * count);

    updateIndex(index, size, count, 0, all);
    updateIndex(delta, size, count, 1, all);
    index[count - 1] = -1;

    for (int i = 0; i < all; i++) {
        // update the index
        increment(index, size, count, delta);
        for (int j = 0; j < count; j++) {
            set[j][index[j]] += index[j];
            // do something;
        }
    }
    free(index);
    free(delta);
}

void updateIndex(int index[], int size[], int count, long int num, long int all)
{
    long int weight = all;
    for (int i = 0; i < count; i++) {
        weight /= size[i];
        index[i] = num / weight;
        num -= index[i] * weight;
    }
}

void increment(int index[], int size[], int count, int delta[])
{
    for (int i = count - 1; i >= 0; i--) {
        index[i] += delta[i];
        while (index[i] >= size[i]) {
            index[i] -= size[i];
            index[i - 1]++;
        }
    }
}