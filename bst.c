
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
no * inserir (no* raiz, tipo_dado elemento){
    if(raiz == NULL) {
        no *novo = (no *) malloc(sizeof(struct no));
        novo->valor = elemento;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    } else {
           if(elemento > raiz->valor) {
                raiz->dir = inserir(raiz->dir, elemento);
           } else {
                raiz->esq = inserir(raiz->esq, elemento);
           }
           return raiz;
    }
}

no* buscar(no* raiz, tipo_dado elemento){
    if (raiz == (no *) NULL){
        return NULL;
    }
    else{
        if(raiz->valor > elemento){
            buscar(raiz->esq, elemento);
        } else if(raiz->valor < elemento){
            buscar(raiz->dir, elemento);
        } else {
            return raiz;
        }
    }
}

int elementoPai(no* raiz, tipo_dado elemento){
    if(raiz == NULL){
        return -1;
    }
    else{
        if(raiz->valor > elemento){
            no* aux1 = raiz->esq;
            if(aux1->valor == elemento){
                return raiz->valor;
            } else if(aux1->valor > elemento){
                return -1;
            }
            elementoPai(raiz->esq, elemento);
        } else if(raiz->valor < elemento){
            no* aux2 = raiz->dir;
            if(aux2->valor == elemento){
                return raiz->valor;
            } else if(aux2->valor < elemento){
                return -1;
            }
            elementoPai(raiz->dir, elemento);
        }
    }
}

void preorder(no* raiz){
    if(raiz == NULL) ;
    else {
        printf("[%d]", raiz->valor);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}


void inorder(no* raiz){
    if(raiz == NULL) ;
    else {
        inorder(raiz->esq);
        printf("[%d]", raiz->valor);
        inorder(raiz->dir);
    }
}

void posorder(no* raiz){
    if(raiz == NULL) ;
    else {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}

void sucessor(no* raiz, tipo_dado elemento){
    if (raiz == (no *) NULL){
        printf("-1\n");
        return;
    }
    no* aux = buscar(raiz, elemento);
    if(aux->dir != NULL){
        no* aux1 = aux->dir;
        printf("%d\n", aux1->valor);
    }
    if(aux->esq != NULL){
        no* aux2 = aux->esq;
        printf("%d\n", aux2->valor);
    }
}

void antecessor(no* raiz, tipo_dado elemento){
    if(raiz == NULL){
        printf("-1\n");
    }
    else{
        if(raiz->valor > elemento){
            no* aux1 = raiz->esq;
            if(aux1->valor == elemento){
                printf("%d\n",raiz->valor);
            } else if(aux1->valor > elemento){
                printf("-1\n");
            }
            antecessor(raiz->esq, elemento);
        } else if(raiz->valor < elemento){
            no* aux2 = raiz->dir;
            if(aux2->valor == elemento){
                printf("%d\n", raiz->valor);
            } else if(aux2->valor < elemento){
                printf("-1\n");
            }
            antecessor(raiz->dir, elemento);
        }
    }
}

int altura(no* raiz){
    int alturaEsquerda, alturaDireita;
    if(raiz == NULL){
        return 0;
    } else {
        alturaEsquerda = altura(raiz->esq);
        alturaDireita = altura(raiz->dir);
        if (alturaEsquerda < alturaDireita){
            return alturaDireita + 1;
        }
        else{
            return alturaEsquerda + 1;
        }
    }
}

int maior(no* raiz){
    if(raiz->dir == NULL){
        return raiz->valor;
    } else {
        maior(raiz->dir);
    }
}

int menor(no* raiz){
    if(raiz->esq == NULL){
        return raiz->valor;
    } else {
        menor(raiz->esq);
    }
}

no* remover(no* raiz, tipo_dado elemento){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->valor == elemento){
            if(raiz->dir == NULL && raiz->esq == NULL){
                raiz = NULL;
            } else if(raiz->dir != NULL && raiz->esq == NULL){
                raiz = raiz->dir;
            } else if(raiz->esq != NULL && raiz->dir == NULL){
                raiz = raiz->esq;
            } else if(raiz->esq != NULL && raiz->dir != NULL){
                raiz->valor = maior(raiz->esq);
                raiz->esq = remover(raiz->esq, raiz->valor);
            }
            return raiz;
    }
    if(elemento > raiz->valor) {
			raiz->dir = remover(raiz->dir, elemento);
	} else {
			raiz->esq = remover(raiz->esq, elemento);
	}
	return raiz;
}
