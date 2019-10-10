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
    int *numero1=NULL;
    *numero1=1;
    crear_raiz(arbol,numero1);

    printf("inicio \n");

    int *devolver;
    *devolver=(int) a_recuperar(arbol,a_raiz(arbol));
    printf("raiz(1):  %i \n",&devolver);

    int *numero2=NULL;
    *numero2=2;
    a_insertar(arbol,a_raiz(arbol),NULL,numero2);
    *devolver=(int) a_recuperar( arbol , l_primera((a_hijos(arbol,a_raiz(arbol))))->elemento );
    printf("primer hijo de raiz(2):  %i \n",&devolver);

    a_eliminar(arbol,a_raiz(arbol),fEliminar);
    *devolver=(int) a_recuperar(arbol,a_raiz(arbol));
    printf("nueva raiz(2):  %i \n",&devolver);

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
