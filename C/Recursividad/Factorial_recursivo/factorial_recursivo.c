#include <stdio.h>

long factorial(long number);
void imprimir( void );

int main()
{
    int  numero, resultado;

    printf( "Ingrese un numero entero positivo:\n" );
    scanf( "%d", &numero);

    if( numero >= 1 ){

        printf( "El factorial es: %d\n", factorial( numero ) );
    }
    else {

        printf( "El factorial es: %f", 1. );

    }

} /* fin de la funcion main*/

long factorial( long number ){

    if ( number == 1 )
        return 1;
    else
        return number *factorial( number - 1 );

}

/* Autor: Gionia | Last Modification: 27/03/2020 */ 
