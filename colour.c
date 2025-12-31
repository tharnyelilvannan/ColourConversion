#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "colour.h"

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Incorrect number of arguments.\n");
        printf("--help for more information.\n");
        exit(1);
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

            regex_t regex;

            int valid = regcomp(&regex, "([0-9]|[A-F]){6}", REG_EXTENDED);

            if (valid)
            {
                printf("Could not compile regex.\n");
                exit(6);
            }

            valid = regexec(&regex, hex, 0, NULL, 0);

            if (valid)
            {
                printf("Invalid hex code.");
                exit(5);
            }

            regfree(&regex);

            int err = hex_to_rgb(hex);

            if (err != 0)
            {
                printf("Error converting to RGB value.\n");
                exit(3);
            }
        }
        else
        {
            exit(2);
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

                if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
                {
                    printf("Invalid RGB code.");
                    exit(5);
                }

                int err = rgb_to_hex(r, g, b);

                if (err != 0)
                {
                    printf("Error converting to hex value.\n");
                    exit(3);
                }
            }
            else
            {
                exit(2);
            }
        }
        else
        {
            printf("Incorrect number of arguments.\n");
            exit(1);
        }
        exit(0);
    }
}