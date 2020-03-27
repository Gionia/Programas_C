#include<stdio.h>
#include<math.h>
/*El programa calcula pi a partir de una serie
  unicamente se necesita saber el numero de iteraciones
  que se realizaran, entre mayor sea el numero de
  iteraciones mayor sera la precision */

int main()
{
    int n = 1, par_o_impar, iteraciones; /*n es el elemento en la serie, este comienza en 1, par_o_impar para saber si es par o no */

    float pi=2;

    printf("Por favor ingrese el numero de iteraciones\n");

    scanf( "%d",&iteraciones );

    while( n <= iteraciones )
    {
        par_o_impar = n%2; /* Para saber si es par o impar utilizamos el operando de modulo */

        if( par_o_impar != 0 )
            pi = pi*( n + 1 )/n; /* Es necesario ver la serie para poder saber como se llega a esto */

        else
            pi = pi*n/( n + 1 );


        n++; /* existen diversas formas de escribir n++*/
    }

    printf( "El valor de pi es %6f con %d iteraciones\n", pi, iteraciones );
}

/* Autor: Gionia | Last Modification: 27/03/2020 */ 
