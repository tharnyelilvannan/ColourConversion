#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colour.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Incorrect number of arguments.\n");
        printf("--help for more information.\n");
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0)
    {
        help();
    }

    if (strcmp(argv[1], "-hex") == 0)
    {
        if (strcmp(argv[3], "-rgb") == 0)
        {
            char *hex = (char *)argv[2];
            hex_to_rgb(hex);
        }
        else
        {
            return 2;
        }
    }

    return 0;
}