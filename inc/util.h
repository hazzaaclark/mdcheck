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
#include <cstdio>

#if defined(USE_ARGS)
#define USE_ARGS
#else
#define USE_ARGS

#define CHECK_INIT                             0
#define CHECK_START_OFFSET                 0x200
#define CHECK_HANDLE_OFFSET                0x18E
#define CHECK_MASK                         65535
#define CHECK_BYTES                            2

#endif

#endif