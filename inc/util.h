/* Copyright (C) 2023 Harry Clark */

/* SEGA Mega Drive Checksum Tool */

/* THIS FILE REFERS TO THE UTILITY OF THE PROGRAM */
/* DECLARING MACROS TO HELP WITH PARSING THE DATA */
/* FOR A MEGA DRIVE ROM (.BIN OR .MD) */

#ifndef UTIL
#define UTIL

/* NESTED INCLUDES */

#include "common.h"

/* SYSTEM INCLUDES */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>

#if defined(USE_ARGS)
#define USE_ARGS
#else
#define USE_HEX_ARGS

#define CHECK_INIT                                0
#define CHECK_BYTES                               2
#define CHECK_START_OFFSET                    0x200
#define CHECK_HANDLE_OFFSET                   0x18E
#define CHECK_MASK                            65535
#define SEEK_SET                               0x00
#define SEEK_END                               0x02
#define BYTE_RANGE                            0x100
#define CALCULATED_CHECKSUM                       0

#define SUM_LENGTH                                \
unsigned WORD

typedef struct CHECKSUM
{
	typedef U32(*COMPUTE)();
	typedef FILE* OPEN_FILE;
	typedef void(*PRINT_SUM)(SUM_LENGTH);
};

typedef struct FILE_TYPE
{
	static char CONSOLE_NAME[16];
	static char FILE_PATH;
	typedef long FILE_SIZE;
};

#endif

#if defined(BIT_ARGS)
#define BIT_ARGS
#else
#define BIT_ARGS

#define BIT_LO                                    0
#define BIT_HI                                    1
#define NUM_BYTES                                 2
#define BIT_SUM                     BIT_HI | BIT_LO

typedef struct BIT
{
	typedef U32 BYTE_TO_INT();
	typedef U32 WORD_TO_INT();
	typedef U32 CHECKSUM_HEADER();
	typedef U32 CONSOLE_HEADER();
};

#endif

#endif
#endif
