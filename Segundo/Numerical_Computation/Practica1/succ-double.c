#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double x_0 = 0.01;
    double x_n;

    for (int i = 1; i < 40; i++)
    {
        x_n = exp(-6.2 * x_0 * x_0) - 0.5;
        x_0 = x_n;
    }

    printf("%.9le",x_n);

    return 0;
}