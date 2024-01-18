# mdcheck
A SEGA Mega Drive Checksum IRQ tool

This tool is to highlight the configuration I have setup to check for concurrent Checksums.
Checksums are chunks of memory that discern Error Handling on the lowest scale.

In this regard, the SEGA Mega Drive/Genesis will run a series of pre-directive checks on the ROM's respective
header file to ensure that it meets a specific criteria in order to run.

Checksums in this context are used to look for illegal instructions and or opcode malfunctions
in the process of transmission of storage and parsing of data.

# Demonstration:

### Michael Jackson's Moonwalker (Rev A).bin

![image](https://github.com/hazzaaclark/mdcheck/assets/107435091/16506654-7d11-4e4c-b445-4c10fb7beaa6)

# Buidling:

git clone this repository, change directory into the clone repo and compile from source:

``gcc main.c -o main``
``./main``

# Sources:

[M68K Vector Table](https://wiki.neogeodev.org/index.php?title=68k_vector_table)
