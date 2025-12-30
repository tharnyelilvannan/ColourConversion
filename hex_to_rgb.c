#include <stdio.h>
#include <stdlib.h>

int hex_to_dec(char);

int hex_to_rgb(char *hex)
{
    // hex format is XXXXXX
    int red = (hex_to_dec(hex[0]) * 16) + (hex_to_dec(hex[1]));
    int green = (hex_to_dec(hex[2]) * 16) + (hex_to_dec(hex[3]));
    int blue = (hex_to_dec(hex[4]) * 16) + (hex_to_dec(hex[5]));

    if (red == -1 || green == -1 || blue == -1)
    {
        return -1;
    }

    printf("(%d, %d, %d)\n", red, green, blue);
    return 0;
}

int hex_to_dec(char letter)
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
        return -1;
    }
}