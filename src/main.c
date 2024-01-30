/* COPYRIGHT (C) HARRY CLARK 2024 */

/* SEGA MEGA DRIVE CHECKSUM TOOLKIT */

/* THIS FILE PERTAINS TOWARDS THE MAINFUNCTIONALITY OF THE PROGRAM */

/* NESTED INCLUDES */

#include "util.h"

CHECKSUM CHECKSUM_ARGS;

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

    if(!IS_VALID_ROM())
    {
        printf("Not a valid SEGA Mega Drive/Genssis Rom \n");
        fclose(CHECKSUM_ARGS.OPEN_FILE);
        return EXIT_FAILURE;
    }
    
    CHECKSUM_ARGS.FILE_NAME = malloc(strlen(argv[1]) + 1);
    strcpy(CHECKSUM_ARGS.FILE_NAME, argv[1]);

    COMPUTE_CHECKSUM();

    printf("Reading Checksum...\n", CHECKSUM_ARGS.READ);
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
