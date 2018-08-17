CC ?= gcc
NVCC ?= nvcc

COMPILE_FLAGS = -Wall -Wextra -g

default: product.out
gpu: product-gpu.out

product.out: product.c c-product.c
	$(CC) $+ -o $@

product-gpu.out: product.cu c-product-gpu.cu
	$(NVCC) $+ -o $@ 