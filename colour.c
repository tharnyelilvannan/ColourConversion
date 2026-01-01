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
    else if (strcmp(argv[1], "-hex") == 0)
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
                int r = rgb_verify(argv[2]);
                int g = rgb_verify(argv[3]);
                int b = rgb_verify(argv[4]);

                rgb_to_hex(r, g, b);
            }
            else if (strcmp(argv[5], "-hsl") == 0)
            {
                int r = rgb_verify(argv[2]);
                int g = rgb_verify(argv[3]);
                int b = rgb_verify(argv[4]);
                rgb_to_hsl((double)r, (double)g, (double)b);
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
    }
    else if (strcmp(argv[1], "-hsl") == 0)
    {
        if (argc == 6)
        {
            if (strcmp(argv[5], "-rgb") == 0)
            {
                double h = atof(argv[2]);
                double s = atof(argv[3]);
                double l = atof(argv[4]);

                int err = hsl_to_rgb(h, s, l);

                if (err != 0)
                {
                    printf("Error converting to RGB value.\n");
                    exit(3);
                }
            }
        }
    }
    else
    {
        printf("Incorrect flag.\n");
        exit(1);
    }

    exit(0);
}

int rgb_verify(char *val)
{
    char *val_end;
    int rgb = strtol(val, &val_end, 10);

    if (rgb > 255 || rgb < 0)
    {
        printf("Invalid RGB code.");
        exit(5);
    }

    return rgb;
}