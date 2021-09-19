#include <stdio.h>

int main(int argc, char const *argv[]){
    float i = 1;
    float sn = 0;
    float sn1 = 0;

    // Apartat a):
    do{
        sn1 = sn;
        sn += 1/i;
        i++;
    }while(sn1 != sn);

    printf("\n a) Sn := %f en %d iteracions. \n",sn,(int)i);

    sn = 0; 
    sn1 = 0;

    // Apartat b):
    do{
        sn1 = sn;
        sn += 1/i;
        i--;
    }while(i > 1);

    printf(" b) Sn := %f",sn);

    return 0;
}
