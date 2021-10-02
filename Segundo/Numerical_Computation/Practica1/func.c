#include <stdio.h>
#include <math.h>

double f_taylor(double x){
    return (double) -1/2 + pow(x,2)/24;
}

int main(int argc, char const *argv[])
{
    FILE * sortida;
    sortida = fopen("exercici2.txt","w");
    double x = -0.001;

    while(x<=0.001){
        fprintf(sortida,"%.11le %.11le\n",x,f_taylor(x));
        x += 0.000025;
    }
    fclose(sortida);
    return 0;
}
