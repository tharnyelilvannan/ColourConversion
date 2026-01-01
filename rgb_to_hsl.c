#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double *min(double *, double *, double *);
double *max(double *, double *, double *);

int rgb_to_hsl(double r, double g, double b)
{
    double red = r / 255.0;
    double green = g / 255.0;
    double blue = b / 255.0;
    double *minimum = min(&red, &green, &blue);
    double *maximum = max(&red, &green, &blue);

    double l = (*minimum + *maximum) / 2;
    double s;
    double h;

    if (fabs(*maximum - *minimum) < 0.0001) // problem
    {
        s = 0;
        h = 0;
        return 0;
    }

    if ((l - 0.5) <= 0)
    {
        s = (*maximum - *minimum) / (*maximum + *minimum);
    }
    else
    {
        s = (*maximum - *minimum) / (2.0 - *maximum - *minimum);
    }

    if (maximum == &red)
    {
        h = (green - blue) / (*maximum - *minimum);
    }
    else if (maximum == &green)
    {
        h = 2 + ((blue - red) / (*maximum - *minimum));
    }
    else
    {
        h = 4 + ((red - green) / (*maximum - *minimum));
    }

    h = h * 60;

    if (h < 0)
    {
        h = h + 360;
    }

    printf("(%f, %f, %f)\n", h, s, l);
    return 0;
}

double *min(double *a, double *b, double *c)
{
    double *min;

    if ((*a - *b) < 0)
    {
        min = a;
    }
    else
    {
        min = b;
    }

    if ((*c - *min) < 0)
    {
        min = c;
    }

    printf("%f\n", *min);

    return min;
}

double *max(double *a, double *b, double *c)
{
    double *max;

    if ((*a - *b) < 0)
    {
        max = b;
    }
    else
    {
        max = a;
    }

    if ((*max - *c) < 0)
    {
        max = c;
    }

    printf("%f\n", *max);

    return max;
}