## COPYRIGHT (C) HARRY CLARK 2024

## SEGA MEGA DRIVE CHECKSUM TOOLKIT

## THIS FILE PERTAINS TOWARDS THE BUILDING OF THE PROJECT
## PROVIDING EASE OF USE FOR COMPILATION 

CC = gcc
CFLAGS = -Iinc
DEPS = inc/common.h inc/util.h
OBJ = src/main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
