#include <stdio.h>
#include <stdlib.h>
#include <lista.h>


int main()
{
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

    return 0;
}
