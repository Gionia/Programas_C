#include <stdio.h>
#include <stddef.h>
/* Autor: Gionia | Last Modification: 27/03/2020 */ 

void inverso ( const char  *const ptrS );

int main(){

    char enunciado [ 80 ];

    printf( "Introduzca un alinea de texto:\n" );
    gets( enunciado );

    printf( "\nLa linea impresa al reves es:\n" );
    inverso( enunciado );

    return 0;

}

void inverso( const char  *const ptrS ){

    if ( ptrS[ 0 ] == '\0' ){

        return;

    }

    else{

        inverso( &ptrS[ 1 ] );
        putchar( ptrS[ 0 ] );

    }

}
