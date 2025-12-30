#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *col_to_hex(int);
char dec_to_hex(int);

int rgb_to_hex(int r, int g, int b)
{
    char *red = col_to_hex(r);
    char *green = col_to_hex(g);
    char *blue = col_to_hex(b);
    char *hex = malloc(7);

    *hex++ = red[0];
    *hex++ = red[1];
    *hex++ = green[0];
    *hex++ = green[1];
    *hex++ = blue[0];
    *hex++ = blue[1];
    *hex = '\0';

    *hex--;
    *hex--;
    *hex--;
    *hex--;
    *hex--;
    *hex--;

    printf("#%s\n", hex);
    return 0;
}

char *col_to_hex(int num)
{
    int q = num / 16;
    int r = num % 16;
    char *hex = malloc(3);
    *hex++ = dec_to_hex(q);
    *hex++ = dec_to_hex(r);
    *hex = '\0';
    *hex--;
    *hex--;
    return hex;
}

char dec_to_hex(int num)
{
    char a;

    switch (num)
    {
    case 0:
        a = '0';
        break;
    case 1:
        a = '1';
        break;
    case 2:
        a = '2';
        break;
    case 3:
        a = '3';
        break;
    case 4:
        a = '4';
        break;
    case 5:
        a = '5';
        break;
    case 6:
        a = '6';
        break;
    case 7:
        a = '7';
        break;
    case 8:
        a = '8';
        break;
    case 9:
        a = '9';
        break;
    case 10:
        a = 'A';
        break;
    case 11:
        a = 'B';
        break;
    case 12:
        a = 'C';
        break;
    case 13:
        a = 'D';
        break;
    case 14:
        a = 'E';
        break;
    case 15:
        a = 'F';
        break;
    default:
        a = 'T';
        break;
    }

    return a;
}