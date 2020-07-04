#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"
#include "lista.h"

int main()
{

    char au[ 10 ];
    int n = 0 ;
    Libro ptrlibrito;
    Lista listilla;
    listilla.cabeza = NULL;



    //estructuras dinamicas
    while( n < 5){
        printf("Ingrese un titulo\n");
        scanf("%s", &ptrlibrito.autor );
        InsertarInicio( &listilla, &ptrlibrito );
        n++;
    }

    imprimirLista( &listilla );
    return 0;

}

