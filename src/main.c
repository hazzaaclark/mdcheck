/* COPYRIGHT (C) HARRY CLARK 2024 */

/* SEGA MEGA DRIVE CHECKSUM TOOLKIT */

/* THIS FILE PERTAINS TOWARDS THE MAINFUNCTIONALITY OF THE PROGRAM */

/* NESTED INCLUDES */

#include "util.h"

CHECKSUM CHECKSUM_ARGS;

/* COMPUTE THE CHECKSUM BY DETERMINING THE SOURCE OF THE FILE */
/* THE ORIGIN IN WHICH THE OFFSET HEX VALUE EXISTS INSIDE OF
/* THE BINARY OFFSET RELATIVE TO THE HANDLE */

static
int COMPUTE_CHECKSUM()
{
    fseek(CHECKSUM_ARGS.OPEN_FILE, CHECK_START_OFFSET, SEEK_SET);
    while (fread(&CHECKSUM_ARGS.LENGTH, sizeof(CHECKSUM_ARGS.LENGTH), 1, CHECKSUM_ARGS.OPEN_FILE))
    {
        CHECKSUM_ARGS.COMPUTE += CHECKSUM_ARGS.LENGTH;
    }

    CHECKSUM_ARGS.COMPUTE &= CHECK_MASK;
    return 0;
}

/* FIX THE CHECKSUM ASSUMING THAT THE READER OFFSET IS OUT OF PLACE */
/* OR IF THE CURRENT CHECKSUM OF THE ROM DUMP DOESN'T MATCH */

static
void FIX_CHECKSUM(void)
{
    fseek(CHECKSUM_ARGS.OPEN_FILE, CHECK_HANDLE_OFFSET, SEEK_SET);
    fwrite(&(CHECKSUM_ARGS.COMPUTE), sizeof(CHECKSUM_ARGS.COMPUTE), 1, CHECKSUM_ARGS.OPEN_FILE);
}

/* A FUNCTION TO MODULARISE THE CODE TO MAKE MAIN NOT AS CLUTTERED */
/* THIS IS FOR PRINTING THE FINAL AND FIXED CHECKSUM */

static
void PRINT_CHECKSUM(void)
{
    if(CHECKSUM_ARGS.READ == CHECKSUM_ARGS.COMPUTE)
        printf("Checksum Correct\n");
    else
        FIX_CHECKSUM();
        printf("Checksum Fixed\n");
}

int main(int argc, char* argv[]) 
{
    /* READ THE CONTENTS OF THE FILE */
    /* RUN ERROR CHECKS TO DETERMINE IF THE FILE IS PROVIDED OR NOT */ 

    CHECKSUM_ARGS.OPEN_FILE = fopen(argv[1], "r+b");
    if (CHECKSUM_ARGS.OPEN_FILE == NULL) 
    {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    COMPUTE_CHECKSUM();

    printf("Read Checksum\n", CHECKSUM_ARGS.READ);
    printf("Found Checksum: %x\n", CHECKSUM_ARGS.COMPUTE);

    if (CHECKSUM_ARGS.READ == CHECKSUM_ARGS.COMPUTE) 
    {
        printf("Checksum correct!\n");
    }

    else 
    {
        FIX_CHECKSUM();
        printf("Checksum Computed!\n");
    }

    fclose(CHECKSUM_ARGS.OPEN_FILE);
    return 0;
}
