#include <stdio.h>

long potencia( long base, int exponente); /* prototipo de la funcion */

/* Este programa calcula la potencia de un numero de manera recursiva, dando solo dos parametros */
int main(){

    int exponente;
    long base;


    printf( "Ingrese una base: ");
    scanf("%ld", &base );
    printf( "Ingrese el exponente: ");
    scanf( "%d", &exponente );

    if( exponente < 0 )
        printf( "Intente ingresar un nuevo numero, esta vez que sea mayor o igual a 0");
    else if( exponente == 0)
         printf( "El valor de %ld eleado a la %d es: %ld\n", base, exponente, 1);
    else
         printf( "El valor de %ld eleado a la %d es: %ld\n", base, exponente, potencia( base, exponente ) );

}/* fin de la funcion main */

long potencia( long base, int exponente ){

    if( exponente == 1 )
        return base;
    else
        return base*potencia( base, exponente - 1);

} /* fin de la funcion recursiva potencia */

/* Autor: Gionia | Last Modification: 27/03/2020 */ 
