#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{ /* Nodo es una estancia */

    int valor;
    struct Nodo* ptrsiguiente;

}Nodo; /* aqui nodo si importa*/

typedef struct Lista{

    Nodo* ptrcabeza;
    int longitud;

}Lista;

/* Prototipos */
/* Se insertan elementos */
void insertarInicio( Lista *ptrlista, int valor);
void insertarFinal( Lista *ptrlista, int valor );
void insertarElemento( int n, Lista *ptrlista, int valor );

/*Se eliminan elementos */
void eliminarElemento( Lista *ptrlista, int valor );
void eliminarInicio( Lista *ptrlista );
void eliminarFinal( Lista *ptrlista );

void imprimeLista( Lista ptrlista );
Nodo *crearNodo( int valor );
void menu( int opcion );
void instruciones( void );

int main(){

    int opcion;
    Lista lista1; /* Se crea una variable del tipo estructuta Lista*/
    int valor;

    lista1.longitud = 0; /*En un inicio la lista tiene una longitud cero y es nula en su cola */
    lista1.ptrcabeza = NULL;

    instruciones();
        scanf( "%d", &opcion );

    while( opcion != 5 ){

        switch( opcion ){

            case 1:
                printf( "Ingrese un valor\n");
                scanf( "%d", &valor );
                insertarInicio( &lista1, valor);
                imprimeLista( lista1 );
                break;

            case 2:
                printf( "Ingrese un valor\n");
                scanf( "%d", &valor );
                insertarFinal( &lista1, valor);
                imprimeLista( lista1 );
                break;

        }//fin de switch

        instruciones();
        scanf( "%d", &opcion );

    }/* fin de while*/

    return 0;

}/* fin de la funcion while */

void instruciones( void )
{
    printf( "1-Insertar al inicio\n"
                "2-Insertar al final\n"
                "3-Insertar en lugar indicado\n"
                "4-Eliminar al inicio\n"
                "5-Salir\n");
}

Nodo *crearNodo( int num )
{
    Nodo *ptrnodo = ( Nodo * )malloc( sizeof( Nodo ) );
    ptrnodo->valor = num;
    ptrnodo->ptrsiguiente = NULL;
    return ptrnodo;

}/* fin de crar nodo*/

void insertarInicio( Lista *ptrlista, int valor )
{
    Nodo *ptrnodo = crearNodo( valor );
    ptrnodo->ptrsiguiente = ptrlista->ptrcabeza;
    ptrlista->ptrcabeza = ptrnodo;
    ptrlista->longitud++;
    printf("El valor es: %d\n", ptrnodo->valor );
    printf( "la longitud es: %d\n", ptrlista->longitud );
}/* fin de insertarInicio*/

void insertarFinal( Lista *ptrlista, int valor )
{

    Nodo *ptrnodo = crearNodo( valor );

    if( ptrlista->ptrcabeza == NULL ){
        ptrlista->ptrcabeza = ptrnodo;
    }
    else{
        Nodo *ptrpuntero = ptrlista->ptrcabeza;

        while( ptrpuntero->ptrsiguiente ){
           ptrpuntero = ptrpuntero->ptrsiguiente;
        }/*fin de while */

        ptrpuntero->ptrsiguiente = ptrnodo;
    }/*fin de else */

    ptrlista->longitud++;

}/*fin insertarFinal */

void imprimeLista( Lista lista )
{

    Nodo *ptrpuntero = lista.ptrcabeza;

    while( ptrpuntero ){
        printf( "%d ->", ptrpuntero->valor );
        ptrpuntero = ptrpuntero->ptrsiguiente;
    }

    printf("NULL\n");

}
