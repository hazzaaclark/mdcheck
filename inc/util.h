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

#if defined(USE_HEX_ARGS)
#define USE_HEX_ARGS
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
#define SUM_LENGTH                                
#define HEADER_CHECKSUM                           0
#define CONSOLE_NAME_LENGTH 					 16

typedef struct CHECKSUM
{
	U32 COMPUTE;
	FILE* OPEN_FILE;
	void(*PRINT_SUM)();
	U32 READ;
	void(*WRITE)();
};

typedef struct FILE_TYPE
{
	FILE* CONSOLE_FILE;
    char CONSOLE_NAME;
    char FILE_PATH;
    long FILE_SIZE;

} FILE_TYPE;

#endif

#if defined(BIT_ARGS)
#define BIT_ARGS
#else
#define BIT_ARGS

#define BIT_LO                                    0
#define BIT_HI                                    1
#define NUM_BYTES                                 2

typedef struct BIT
{
	U32 BYTE_TO_INT;
	U32 WORD_TO_INT;
	U32 CHECKSUM_HEADER;
	U32 CONSOLE_HEADER[0];
	U32 RETURN_BIT_SUM;
};

#endif

#if defined(FILE_ERROR)
#define FILE_ERROR
#else
#define FILE_ERROR

typedef struct ERROR
{
	U32(*VERIFY_CONSOLE_ERR)(void);
	U32(*OPEN_FILE_ERR)(void);
	U32(*WRITE_ERR)(void);
	U32(*CHECKSUM_ERR)(void);
};

#endif

#endif
