#ifndef lista_h
#define lista_h

#include <stdio.h>
#include "estructura.h"

typedef struct Nodo{
    Libro libro;
    struct Nodo *siguiente;
}Nodo;

typedef struct Lista{
   Nodo *cabeza;
   int longitud;

}Lista;

Nodo* CrearNodo( Libro* libro );

void DestruirNodo( Nodo *nodo );

void InsertarInicio( Lista *lista, Libro *libro );

void InsertarFinal( Lista *lista, Libro *libro );

void insertarDepues( int n, Lista *lista, Libro *libro );

int cantidad( Lista *lista );

void EliminarPrincipio( Lista *lista, Libro* libro );

void EliminarFinal( Lista * lista );

void ELiminarElemento( int n, Lista *lista, Libro *libro);

void imprimirLista( Lista *lista );

#endif
