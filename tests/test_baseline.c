#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    if (strlen("lab") != 3U) {
        return EXIT_FAILURE;
    }
    return puts("PASS: baseline string length") < 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
