#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "lista.h"
#include "arbol.h"

#define ARB_OPERACION_INVALIDA      10
#define ARB_POSICION_INVALIDA       11
#define ARB_ERROR_MEMORIA           12



/**
Inicializa un �rbol vac�o.
Una referencia al �rbol creado es referenciado en *A.
**/
void crear_arbol(tArbol * a){

    tArbol arbol=(tArbol) malloc(sizeof(struct arbol));
    arbol->raiz=NULL;
    a=&arbol;


}

/**
Crea la ra�z de A.
Si A no es vac�o, finaliza indicando ARB_OPERACION_INVALIDA.
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
 El nuevo nodo se agrega en A como hijo de NP, hermano izquierdo de NH, y cuyo r�tulo es E.
 Si NH es NULL, el nuevo nodo se agrega como �ltimo hijo de NP.
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
        l_insertar(hijosDeNP,l_ultima(hijosDeNP),e);
    }

    while(/**recorrer la lista hasta encontrar nh**/);

    if(/**no se encontro nh**/){
        exit(ARB_POSICION_INVALIDA);
    }
    else/**se encontro nh**/{

        /**ponerlo a la izquierda de NH**/
    }


    return nodoInsertar;


}




/**
 Elimina el nodo N de A.
 El elemento almacenado en el �rbol es eliminado mediante la funci�n fEliminar parametrizada.
 Si N es la ra�z de A, y tiene un s�lo hijo, este pasa a ser la nueva ra�z del �rbol.
 Si N es la ra�z de A, y a su vez tiene m�s de un hijo, finaliza retornando ARB_OPERACION_INVALIDA.
 Si N no es la ra�z de A y tiene hijos, estos pasan a ser hijos del padre de N, en el mismo orden y a partir de la posici�n que ocupa N en la lista de hijos de su padre.
**/
void a_eliminar(tArbol a, tNodo n, void (*fEliminar)(tElemento)){

}

/**
 Destruye el �rbol A, eliminando cada uno de sus nodos.
 Los elementos almacenados en el �rbol son eliminados mediante la funci�n fEliminar parametrizada.
**/
void a_destruir(tArbol * a, void (*fEliminar)(tElemento)){
    //recorre en postOrden
    postOrden(a,a->raiz);

}

void postOrden(tArbol * a, tNodo n){

    while(){//para cada hijo de n
         postOrden(a,hijoActual);
    }

    a_eliminar(a,n,?);


}



/**
Recupera y retorna el elemento del nodo N.
*/
tElemento a_recuperar(tArbol a, tNodo n){
    return n->elemento;
}



/**
Recupera y retorna el nodo correspondiente a la ra�z de A.
**/
tNodo a_raiz(tArbol a){
    return a->raiz;
}



/**
 Obtiene y retorna una lista con los nodos hijos de N en A.
**/
tLista a_hijos(tArbol a, tNodo n){
    return n->hijos; //No se si hay que crear una lista nueva.
}



/**
 Inicializa un nuevo �rbol en *SA.
 El nuevo �rbol en *SA se compone de los nodos del sub�rbol de A a partir de N.
 El subarbol de A a partir de N debe ser eliminado de A.
**/
void a_sub_arbol(tArbol a, tNodo n, tArbol * sa){

}

