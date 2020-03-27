#include <stdio.h>

/* cuenta los caracteres de la entrada; 1a. version */

int main()
{
    long nc;

    nc = 0;
    while(getchar() != EOF)
    {
        ++nc;
        printf("%1d\n",nc);
                            }

}

/* Autor: Gionia | Last Modification: 27/03/2020 */ 
