#include <stdio.h>

long fibonacci( long elemento );

int main()
{
    int number;

    printf( "Ingrese que elemento quiere de la serie fibonacci (debe ser positivo)\n");
    scanf( "%d", &number);

    if( number < 0)
        printf( "numero equivocado, intente de nuevo" );
    else
        printf( "La suma hasta el elemento %d es: %ld", number, fibonacci( number ));

}

long fibonacci( long elemento ){

    if( elemento == 0 || elemento == 1)
        return elemento;
    else
        return fibonacci(elemento - 1) + fibonacci( elemento - 2);

}
/* Autor: Gionia | Last Modification: 27/03/2020 */ 
