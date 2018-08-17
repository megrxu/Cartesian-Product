#include <string.h>
#include <stdlib.h>
#include "c-product.h"

void product_iterator(unsigned char* set[], size_t size[], size_t count, void (*process)(unsigned char* set[], size_t index[], size_t count))
{
    size_t all = 1;
    for (size_t i = 0; i < count; i++) {
        all *= size[i];
    }
    size_t* index;
    index = (size_t*)malloc(sizeof(size_t) * count);
    memset(index, 0x00, sizeof(size_t) * count);
    for (size_t i = 0; i < all; i++) {
        (*process)(set, index, count);
        increment(index, size, count);
    }
}

void increment(size_t index[], size_t size[], size_t count)
{
    if (index[count - 1] == size[count - 1] - 1) {
        index[count - 1] = 0;
        increment(index, size, count - 1);
    } else {
        index[count - 1]++;
    }
}