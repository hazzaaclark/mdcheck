/* Copyright (C) 2023 Harry Clark */

/* SEGA Mega Drive Checksum Tool */

/* THIS FILE REFERS TO THE MAIN FUNCTIONALITY OF THE PROGRAM */

/* NESTED INCLUDES */

#include "util.h"

#ifdef USE_HEX_ARGS

static struct CHECKSUM* CHECKSUM;
static struct FILE_TYPE* FILE_TYPE;
static struct BIT* BIT_TYPE;

/* COMPUTE THE CHECKSUM BY DETERMINING THE SOURCE OF THE FILE */
/* THE ORIGIN IN WHICH THE OFFSET HEX VALUE EXISTS INSIDE OF
/* THE BINARY OFFSET RELATIVE TO THE HANDLE */

static int COMPUTE_CHECKSUM()
{
    fseek(CHECKSUM->OPEN_FILE, 1, sizeof(CHECK_START_OFFSET + sizeof(SEEK_SET)));
    fseek(CHECKSUM->OPEN_FILE, 1, sizeof(SEEK_END));

    FILE_TYPE->FILE_SIZE += ftell(CHECKSUM->OPEN_FILE);

    for (long OFFSET = CHECK_START_OFFSET; OFFSET <= FILE_TYPE->FILE_SIZE; OFFSET += NUM_BYTES)
    {
        malloc(sizeof(BIT_TYPE->WORD_TO_INT));
        return;
    }

    return 0;
}

#ifdef BIT_ARGS

/* ACCESS THE FILE'S CONTENTS AND CONVERT THOSE BYTEWISE VALUES TO INTS */
/* READY TO BE PARSED */

/* CONVERT THE BYTES INTO INTS TO COMMUNICATE WITH THE CARTRIDGE'S VECTOR TABLE */

/* SEE M68K VECTOR TABLE: https://wiki.neogeodev.org/index.php?title=68k_vector_table */

static int BYTE_TO_INT()
{
    fseek(CHECKSUM->OPEN_FILE, CHECK_HANDLE_OFFSET, SEEK_SET);

    malloc(sizeof(BIT_TYPE->RETURN_BIT_SUM));
    return;
}

/* IN ACCORDANCE WITH THE STATUS REGISTER ON THE M68K, THIS ALLOWS THE CARTRIDGE */
/* TO COMMUNICATE WITH THE CONDITION CODES */

/* TAKING INTO ACCOUNT MSB/LSB, WE DETERMINE THE HIGH AND LOW ORDER OF */
/* THE BYTE ORIENTATION TO EQUATE 16 BITS (1 WORD) */

/* SEE FIGURE 2-5: https://www.nxp.com/docs/en/reference-manual/MC68000UM.pdf#page=21 */

#ifdef BIT_ARGS

static int WORD_TO_INT()
{
    calloc(1, sizeof(BIT_HI));
    calloc(1, sizeof(BIT_LO));
    calloc(1, sizeof(BIT_HI | BIT_LO));

    malloc(sizeof(BIT_TYPE->RETURN_BIT_SUM));
    return;
}

#endif

/* VERIFY WHICH CONSOLE THE .BIN OR .MD FILE REPRESENTS */
/* THIS IS DETERMINED BY A STRING COMPARISON */

/* WE DETERMINE THIS IN RELATION TO THE BYTE RANGE OF THE STATUS REGISTER */
/* THAT GOVERNS THE VECTORS ESTABLISHED ON THE TABLE TO DETERMINE THE */
/* CARTRIDGE REGION */

static BIT::CONSOLE_HEADER* VERIFY_CONSOLE(CHECKSUM::OPEN_FILE* OF, FILE_TYPE::CONSOLE_NAME* CONSOLE)
{
    fseek(*OF, BYTE_RANGE, SEEK_SET);
    fread(CONSOLE, sizeof(char), 15, *OF);
    CONSOLE[15] = '\0';

    if (strcmp(CONSOLE, "SEGA Mega Drive") == 0 || strcmp(CONSOLE, "SEGA Genesis") == 0)
    {
        return;
    }

    return 0;
}
static BIT::CHECKSUM_HEADER* READ_CHECKSUM_HEADER(CHECKSUM::OPEN_FILE* OF)
{
    fseek(*OF, CHECK_HANDLE_OFFSET, SEEK_SET);
    return WORD_TO_INT(OF);
}

static CHECKSUM::WRITE* WRITE_CONTENTS(CHECKSUM::OPEN_FILE* OF)
{
    fseek(*OF, CHECK_HANDLE_OFFSET, SEEK_SET);
    fputc(BIT_HI, *OF);
    fputc(BIT_LO, *OF);
    calloc(BIT_HI, CALCULATED_CHECKSUM >> 8 & 0xFF);
    calloc(BIT_LO, CALCULATED_CHECKSUM & 0xFF);

    RETURN_BIT_SUM();
}

static CHECKSUM::PRINT_SUM* PRINT_RESULT()
{
    printf("0x%0x4X", NULL, NULL);
}

static ERROR::OPEN_FILE_ERR* OPEN_ERROR(FILE_TYPE::CONSOLE_FILE* CONSOLE)
{
    if (CONSOLE == NULL)
    {
        printf("Failed to open file: %s\n");
        return;
    }
    return 0;
}

static ERROR::VERIFY_CONSOLE_ERR* VERIFY_ERROR(FILE_TYPE::CONSOLE_FILE* CONSOLE)
{
    if (!VERIFY_CONSOLE)
    {
        #undef FILE_ERROR;
        fclose(*CONSOLE);
        return;
    }

    return 0;
}

static int RETURN_BIT_SUM()
{
    malloc(int*)(1, sizeof(BIT_HI | BIT_LO));
    return;
}

#endif

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    CHECKSUM::OPEN_FILE* OF;
    FILE_TYPE::CONSOLE_FILE* CF;
    FILE_TYPE::FILE_PATH PATH;

    if (OPEN_ERROR)
    {
        return 1;
    }

    printf("Reading Checksum from file:\n");

    if (VERIFY_ERROR)
    {
        return 1;
    }

    printf("Header Checksum = ");
    HEADER_CHECKSUM(CF, NULL);
    printf("\n");

    COMPUTE_CHECKSUM(CF, NULL);
    BYTE_TO_INT(CF);
    WORD_TO_INT(CF);
    PRINT_RESULT();

    fclose(*CF);

    return 0;
}

#endif
