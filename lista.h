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
extern void crear_lista(tLista * l){

    l=null;//Crea la lista que apunta a un nulo

}

/**
 Inserta el elemento E, en la posición P, en L.
 Con L = A,B,C,D y la posición P direccionando C, luego:
 L' = A,B,E,C,D
**/
extern void l_insertar(tLista l, tPosicion p, tElemento e){

    if(l_longitud(l)==0){
        *l->elemento=e;
    }else{
        tPosicion nodoAuxiliar= (tPosicion*) malloc(sizeof(tPosicion));
        nodoAuxiliar=p;
        *p->elemento=e;
        *p->siguiente=nodoAuxiliar;
    }

}

/**
 Elimina la celda P de L. El elemento almacenado en la posición P es eliminado mediante la función fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
extern void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento));

/**
 Destruye la lista L, elimininando cada una de sus celdas. Los elementos almacenados en las celdas son eliminados mediante la función fEliminar parametrizada.
**/
extern void l_destruir(tLista * l, void (*fEliminar)(tElemento));

 /**
 Recupera y retorna el elemento en la posición P.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
extern tElemento l_recuperar(tLista l, tPosicion p){

    if(l_ultima(l)==p){
        //No se como tirar excepsiones lst Jejox
    }else{
        return p->elemento;
    }

}

/**
 Recupera y retorna la primera posición de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
extern tPosicion l_primera(tLista l){

    if(l_longitud(l)==0){
        return l_fin(l);
    }else{
        tPosicion primerNodo= (tPosicion*) malloc(sizeof(tPosicion));
        primerNodo=(tPosicion) l;
        return primerNodo;
    }

}

/**
 Recupera y retorna la posición siguiente a P en L.
 Si P es fin(L), finaliza indicando LST_NO_EXISTE_SIGUIENTE.
**/
extern tPosicion l_siguiente(tLista l, tPosicion p){

    if(l_fin(l)==p){
        //No se como tirar excepsiones lst Jejox LST_NO_EXISTE_SIGUIENTE
    }else{
        tPosicion nodoAuxSiguiente= (tPosicion*) malloc(sizeof(tPosicion));
        nodoAuxSiguiente=p->siguiente;
        return nodoAuxSiguiente;
    }

}

/**
 Recupera y retorna la posición anterior a P en L.
 Si P es primera(L), finaliza indicando LST_NO_EXISTE_ANTERIOR.
**/
extern tPosicion l_anterior(tLista l, tPosicion p){

    if(l_primera(l)==p){
        //No se como tirar excepsiones lst Jejox LST_NO_EXISTE_ANTERIOR
    }else{
        tPosicion nodoBuscador= (tPosicion*) malloc(sizeof(tPosicion));
        nodoBuscador=l_primera(l);

        while(nodoBuscador!=null){
            if(nodoBuscador->siguiente==p){
                return nodoBuscador;
            }
            nodoViajante=nodoViajante->siguiente;
        }

        //No se como tirar excepsiones lst Jejox LST_POSICION_INVALIDA
    }

}

 /**
 Recupera y retorna la última posición de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
extern tPosicion l_ultima(tLista l){

    if(l_longitud(l)==0){
        return l_fin(l);
    }else{
        tPosicion nodoViajante= (tPosicion*) malloc(sizeof(tPosicion));
        nodoViajante=l_primera(l);

        while(nodoViajante->siguiente!=null){
            nodoViajante=nodoViajante->siguiente;
        }

        return nodoViajante;
    }

}

 /**
 Recupera y retorna la posición fin de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
extern tPosicion l_fin(tLista l){

    if(l_longitud(l)==0){
        return crear_lista(l);
    }else{
        tPosicion nodoViajante= (tPosicion*) malloc(sizeof(tPosicion));
        nodoViajante=l_primera(l);

        while(nodoViajante!=null){
            nodoViajante=nodoViajante->siguiente;
        }

        return nodoViajante;
    }

}

/**
 Retorna la longitud actual de la lista.
**/
extern int l_longitud(tLista l){

    int contador=0;

    tPosicion nodoViajante= (tPosicion*) malloc(sizeof(tPosicion));
    nodoViajante=(tPosicion) l;

    while(nodoViajante!=null){
        contador=contador+1;
        nodoViajante=nodoViajante->siguiente;
    }

}

#endif // LISTA_H_INCLUDED
