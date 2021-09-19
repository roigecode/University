#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float x_0 = 0.01;
    float x_n = 0;
    float x_n1 = 0;

    for (int i = 1; i < 41; i++)
    {
        x_n1 = x_n;
        x_n = exp(-6.2 * pow(x_n,2)) - 0.5;
    }

    printf("\n Valor de x_40: %f\n",x_n);

    return 0;
}
