#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Nodo *MakeNodo( Number *number){

    Nodo *nodo = ( Nodo * )malloc( sizeof( Nodo ) ); //se asigna espacio en memoria para crear los nodos

    nodo->number.value = number->value; /* el nodo que se creo, tiene un elemento llamado number y este a su vez un value*/
    nodo->next = NULL;

    return nodo;

}

void killNodo( Nodo *nodo ){
    free( nodo );/*se libera espacio para que no se sobre cargue la memoria */
}//fin de la funcion kill nodo

void InsertBegin( List * list, Number *number){

    Nodo *nodo = MakeNodo( number ); //se crea el nodo mediante la funcion correspondiente
    nodo->next = list->head; //como se pone al onicio, antes de ponerlo es posible que ya exista un nodo cabeza, lo que hacemos es desplazarlo
    list->head = nodo; //ahora nuestra cabeza de la lista sera el nodo insertado en el inicio
    list->length++;//aumentamos la longitud de nuestra lista

}
