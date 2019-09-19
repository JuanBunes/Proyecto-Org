#include <stdio.h>
#include <stdlib.h>
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



extern void crear_lista(tLista * l);
extern void l_insertar(tLista l, tPosicion p, tElemento e);
extern void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento));
extern void l_destruir(tLista * l, void (*fEliminar)(tElemento));
extern tElemento l_recuperar(tLista l, tPosicion p);
extern tPosicion l_primera(tLista l);
extern tPosicion l_siguiente(tLista l, tPosicion p);
extern tPosicion l_anterior(tLista l, tPosicion p);
extern tPosicion l_ultima(tLista l);
extern tPosicion l_fin(tLista l);
extern int l_longitud(tLista l);


/**
 Inicializa una lista vacía.
 Una referencia a la lista creada es referenciada en *L.
**/
void crear_lista(tLista * l){

        celda* nuevalista=(celda*) malloc(sizeof(struct celda));
        l=&nuevalista;
        //int x=12;
        nuevalista->elemento=NULL;//Crea centinela
        nuevalista->siguiente=NULL;
}

/**
 Inserta el elemento E, en la posición P, en L.
 Con L = A,B,C,D y la posición P direccionando C, luego:
 L' = A,B,E,C,D
**/
void l_insertar(tLista l, tPosicion p, tElemento e){


        celda* nodoNuevo= (celda*) malloc(sizeof(struct celda));
        nodoNuevo->elemento=e;

        if(p->elemento==NULL){
            nodoNuevo->siguiente=NULL;
            l->siguiente=nodoNuevo;
        }

        else{
            nodoNuevo->siguiente=p;
            p->siguiente=nodoNuevo;
        }


}

/**
 Elimina la celda P de L. El elemento almacenado en la posición P es eliminado mediante la función fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento));

/**
 Destruye la lista L, elimininando cada una de sus celdas. Los elementos almacenados en las celdas son eliminados mediante la función fEliminar parametrizada.
**/
void l_destruir(tLista * l, void (*fEliminar)(tElemento));

 /**
 Recupera y retorna el elemento en la posición P.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
tElemento l_recuperar(tLista l, tPosicion p){

    if(l==p){//if(l_fin(l)==p){
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
        tPosicion primerNodo= (tPosicion) malloc(sizeof(struct celda));
        primerNodo=(tPosicion) l->siguiente;
        return primerNodo;
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
        tPosicion nodoAuxSiguiente= (tPosicion) malloc(sizeof(struct celda));
        nodoAuxSiguiente=p->siguiente;
        return nodoAuxSiguiente;
    }

}

/**
 Recupera y retorna la posición anterior a P en L.
 Si P es primera(L), finaliza indicando LST_NO_EXISTE_ANTERIOR.
**/
tPosicion l_anterior(tLista l, tPosicion p){


    if(l_primera(l)==p){
        exit(3);
    }else{

        tPosicion nodoViajante= (tPosicion) malloc(sizeof(struct celda));
        tPosicion nodoBuscador= (tPosicion) malloc(sizeof(struct celda));
        nodoBuscador=l_primera(l);

        while(nodoBuscador!=NULL){
            if(nodoBuscador->siguiente==p){
                return nodoBuscador;
            }
            nodoViajante=nodoViajante->siguiente;
        }
        free(nodoViajante);
        exit(4);
    }

}

 /**
 Recupera y retorna la última posición de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
tPosicion l_ultima(tLista l){

    if(l_longitud(l)==0){
        return l_fin(l);
    }else{

        tPosicion nodoViajante= (tPosicion) malloc(sizeof(struct celda));
        nodoViajante=l_primera(l);

        while(nodoViajante->siguiente!=NULL){
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

        if(l_longitud(l)==0){
            exit(3);
        }
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

int main()
{
    tLista lista;
    //tPosicion pos;

    //pos->elemento=NULL;
    //pos->siguiente=NULL;






    crear_lista(&lista);

    int *num;
    int x=9;
    num=&x;
    printf("fin \n");
    l_insertar(lista,lista,&x);


    //int cant=l_longitud(lista);
    //printf("longitud: %i",cant);

    printf("elemento: %i \n",(int)l_fin(lista));

    printf("fin");
    return 0;
}


#endif // LISTA_H_INCLUDED
