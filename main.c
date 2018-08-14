#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void product_iterator(unsigned char* set[], size_t size[], size_t count);
void _product_iterator(unsigned char* set[], size_t index[], size_t count);
void increment(size_t index[], size_t size[], size_t count);

int main()
{
    unsigned char rset[3][3] = {
        { 0x11, 0x22, 0x33 },
        { 0x44, 0x55, 0x66 },
        { 0x77, 0x88, 0x99 }
    };

    unsigned char* set[3] = { rset[0], rset[1], rset[2] };
    size_t size[3] = { 3, 2, 3 };

    product_iterator(set, size, 3);
}

void product_iterator(unsigned char* set[], size_t size[], size_t count)
{
    size_t all = 1;
    for (size_t i = 0; i < count; i++) {
        all *= size[i];
    }
    size_t* index;
    index = (size_t*)malloc(sizeof(size_t) * count);
    memset(index, 0x00, sizeof(size_t) * count);
    for (size_t i = 0; i < all; i++) {
        _product_iterator(set, index, count);
        increment(index, size, count);
    }
}

void _product_iterator(unsigned char* set[], size_t index[], size_t count)
{
    for (size_t i = 0; i < count; i++) {
        printf("%x ", set[i][index[i]]);
    }
    printf("\n");
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