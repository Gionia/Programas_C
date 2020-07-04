#ifndef STRUCT_H
#define STRUCT_H

    typedef struct Number{ //este es el tipo de elemento que se guardara, de ser necesario este puede cambiar
        int value;
    }Number;

    typedef struct Nodo{ //cada celda es un  nodo el cual contiene la estructura que se almacena (numero) y contiene un apuntadora otro elemento
        Number number;
        struct Nodo *next;
    }Nodo;

    typedef struct List{//la lista contiene una cabeza la cual se inicializara con el primer nodo
        Nodo *head;
        int length; //tambien podemos ir midiendo la longitud de la lista
    }List;

    /* *************define functions**************** */
    Nodo *MakeNodo( Number *number );
    void killNodo( Nodo *nodo );


#endif
