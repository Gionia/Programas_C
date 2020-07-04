#include <stdio.h>

#define TAMANIO 8

/* Autor: Gionia | Last Modification: 27/03/2020 */  
/**:::::::::::::::::::::::::::::::::::::::::::::Prototipos de funciones::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

int mejor_movimiento( int tablero_accesible[][8], int actualr, int actualc );
int move_row( int actualr, int move_number);
int move_col( int actualc, int move_number);
void imprimir_tablero( int tableros[ ][ TAMANIO ] );
int mover( int tablero[][ TAMANIO ], int movimiento, int actalr, int actualc, int contador);
int generador_movimiento( int i, int j);

/**::::::::::::::::::::::::::::::::::::::::::::::::Variables Globales::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

int horizontal[ TAMANIO ] = { 2, 1, -1, -2, -2, -1, 1, 2};
int vertical[ TAMANIO ] = { -1, -2, -2, -1, 1, 2, 2, 1}; /*cada tipo de movimiento se mueve tantas casillas en horizontal y vertical */

 /* horizontal[ 0 ] = 2;    El movimiento 0 esta comuesto por horizontal[0] y vertical[0]
    horizontal[ 1 ] = 1;    Es decir movimiento x esta comuesto por horizontal[x] y vertical[x]
    horizontal[ 2 ] = -1;   siendo x elemeto del conjunto de numero enteros acotado por [ 0, 7 ]
    horizontal[ 3 ] = -2;
    horizontal[ 4 ] = -2;
    horizontal[ 5 ] = -1;*/               /** _0___  1___  2___   3___ 4___  5___  6___  7___
    horizontal[ 6 ] = 1;                     |     |     |     |     |     |     |     |     |
    horizontal[ 7 ] = 2;                   0 |     |     |     |     |     |     |     |     |
                                             -------------------------------------------------
    vertical[ 0 ] = -1;                      |     |     |     |     |     |     |     |     |
    vertical[ 1 ] = -2;                    1 |     |     |     |  2  |     |  1  |     |     |
    vertical[ 2 ] = -2;                      -------------------------------------------------
    vertical[ 3 ] = -1;                      |     |     |     |     |     |     |     |     |
    vertical[ 4 ] = 1;                     2 |     |     |  3  |     |     |     |  0  |     |
    vertical[ 5 ] = 2;                       -------------------------------------------------
    vertical[ 6 ] = 2;                       |     |     |     |     |     |     |     |     |
    vertical[ 7 ] = 1;                     3 |     |     |     |     |  k  |     |     |     |
                                             -------------------------------------------------
                                             |     |     |     |     |     |     |     |     |
                                           4 |     |     |  4  |     |     |     |  7  |     |
                                             -------------------------------------------------
                                             |     |     |     |     |     |     |     |     |
                                           5 |     |     |     |  5  |     |  6  |     |     |
                                             -------------------------------------------------
                                             |     |     |     |     |     |     |     |     |
                                           6 |     |     |     |     |     |     |     |     |
                                             -------------------------------------------------
                                             |     |     |     |     |     |     |     |     |
                                           7 |     |     |     |     |     |     |     |     |
                                             ------------------------------------------------- **/

/**:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

int main(){

    int i, j;

    for( i = 0; i <= 7; i++ ){

        for( j = 0; j <= 7; j++ ){
            generador_movimiento( i , j);
        }

    }

    return 0;

} /* fin de la funcion main */

/**:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::**/

int generador_movimiento( int actualrow, int actualcol){

    int tablero[ TAMANIO ][ TAMANIO ] = {0}; /*cada elemento de tablero por el momento es cero*/
    int tablero_accesible[ TAMANIO ][ TAMANIO ] = { { 2, 3, 4, 4, 4, 4, 3, 2},
                                                    { 3, 4, 6, 6, 6, 6, 4, 3},
                                                    { 4, 6, 8, 8, 8, 8, 6, 4},
                                                    { 4, 6, 8, 8, 8, 8, 6, 4},
                                                    { 4, 6, 8, 8, 8, 8, 6, 4},
                                                    { 4, 6, 8, 8, 8, 8, 6, 4},
                                                    { 3, 4, 6, 6, 6, 6, 4, 3},
                                                    { 2, 3, 4, 4, 4, 4, 3, 2}};  /* en el tablero existen puntos accesibles, el numero indica
                                                                                desde cuantas posiciones es accesible la casilla*/

    //int actualrow = ROW, actualcol = COL; /* El caballo comienza en la casilla (ROW, COL), se puede definir de nuevo */
    int movimiento; /* existen 8 tipos de movimiento, ver el grafico de la seccion variables globales*/
    /*Existen ocho movimientos para el caballo, por ejemplo horizontal[0] y vertical[0] hacen
      referencia al movimiento numero cero*/
    int contador = 1; /*indica cuantos movimientos se han realizado*/

    tablero[ actualrow ][ actualcol ] = contador;
    movimiento = mejor_movimiento( tablero_accesible, actualrow , actualcol); /* Es el primer movimiento que realiza el knight*/
    mover( tablero, movimiento, actualrow, actualcol, contador );
    printf( "El caballo inicia en la posicion ( %d, %d )\n", actualrow, actualcol );
        while( movimiento != -1){

            actualrow = move_row( actualrow, movimiento );
            actualcol = move_col( actualcol, movimiento );
            contador++;
            tablero[ actualrow ][ actualcol ] = contador;
            movimiento = mejor_movimiento( tablero_accesible, actualrow, actualcol );

        }
    printf(" Total movimientos: %d\nLos movimientos que debe realizar para resolver el problema son:\n", contador );
    imprimir_tablero( tablero );

}/* fin de la funcion generador_movimiento */

/**:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

/*  Esta funcion es de suma importancia ya que, elige
    cual es la posible mejor opcion para realizar un movimiento
    una vez realizado esto la funcion regresa el tipo de
    movimiento que se debe de realizar para mover al knight  */

int mejor_movimiento( int tablero_accesible[ TAMANIO ][ TAMANIO ], int actualr, int actualc ){

    int posibler, posiblec, i;
    int best_move; /* best_move es el posible movimiento, cada vez ese posible movimiento se considera el mejor, y despues se compara, con en el sig*/
    int best = 8; /* si llega a ser el mejor se guarda en la variable best*/
    int best_cord = -1; /* guarda el tipo de movimiento que tendra que realizar para hacer el mejor movimiento, inicia en -1 por que es posible
                            que el knight ya no pueda moverse, en este caso se necesita un numero para decir que se detenga el programa*/

    for( i = 0; i <= 7; i++ ){ /* se probaran los siete movimientos para ver cual es el mejor */

        posibler = move_row( actualr, i);
        posiblec = move_col( actualc, i);

        if( (posiblec >= 0 & posiblec <= 7 ) & ( posibler >= 0 & posibler <= 7 ) & tablero_accesible[ posibler][ posiblec] != 0 ){
        /* verfica que este dentro del rango del tablero*/

            best_move = tablero_accesible[ posibler ][ posiblec ]; /* comienza haciendo que el primer num accesible es el mas bajo */
            tablero_accesible[ posibler ][ posiblec ] -= 1;  /* se reduce el numero de accesos posibles, dependiendo de la posicion actual */

            if( best_move <= best & best_move != 0 ){
                best = best_move; /* en pocas palabras esta operacion encuentra el valor minimo entres los puntos accesibles */
                best_cord = i; /* una vez encontrado se guarda el tipo de movimiento que nos lleva al valor accesible mas bajo*/
            }

        }

    }/*fin ciclo for */

    tablero_accesible[ actualr ][ actualc ] = 0; /* el punto donde esta el knight es cero, es decir, ya no es accesible*/

    return best_cord;

}/*fin de fun movimientos posibles */

/**:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

int move_row( int actualr, int move_number){ /*se usa para saber la posicion de el knight sobre el eje horizontal  */
    return actualr + vertical[ move_number ];

}

/**:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

int move_col( int actualc, int move_number){ /* se usa para saber la posicion de el knight sobre el eje vertical */
    return actualc + horizontal[ move_number ];

}

/**:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

void imprimir_tablero( int tableros[  ][ TAMANIO ] ){ /* Imprime los tableros*/

    int i, j;

    printf("\n");
    for( i = 0; i <= 7; i++ ){

        for( j=0; j<= 7; j++ ){

            if( j == 0)
                printf( "\t" ); /* deja un espacio (sangria) */

            printf( "%4d", tableros[ i ][ j ]);
        }

        printf("\n\n");

    }

    printf("\n");
}

/**:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

int mover( int tablero[ TAMANIO ][ TAMANIO ], int movimiento, int actualr, int actualc, int contador ){
/* Esta funcion cambia el tablero indicando el numero de movimientos realizados */

    int cordx, cordy; /*posicion a la que s emovera el knight */

    cordx = move_row( actualr, movimiento );
    cordy = move_col( actualc, movimiento );
    tablero[ cordx ][ cordy ] = contador;

    return 0;

}

/* Autor: Gionia | Last Modification: 27/03/2020 */ 
