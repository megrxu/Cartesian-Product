#include "c-product.h"
#include <stdio.h>
#include <string.h>

void process(unsigned char* set[], size_t index[], size_t count);

int main()
{
    unsigned char rset[16][8];
    memset(rset[0], 0, sizeof(unsigned char) * 10 * 8);

    unsigned char* set[16] = {
        rset[0], rset[1], rset[2], rset[3],
        rset[4], rset[6], rset[6], rset[7],
        rset[8], rset[9], rset[10], rset[11],
        rset[12], rset[13], rset[14], rset[15]
    };
    size_t size[16] = { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 };

    product_iterator(set, size, 10, process);
}

void process(unsigned char* set[], size_t index[], size_t count)
{
    // for (size_t i = 0; i < count; i++) {
    //     printf("%x ", set[i][index[i]]);
    // }
    // printf("\n");
    return;
}
