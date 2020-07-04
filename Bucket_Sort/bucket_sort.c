#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO 200

int main(){

    int *ptra;

    int arreglo[ 5 ] = { 1, 2, 3, 4 , '\0'};

    ptra = &arreglo[1];

    putchar(ptra[1]);

    printf( "%s", arreglo );
    return 0;

}

/* Autor: Gionia | Last Modification: 27/03/2020 */ 
