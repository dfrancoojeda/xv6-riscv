#include <stdio.h>
#include <stdint.h>

void foo()
{
    // Function intended for modification
}

int main()
{
    printf("Attempting to modify code segment...\n");

    // Obtain address of the function foo
    char *code = (char *)&foo;

    // Attempt to modify the first byte of the function
    *code = 0x90; // Example: writing a NOP instruction

    printf("Modification attempted. Check for errors.\n");

    return 0;
}