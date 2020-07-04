#include <stdlib.h>
#include "lista.h"
#include <string.h>

Nodo* CrearNodo( Libro* libro ){

    Nodo* nodo = ( Nodo * )malloc( sizeof( Nodo ) ); //asignamos lmemoria suficiente

    strncpy( nodo->libro.autor, libro->autor, 50 ); //a nuestra variable nodo se le aignan los parametros de entada
    //strncpy( nodo->libro.titulo, libro->titulo, 50 );
    //strncpy( nodo->libro.isb, libro->isb, 50 );
    nodo->siguiente = NULL; //siguiente se vuelve nulo

    return nodo;

}

void DestruirNodo( Nodo *nodo ){

    free(nodo);

}

void InsertarInicio( Lista *lista, Libro *libro ){

    Nodo *nodo = CrearNodo( libro );
    printf("%s\n", libro->autor );
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;


}


void InsertarFinal( Lista *lista, Libro *libro ){

    Nodo* nodo = CrearNodo( libro );
    Nodo* puntero = lista->cabeza;

    if( lista->cabeza == NULL ){
        lista->cabeza= nodo;
    }//fin de if

    else{

        while( puntero->siguiente ){
            puntero = puntero->siguiente;
        }//fin de while

        puntero->siguiente = nodo;

    }//fin de else

    lista->longitud++;

}//fin de la funcion InsertarFinal()

void insertarDepues( int n, Lista *lista, Libro *libro ){

    Nodo* nodo = CrearNodo( libro );
    Nodo* puntero = lista->cabeza;

    if( lista->cabeza == NULL ){
        lista->cabeza = nodo;
    }

    else{

        int pocision = 0;

        while( pocision < n && puntero->siguiente ){
            puntero = puntero->siguiente;
            pocision++;
        }

        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;

    }//fin de else
    lista->longitud++;

}

int cantidad( Lista *lista ){
    return lista->longitud;
}

void EliminarPrincipio( Lista *lista, Libro* libro ){

    if( lista->cabeza ){

        Nodo* eliminado = lista->cabeza;

        lista->cabeza = lista->cabeza->siguiente;
        DestruirNodo( eliminado );
        lista->longitud--;
        }

}

void EliminarFinal( Lista * lista ){

    if( lista->cabeza ){

        if( lista->cabeza->siguiente ){

            Nodo *puntero = lista->cabeza;

            while( puntero->siguiente->siguiente ){
                puntero = puntero->siguiente;
            }

            Nodo *eliminado = puntero->siguiente;

            puntero->siguiente = NULL;
            DestruirNodo( eliminado );
            lista->longitud--;
        }// fin de if
        else{
            Nodo *eliminado = lista->cabeza;
            lista->cabeza = NULL;
            DestruirNodo( eliminado );
        }

    }//fin de if
}

void ELiminarElemento( int n, Lista *lista, Libro *libro){

    if( lista->cabeza ){

        if( n ==0 ){

            Nodo* eliminado = lista->cabeza;

            lista->cabeza = lista->cabeza->siguiente;
            DestruirNodo( eliminado );
            lista->longitud--;
        }

        else  if( n < lista->longitud ){
            Nodo *puntero = lista->cabeza;

            int posicion = 0;

            while( posicion < (n - 1 ) && puntero->siguiente ){
                puntero = puntero->siguiente;
                posicion++;
            }//fin de while

            Nodo *eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            DestruirNodo( eliminado );
            lista->longitud--;

            }//fin de else if
    }// fin de if

}/*fin de la funcion eliminar elemento */

void imprimirLista ( Lista *lista){

    printf( "Lalongitud es %d\n", lista->longitud );
    printf("%s", lista->cabeza->libro.autor );

    if( lista->cabeza == NULL ){
        printf( "la lista esta vacia\n" );
    }
    else{

        printf("hasta aqui jala\n");


        Nodo *nodo = lista->cabeza;

        while( nodo->siguiente != NULL ){
            printf("hasta aqui jala  aaa tambien");
            printf("%s", nodo->libro.autor );
            nodo = nodo->siguiente;
        }//fin de while

    }//fin de else

}//fin de la funcion lista
