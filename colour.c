#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colour.h"

int main(int argc, char *argv[])
{
    if (argc <= 1)
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
            char *hex = argv[2];
            int err = hex_to_rgb(hex);

            if (err != 0)
            {
                printf("Error converting to RGB value.\n");
                return 3;
            }
        }
        else
        {
            return 2;
        }
    }
    else if (strcmp(argv[1], "-rgb") == 0)
    {
        if (argc == 6)
        {
            if (strcmp(argv[5], "-hex") == 0)
            {
                char *r_end;
                char *g_end;
                char *b_end;

                long int r = strtol(argv[2], &r_end, 10);
                long int g = strtol(argv[3], &g_end, 10);
                long int b = strtol(argv[4], &b_end, 10);

                int err = rgb_to_hex(r, g, b);

                if (err != 0)
                {
                    printf("Error converting to hex value.\n");
                    return 3;
                }
            }
            else
            {
                return 2;
            }
        }
        else
        {
            printf("Incorrect number of arguments.\n");
            help();
            return 1;
        }
        return 0;
    }
}