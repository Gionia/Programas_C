#include <stdio.h>

int hanoil( int disco, int uno, int dos, int tres);
int mover_torre( int inicio, int fin);
int main(){

    int disco;

    printf("Ingrese el numero de discos:\n");
    scanf( "%d", &disco );

    hanoil( disco, 1, 2, 3);

}

int hanoil( int disco, int origen, int destino, int intermedio ){

    if( disco >= 1 ){

            hanoil( disco - 1, origen, intermedio, destino );
            mover_torre( origen, destino );
            hanoil( disco-1, intermedio, destino, origen );
    }


} /* fin de la funcion hanoil */


int mover_torre(int inicio, int fin ){

       return printf("%d--->%d\n", inicio, fin);

} /*fin de la funcion mover_torre */

/* Autor: Gionia | Last Modification: 27/03/2020 */ 
