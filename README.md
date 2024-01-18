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

![image](https://github.com/hazzaaclark/mdcheck/assets/107435091/7fad2dce-6893-4ea2-9095-ea7fbafc3ec0)

### Sonic the Hedgehog (USA, Europe).bin

![image](https://github.com/hazzaaclark/mdcheck/assets/107435091/4b584cd8-998d-440e-a4d2-cfa121303d76)


# Buidling:

git clone this repository, change directory into the clone repo and compile from source:

``gcc main.c -o main``
``./main``

build instructions have changed slightly.
Rather than providing the ROM as an in-code parameter, you can now attach it onto the end of the execution

``./main \PATH\TO\MD\ROM\ROM_NAME.bin``

- see above image for guidance on the formatting

# Sources:

[M68K Vector Table](https://wiki.neogeodev.org/index.php?title=68k_vector_table)
