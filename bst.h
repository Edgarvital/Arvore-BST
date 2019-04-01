#ifndef BST_H
#define BST_H

typedef  int  tipo_dado;

typedef struct no {
    tipo_dado valor;
    struct no *esq, *dir;
} no;

no* inserir (no* raiz, tipo_dado elemento);
no* buscar(no* raiz, tipo_dado elemento);
no* remover(no* raiz, tipo_dado elemento);

void preorder(no* raiz);
void inorder(no* raiz);
void posorder(no* raiz);
void sucessor(no* raiz, tipo_dado elemento);
void antecessor(no* raiz, tipo_dado elemento);

int elementoPai(no* raiz, tipo_dado elemento);
int altura(no* raiz);
int maior(no* raiz);
int menor(no* raiz);

#endif

