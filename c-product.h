#ifndef C_PRODUCT_H
#define C_PRODUCT_H

#include <stdlib.h>

// Used to iterate the product results according to the pointer list
void product_iterator(unsigned char* set[], int size[], int count, long int all);

// Used to update the pointer list
void updateIndex(int index[], int size[], int count, long int num, long int all);
void increment(int index[], int size[], int count, int delta[]);

#endif // !C_PRODUCT_H
