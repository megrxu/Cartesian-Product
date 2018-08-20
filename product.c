#include "c-product.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int count = 5;
    int elements_count = 4;
    if (argc > 1) {
        count = atoi(argv[1]);
    }

    // The sets' pointer
    unsigned char** set;
    set = (unsigned char**)malloc(count * sizeof(unsigned char*));

    // // The real sets
    int* size;
    size = (int*)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++) {
        size[i] = elements_count;
        set[i] = (unsigned char*)malloc(size[i] * sizeof(unsigned char));
        for (int j = 0; j < size[i]; j++) {
            set[i][j] = 0x11 * j;
        }
    }

    long int all = 1;
    for (int i = 0; i < count; i++) {
        all *= size[i];
    }

    printf("%ld\n", all);

    product_iterator(set, size, count, all);
}