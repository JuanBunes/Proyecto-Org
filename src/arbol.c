#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "lista.h"
#include "arbol.h"

#define ARB_OPERACION_INVALIDA      10
#define ARB_POSICION_INVALIDA       11
#define ARB_ERROR_MEMORIA           12

void postOrden(tArbol * a, tNodo n,void (*fEliminar)(tElemento));

/**
Inicializa un árbol vacío.
Una referencia al árbol creado es referenciado en *A.
**/
void crear_arbol(tArbol * a){

    tArbol arbol=(tArbol) malloc(sizeof(struct arbol));
    arbol->raiz=NULL;
    a=&arbol;


}

/**
Crea la raíz de A.
Si A no es vacío, finaliza indicando ARB_OPERACION_INVALIDA.
**/
void crear_raiz(tArbol a, tElemento e){


    if(a->raiz!=NULL){
        exit(ARB_OPERACION_INVALIDA);
    }

    tNodo nodoRaiz=(tNodo) malloc(sizeof(struct nodo));
    crear_lista(&(nodoRaiz->hijos)); /*no se como importar las operaciones de lista*/

    nodoRaiz->elemento=e;
    nodoRaiz->padre=NULL;
    a->raiz=nodoRaiz;

}

/**
 Inserta y retorna un nuevo nodo en A.
 El nuevo nodo se agrega en A como hijo de NP, hermano izquierdo de NH, y cuyo rótulo es E.
 Si NH es NULL, el nuevo nodo se agrega como último hijo de NP.
 Si NH no corresponde a un nodo hijo de NP, finaliza indicando ARB_POSICION_INVALIDA.
 NP direcciona al nodo padre, mientras NH al nodo hermano derecho del nuevo nodo a insertar.
**/


tNodo a_insertar(tArbol a, tNodo np, tNodo nh, tElemento e){

    tNodo nodoInsertar=(tNodo) malloc(sizeof(struct nodo));
    nodoInsertar->elemento=e;
    nodoInsertar->padre=np;
    crear_lista(&nodoInsertar->hijos);

    tLista hijosDeNP;
    hijosDeNP=np->hijos;

    if(nh==NULL){ /*Caso el hermano es nulo*/
        l_insertar(hijosDeNP,l_ultima(hijosDeNP),nodoInsertar);
    }

    int encontre=0;
    tPosicion posViajante= (tPosicion) malloc(sizeof(struct celda));
    posViajante=(l_primera(hijosDeNP));
    int fin=l_longitud(hijosDeNP);

    int i;
    for(i=0;i<fin;i++){
        if(posViajante->elemento==nh){
            encontre=1;
            i=fin;
        }
        if(encontre==0){
            posViajante=l_siguiente(hijosDeNP,posViajante);
        }
    }

    if(encontre==0){
        exit(ARB_POSICION_INVALIDA);
    }
    else{
        l_insertar(hijosDeNP,l_siguiente(hijosDeNP,posViajante),nodoInsertar);
    }

    return nodoInsertar;
}




/**
 Elimina el nodo N de A.
 El elemento almacenado en el árbol es eliminado mediante la función fEliminar parametrizada.
 Si N es la raíz de A, y tiene un sólo hijo, este pasa a ser la nueva raíz del árbol.
 Si N es la raíz de A, y a su vez tiene más de un hijo, finaliza retornando ARB_OPERACION_INVALIDA.
 Si N no es la raíz de A y tiene hijos, estos pasan a ser hijos del padre de N, en el mismo orden y a partir de la posición que ocupa N en la lista de hijos de su padre.
**/
void a_eliminar(tArbol a, tNodo n, void (*fEliminar)(tElemento)){

    if(n==a_raiz(a)){
        if(l_longitud(n->hijos)==1){

            a->raiz=(l_primera(n->hijos)->elemento);
            a_raiz(a)->padre=NULL;

            fEliminar(n->elemento);
            free(n);

        }else{

            exit(ARB_POSICION_INVALIDA);

        }
    }else{

        if(l_longitud(n->hijos)==0){

            l_destruir(&(n->hijos),fEliminar);
            free(n);

        }else{

            tLista hijosDeN = (tLista) malloc(sizeof(struct celda));
            hijosDeN = n->hijos;

            tLista hijosDePadre = (tLista) malloc(sizeof(struct celda));
            hijosDePadre = n->padre->hijos;

            tPosicion posHijosN= (tPosicion) malloc(sizeof(struct celda));
            posHijosN=(l_primera(hijosDeN));

            tPosicion posHijosPadre= (tPosicion) malloc(sizeof(struct celda));
            posHijosPadre=(l_primera(hijosDePadre));

            while(posHijosPadre->elemento!=n){
                posHijosPadre=l_siguiente(hijosDePadre,posHijosPadre);
            }

            while(posHijosN!=l_ultima(hijosDeN)){

                l_insertar(hijosDePadre,posHijosPadre,posHijosN->elemento);
                posHijosN=l_siguiente(hijosDeN,posHijosN);

            }

            l_insertar(hijosDePadre,posHijosPadre,posHijosN->elemento);

            fEliminar(n->elemento);
            free(n);

        }

    }

}
ha yeet
/**
 Destruye el árbol A, eliminando cada uno de sus nodos.
 Los elementos almacenados en el árbol son eliminados mediante la función fEliminar parametrizada.
**/
void a_destruir(tArbol * a, void (*fEliminar)(tElemento)){

    postOrden(a,a_raiz(*a),fEliminar);

}

void postOrden(tArbol * a, tNodo n,void (*fEliminar)(tElemento)){

    tLista hijosDeN = (tLista) malloc(sizeof(struct celda));
    hijosDeN = n->hijos;

    if(l_longitud(hijosDeN)!=0){

        tPosicion posActual= (tPosicion) malloc(sizeof(struct celda));
        posActual=(l_primera(hijosDeN));

        tNodo hijoActual=(tNodo) malloc(sizeof(struct nodo));
        hijoActual = posActual->elemento;

        while(posActual!=l_fin(hijosDeN)){
            postOrden(a,hijoActual,fEliminar);
        }

    }

    l_destruir(&(n->hijos),fEliminar);
    fEliminar(n->elemento);
    free(n);

}



/**
Recupera y retorna el elemento del nodo N.
*/
tElemento a_recuperar(tArbol a, tNodo n){
    return n->elemento;
}



/**
Recupera y retorna el nodo correspondiente a la raíz de A.
**/
tNodo a_raiz(tArbol a){
    return a->raiz;
}



/**
 Obtiene y retorna una lista con los nodos hijos de N en A.
**/
tLista a_hijos(tArbol a, tNodo n){
    return n->hijos;
}



/**
 Inicializa un nuevo árbol en *SA.
 El nuevo árbol en *SA se compone de los nodos del subárbol de A a partir de N.
 El subarbol de A a partir de N debe ser eliminado de A.
**/
void a_sub_arbol(tArbol a, tNodo n, tArbol * sa){

}


