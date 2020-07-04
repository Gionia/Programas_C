#include <stdio.h>

/* Obtenido del libro de “Lenguaje c“
   Copia la entrada a la salida; 1a.version
   observe que EOF= ctrl+x ctr+c*/

int main()
{
   int c;

   c = getchar();
   while (c != EOF)
   {
        putchar(c);
        c = getchar();

   }
}
