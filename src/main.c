#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "arbol.h"

void fEliminar(tElemento e);

void fEliminar(tElemento e){

    free(e);

}

int main()
{

    tArbol arbol;
    crear_arbol(&arbol);
    crear_raiz(arbol,1);
    printf("inicio \n");
    printf("raiz:  %i \n",a_recuperar(arbol,a_raiz(arbol)));



/*
    tLista  lista;
    crear_lista (&lista);
    lista->elemento=NULL;
    lista->siguiente=NULL;


    printf("inicio \n");

    int *num;
    int x=9;
    l_insertar( lista, lista,&x);
    printf("inicio \n");

    num= (int*) l_recuperar( lista, lista);
    printf("1elem: %i", *num);

    int j=7;
    l_insertar(lista,l_primera(lista),&j);

    num= (int*) l_recuperar( lista, lista);
    printf("2elem: %i \n", *num);

    int k=5;
    l_insertar(lista,l_primera(lista),&k);

    num= (int*) l_recuperar( lista, l_ultima(lista));
    printf("elem9: %i", *num);

    num= (int*) l_recuperar( lista, l_anterior(lista,l_ultima(lista)));
    printf("elem7: %i", *num);

    k=l_longitud(lista);
    printf("3: %i", k);

    l_eliminar(lista,l_primera(lista),fEliminar);
    num= (int*) l_recuperar( lista, lista);
    printf("1elem: %i", *num);

*/
    return 0;
}
