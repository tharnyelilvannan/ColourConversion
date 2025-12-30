#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colour.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Incorrect number of aru=guments.\n");
        printf("--help for more information.\n");
        return 1;
    }

    if (strcmp(argv[1], "--help" == 0))
    {
        help();
    }
}