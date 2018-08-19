#ifndef C_PRODUCT_CUH
#define C_PRODUCT_CUH

__global__
void product_iterator(unsigned char* set[], int size[], int count, long int all);

// Used to update the pointer list
__global__
void updateIndex(int index[], int size[], int count, long int num, long int all);

#endif // !C_PRODUCT_CUDA_H
