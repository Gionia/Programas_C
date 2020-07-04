#include <stdio.h>
#include <math.h>

int mcd( int x, int y);

int main(){

    int x, y;

    printf( "Ingrese el numero x:\n");
    scanf( "%d", &x);
    printf( "Ingrese el numero y:\n");
    scanf( "%d", &y);

    printf( "El maximo comun divisor es: %d", mcd( x, y ) );

    return 0;
}

int mcd( int x, int y){

    if( y == 0)
        return x;
    else
        return mcd( y, x%y );

}

/* Autor: Gionia | Last Modification: 27/03/2020 */ 
