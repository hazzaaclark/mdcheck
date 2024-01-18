/* COPYRIGHT (C) HARRY CLARK 2024 */

/* SEGA MEGA DRIVE CHECKSUM TOOLKIT */

/* THIS FILE REFERS TO THE UTILITY OF THE PROGRAM */
/* DECLARING MACROS TO HELP WITH PARSING THE DATA */
/* FOR A MEGA DRIVE ROM (.BIN OR .MD) */

#ifndef UTIL
#define UTIL

#include "common.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CHECK_INIT                                0
#define CHECK_BYTES                               2
#define CHECK_START_OFFSET                    0x200
#define CHECK_HANDLE_OFFSET                   0x18E
#define CHECK_MASK                            65535
#define BYTE_RANGE                            0x100
#define CALCULATED_CHECKSUM                       0
#define SUM_LENGTH                                1
#define HEADER_CHECKSUM                           0
#define CONSOLE_NAME_LENGTH 					 16

#define     EXIT_SUCCESS                          0
#define     EXIT_FAILURE                          1

typedef struct CHECKSUM
{
    U16 LENGTH;
	U32 COMPUTE;
	FILE* OPEN_FILE;
	void(*PRINT_SUM)(void);
	U32 READ;
	void(*WRITE)(void);

} CHECKSUM;

#endif
