#include "kernel/types.h"
#include "user/user.h"

int main(void)
{
    char *data = sbrk(4096); // Allocate one page of memory
    printf("data: %p\n", data);
    // Protect the page
    if (mprotect(data, 2) == -1)
    {
        printf("mprotect failed\n");
        exit(1);
    }

    printf("Attempting to write to protected page\n");
    data[0] = 'A'; // This should cause a trap or segmentation fault

    printf("Write successful (unexpected)\n");
    exit(0);
}