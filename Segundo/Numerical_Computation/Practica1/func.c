#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    // Desenvolupament per Taylor de la funció:
    double x;
    double funcio = (cos(x)-1)/pow(x,2);
    double taylorcos = 1-pow(x,2)/2;
    double taylorfunc = (taylorcos-1)/pow(x,2);

    x = 0.0001;

    double errabs = funcio;
    
    printf("Error absolut: %f\n",errabs);
    return 0;
}
