CC ?= gcc

SOURCES = main.c

default: all

all: main.c
	${CC} $+ -o product.out -Wall -Wextra -g