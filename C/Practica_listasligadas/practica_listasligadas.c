#include <stdio.h>
#include <stdlib.h>

struct nodoLista{

    int dato;
    struct nodoLista *ptrSiguiente;
};

typedef struct nodoLista NodoLista;
typedef NodoLista *ptrNodoLista;

int main(){

    int *ptrprueba;
    int num;
    int numero;

    printf("&numero: %p\n", &numero);

    printf( "&ptrprueba: %p\n", &ptrprueba );
    numero = 1;
    ptrprueba = &numero;


    printf( "ptrprueba: %p\n\*ptrprueba: %p\n&ptrprueba: %p\nnumero: %p", ptrprueba, *ptrprueba, &ptrprueba, numero );


}

/* Autor: Gionia | Last Modification: 27/03/2020 */ 
