#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hsl_to_rgb(double h, double s, double l)
{
    double chroma = (1 - fabs(2 * l - 1)) * s;
    double h_prime = h / 60.0;
    double x = chroma * (1 - fabs(fmod(h_prime, 2.0) - 1));
    double red1;
    double green1;
    double blue1;

    if (h_prime >= 0 && h_prime <= 1)
    {
        red1 = chroma;
        green1 = x;
        blue1 = 0;
    }
    else if (h_prime >= 1 && h_prime <= 2)
    {
        red1 = x;
        green1 = chroma;
        blue1 = 0;
    }
    else if (h_prime >= 2 && h_prime <= 3)
    {
        red1 = 0;
        green1 = chroma;
        blue1 = x;
    }
    else if (h_prime >= 3 && h_prime <= 4)
    {
        red1 = 0;
        green1 = x;
        blue1 = chroma;
    }
    else if (h_prime >= 4 && h_prime <= 5)
    {
        red1 = x;
        green1 = 0;
        blue1 = chroma;
    }
    else if (h_prime >= 5 && h_prime <= 6)
    {
        red1 = chroma;
        green1 = 0;
        blue1 = x;
    }
    else
    {
        exit(8);
    }

    double m = l - (chroma / 2.0);

    double red = (red1 + m) * 255;
    double green = (green1 + m) * 255;
    double blue = (blue1 + m) * 255;

    printf("(%d, %d, %d)\n", (int)round(red), (int)round(green), (int)round(blue));

    return 0;
}