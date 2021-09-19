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

    printf("\n Sn := %f || Sn-1 := %f",sn,sn1);
    printf("\n Valor de i: %f\n",i);

    sn = 0; 
    sn1 = 0;

    // Apartat b):
    do{
        sn1 = sn;
        sn += 1/i;
        i--;
    }while(i > 1);

    printf(" Sn := %f || Sn-1 := %f",sn,sn1);

    return 0;
}
