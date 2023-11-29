#include "kernel/types.h"
#include "user/user.h"

int main(void)
{
    char *data = sbrk(4096); // Allocate one page of memory

    // Protect the page
    mprotect(data, 1);

    // Unprotect the page
    if (munprotect(data, 1) == -1)
    {
        printf("munprotect failed\n");
        exit(1);
    }

    printf("Attempting to write to unprotected page\n");
    data[0] = 'A'; // This should be successful

    printf("Write successful\n");
    exit(0);
}