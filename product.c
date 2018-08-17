#include <stdio.h>
#include <string.h>
#include "c-product.h"

void process(unsigned char* set[], size_t index[], size_t count);

int main()
{
    unsigned char rset[3][3] = {
        { 0x11, 0x22, 0x33 },
        { 0x44, 0x55, 0x66 },
        { 0x77, 0x88, 0x99 }
    };

    unsigned char* set[3] = { rset[0], rset[1], rset[2] };
    size_t size[3] = { 3, 2, 3 };

    product_iterator(set, size, 3, process);
}

void process(unsigned char* set[], size_t index[], size_t count)
{
    for (size_t i = 0; i < count; i++) {
        printf("%x ", set[i][index[i]]);
    }
    printf("\n");
}
