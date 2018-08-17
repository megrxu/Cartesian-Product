#ifndef C_PRODUCT_H
#define C_PRODUCT_H

// Used to iterate the product results according to the pointer list
void product_iterator(unsigned char* set[], size_t size[], size_t count, void (*process)(unsigned char* set[], size_t index[], size_t count));

// Used to update the pointer list
void increment(size_t index[], size_t size[], size_t count);

#endif // !C_PRODUCT_H
