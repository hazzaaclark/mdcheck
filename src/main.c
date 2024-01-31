/* COPYRIGHT (C) HARRY CLARK 2024 */

/* SEGA MEGA DRIVE CHECKSUM TOOLKIT */

/* THIS FILE PERTAINS TOWARDS THE MAINFUNCTIONALITY OF THE PROGRAM */

/* NESTED INCLUDES */

#include "util.h"

CHECKSUM CHECKSUM_ARGS;

/* COMPUTE THE CHECKSUM BY DETERMINING THE SOURCE OF THE FILE */
/* THE ORIGIN IN WHICH THE OFFSET HEX VALUE EXISTS INSIDE OF
/* THE BINARY OFFSET RELATIVE TO THE HANDLE */

int COMPUTE_CHECKSUM()
{
    fseek(CHECKSUM_ARGS.OPEN_FILE, CHECK_START_OFFSET, SEEK_SET);
    while (fread(&CHECKSUM_ARGS.LENGTH, sizeof(CHECKSUM_ARGS.LENGTH), 1, CHECKSUM_ARGS.OPEN_FILE))
    {
        CHECKSUM_ARGS.COMPUTE += CHECKSUM_ARGS.LENGTH;
    }

    CHECKSUM_ARGS.COMPUTE &= CHECK_MASK;
    return EXIT_SUCCESS;
    return 0;
}

void FIX_CHECKSUM(void)
{
    fseek(CHECKSUM_ARGS.OPEN_FILE, CHECK_HANDLE_OFFSET, SEEK_SET);
    fwrite((&CHECKSUM_ARGS.COMPUTE), sizeof(CHECKSUM_ARGS.COMPUTE), 1, CHECKSUM_ARGS.OPEN_FILE);
}

void PRINT_CHECKSUM(void)
{
    if(CHECKSUM_ARGS.READ == CHECKSUM_ARGS.COMPUTE)
        printf("Checksum Correct\n");
    else
        FIX_CHECKSUM();
        printf("Checksum Fixed\n");
}

bool IS_ROM_VALID(FILE* rom)
{
    char *name = (char*)malloc(CONSOLE_NAME_LENGTH+1);

    fseek(rom, SYSTEM_TYPE_OFFSET, SEEK_SET);
    fread(name, CONSOLE_NAME_LENGTH, 1, rom);
    name[CONSOLE_NAME_LENGTH] = '\0';

    /* Only the SEGA name matters in checking if a ROM is valid */
    char expected[] = "SEGA";
    for (size_t i = 0; i < sizeof(expected) - 1; i++) {
        if (name[i] != expected[i]) {
            free(name);
            return false;
        }
    }

    free(name);
    return true;
}

int main(int argc, char* argv[])
{
    fputs
    (
        "--------------------------------------\n"
        "--------------------------------------\n"
        "MEGA DRIVE CHECKSUM TOOL - Harry Clark\n"
        "--------------------------------------\n"
        "--------------------------------------\n"
        ,stdout);

    /* READ THE CONTENTS OF THE FILE */
    /* RUN ERROR CHECKS TO DETERMINE IF THE FILE IS PROVIDED OR NOT */

    CHECKSUM_ARGS.OPEN_FILE = fopen(argv[1], "r+b");
    if (CHECKSUM_ARGS.OPEN_FILE == NULL)
    {
        printf("Could not open file, please provide a path at the end of the execution\n", argv[1]);
        return EXIT_FAILURE;
    }

    CHECKSUM_ARGS.FILE_NAME = malloc(strlen(argv[1]) + 1);
    strcpy(CHECKSUM_ARGS.FILE_NAME, argv[1]);

    if (!IS_ROM_VALID(CHECKSUM_ARGS.OPEN_FILE))
    {
        printf("Invalid or corrupt rom\n");
        return EXIT_FAILURE;
    }

    COMPUTE_CHECKSUM();

    printf("Read Checksum\n", CHECKSUM_ARGS.READ);
    printf("Found Checksum: 0x%x\n", CHECKSUM_ARGS.COMPUTE);

    if (CHECKSUM_ARGS.READ == CHECKSUM_ARGS.COMPUTE)
    {
        printf("Checksum correct!\n");
    }
    else
    {
        FIX_CHECKSUM();
        printf("Checksum Computed!\n");
    }

    free(CHECKSUM_ARGS.FILE_NAME);
    fclose(CHECKSUM_ARGS.OPEN_FILE);
    return EXIT_SUCCESS;
}
