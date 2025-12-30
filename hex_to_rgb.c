#include <stdio.h>
#include <stdlib.h>

int convert_letter_to_num(char);

int hex_to_rgb(char *hex)
{
    char r[2];
    r[0] = hex[0];
    r[1] = hex[1];

    char g[2];
    g[0] = hex[2];
    g[1] = hex[3];

    char b[2];
    b[0] = hex[4];
    b[1] = hex[5];

    int red = (convert_letter_to_num(r[0]) * 16) + (convert_letter_to_num(r[1]));
    int green = (convert_letter_to_num(g[0]) * 16) + (convert_letter_to_num(g[1]));
    int blue = (convert_letter_to_num(b[0]) * 16) + (convert_letter_to_num(b[1]));

    printf("(%d, %d, %d)\n", red, green, blue);
    return 0;
}

int convert_letter_to_num(char letter)
{
    switch (letter)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    default:
        break;
    }
}