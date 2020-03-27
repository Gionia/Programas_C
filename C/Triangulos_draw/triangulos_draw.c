#include<stdio.h>
#define LOWER 1
#define UPPER 10


int main()
{

    int i, j, option, k;

    printf( "Elige el tipo de figura a imprimir: 1 | 2 | 3 | 4\n" );

    scanf( "%d", &option );
    printf("\n");

    switch ( option ) {

        case 1: /* Imprime la primera figura, ver libro cap 4 */

            for(i = LOWER; i <= UPPER; i++ ){

                for( j = LOWER; j <= i; j++ ) {
                    printf( "*" );
                }

             printf("\n");

            }

        break; /* fin del case 1*/

        case 2: /* imprime la segunda figura, ver libro */

            for(i = LOWER; i <= UPPER; i++ ){

                for( j = UPPER; j >= i; j-- ) {
                    printf("*");
                }

             printf("\n");

            }

        break; /* fin del case 2 */

        case 3: /* imprime la tercera figura, ver el libro*/

            for(i = LOWER; i <= UPPER; i++ ){

                for( k = LOWER; k <= i; k++ ){ /*  este ciclo for imprime  los espacios en blanco correspondientes a la figura*/

                    if( k > LOWER ){ /*  la primera linea no lleva espacios en blanco */
                        printf(" ");

                    }

                }

                for( j = UPPER; j >= i; j-- ) {
                    printf("*"); /* imrprime "*" */
                }

             printf("\n");

            }

        break; /* fin del case 3 */

        case 4: /* imprime la 4 figura, ver el libro*/

            for(i = LOWER; i <= UPPER; i++ ){

                for( k = UPPER; k >= i; k-- ){ /*  este ciclo for imprime  los espacios en blanco correspondientes a la figura*/

                    if( k < UPPER ){ /*  la ultima linea no imprimira el espacio en blanco */
                        printf(" ");

                    }

                }

                for( j = LOWER; j <= i; j++ ) {
                    printf("*");
                }

             printf("\n");

            }

        break; /* fin del case 4 */


        } /* fin del switch(option) */


}

/* Autor: Gionia | Last Modification: 27/03/2020 */ 
