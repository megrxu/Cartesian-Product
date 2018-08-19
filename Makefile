CC ?= gcc
NVCC ?= nvcc

COMPILE_FLAGS = -Wall -Wextra -g
NVCC_FLAGS = -arch compute_35 -rdc=true

default: product.out
gpu: product-gpu.out

product.out: product.c c-product.c
	$(CC) $(COMPILE_FLAGS) $+ -o $@

product-gpu.out: product.cu c-product.cu
	$(NVCC) $(NVCC_FLAGS) $+ -o $@