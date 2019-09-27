#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <lista.h>
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define LST_ELEMENTO_NULO           1
#define LST_NO_EXISTE_SIGUIENTE     2
#define LST_NO_EXISTE_ANTERIOR      3
#define LST_POSICION_INVALIDA       4
#define LST_ERROR_MEMORIA           5


struct celda{
    void * elemento;
    struct celda * siguiente;
};

typedef struct celda * tLista;
typedef struct celda * tPosicion;
typedef void * tElemento;



/**
 Inicializa una lista vacía.
 Una referencia a la lista creada es referenciada en *L.
**/
void crear_lista(tLista * l){

        tLista lista=(tLista) malloc(sizeof(struct celda));
        lista->elemento=NULL;
        lista->siguiente=NULL;


        l=&lista;
}

/**
 Inserta el elemento E, en la posición P, en L.
 Con L = A,B,C,D y la posición P direccionando C, luego:
 L' = A,B,E,C,D
**/
void l_insertar(tLista l, tPosicion p, tElemento e){

        celda* nodoNuevo= (celda*) malloc(sizeof(struct celda));
        nodoNuevo->elemento=e;

        if(l_longitud(l)==0){ //Caso: la lista esta vacia, fijarse si el if es inutil

            l->siguiente=nodoNuevo;
            nodoNuevo->siguiente=NULL;

        }else{ //Caso: La lista no esta vacia

            if(l_primera(l)==p){
                nodoNuevo->siguiente=p;
                l->siguiente=nodoNuevo;
            }else{
                l_anterior(l,p)->siguiente=nodoNuevo;
                nodoNuevo->siguiente=p;
            }

        }
}

/**
 Elimina la celda P de L. El elemento almacenado en la posición P es eliminado mediante la función fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento)){

    if(l_fin(l)==p){

        exit(4);

    }else{

        l_anterior(l,p)->siguiente = p->siguiente; //Apunto el siguiente del anterior a p, al siguiente de p
        fEliminar(p->elemento); //Elimino el elemento de p con fEliminar
        //LIberar espacio en memoria de la celda despues de usar su siguiente


    }

}

/**
 Destruye la lista L, elimininando cada una de sus celdas. Los elementos almacenados en las celdas son eliminados mediante la función fEliminar parametrizada.
**/
void l_destruir(tLista * l, void (*fEliminar)(tElemento)){

    tPosicion nodoViajante= (tPosicion) malloc(sizeof(struct celda)); //Creo un nodo para recorrer la lista

    while(nodoViajante->siguiente!=NULL){

        fEliminar(nodoViajante->elemento); //Elimino el elemento de la celda con fEliminar
        nodoViajante=nodoViajante->siguiente; //Le asigno el siguiente al viajante
        //LIberar espacio en memoria de la celda despues de usar su siguiente

    }

    free(nodoViajante); //Por ultimo libero la memoria utilizada en nodoViajante

}

 /**
 Recupera y retorna el elemento en la posición P.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
tElemento l_recuperar(tLista l, tPosicion p){

    if(NULL==p){

        exit(4);

    }else{

        return p->siguiente->elemento;

    }

}

/**
 Recupera y retorna la primera posición de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
tPosicion l_primera(tLista l){

    if(l_longitud(l)==0){

        return l_fin(l);

    }else{

        return l->siguiente;

    }

}

/**
 Recupera y retorna la posición siguiente a P en L.
 Si P es fin(L), finaliza indicando LST_NO_EXISTE_SIGUIENTE.
**/
tPosicion l_siguiente(tLista l, tPosicion p){

    if(l_fin(l)==p){

        exit(2);

    }else{

        tPosicion nodoSiguiente= (tPosicion) malloc(sizeof(struct celda));
        nodoSiguiente=p->siguiente;
        return nodoSiguiente;
        free(nodoSiguiente);
    }

}

/**
 Recupera y retorna la posición anterior a P en L.
 Si P es primera(L), finaliza indicando LST_NO_EXISTE_ANTERIOR.
**/
tPosicion l_anterior(tLista l, tPosicion p){


    if(l->siguiente==p){

        exit(3);

    }else{

        tPosicion nodoViajante= (tPosicion) malloc(sizeof(struct celda)); //Creo un viajante
        nodoViajante=l; //Lo apunto al inicio de la lista

        while(nodoViajante!=NULL){ //Cuando llega al final termina
            if(nodoViajante->siguiente==p){ //Si el siguiente al viajante es el buscado
                return nodoViajante;        //lo devuelve
            }
            nodoViajante=nodoViajante->siguiente;
        }

        free(nodoViajante); //Se libera el espacio en memoria del nodoViajante
        exit(4); //Si llega aca significa que no encontro la posicion en la lista, asique tira excepcion
    }

}

 /**
 Recupera y retorna la última posición de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
tPosicion l_ultima(tLista l){

    if(l_longitud(l)==0 || l_longitud(l)==1){

        return l_fin(l);

    }else{

        tPosicion nodoViajante= (tPosicion) malloc(sizeof(tPosicion));
        nodoViajante=l;

        while(nodoViajante->siguiente->siguiente!=NULL){
            nodoViajante=nodoViajante->siguiente;
        }

        return nodoViajante;
    }

}

 /**
 Recupera y retorna la posición fin de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
tPosicion l_fin(tLista l){

        tPosicion nodoViajante= (tPosicion) malloc(sizeof(tPosicion));
        nodoViajante=l;

        while(nodoViajante->siguiente!=NULL){
            nodoViajante=nodoViajante->siguiente;
        }

        return nodoViajante;
    }



/**
 Retorna la longitud actual de la lista.
**/
int l_longitud(tLista l){

    int contador=0;

    tPosicion nodoViajante= (tPosicion) malloc(sizeof(struct celda));
    nodoViajante=l;


    while(nodoViajante->siguiente!=NULL){
        contador=contador+1;
        nodoViajante=nodoViajante->siguiente;
    }
    free(nodoViajante);

    return contador;

}

int main2()
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


#endif // LISTA_H_INCLUDED
