#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        int opcao;

       no * arvore=NULL;
        while(1==1) {
            printf("Digite O Numero Relativo a Opcao:\n1 - Inserir elemento;\n2 - Percurso em pre-order;\n3 - Percurso em in-order;\n4 - Percurso em pos-order;\n5 - Remover elemento;\n6 - Exibir maior elemento;\n7 - Exibir menor elemento;");
            printf("\n8 - Exibir altura da arvore;\n9 - Procurar o pai de um elemento;\n10 - Dado um elemento, encontrar seu sucessor;\n11 - Dado um elemento, encontrar seu antecessor;\n999 - Encerrar o programa;\n");
            scanf("%d", &opcao);
            switch(opcao) {
                int n;
                case 1:
                    printf("Digite o valor a ser inserido:\n");
                    scanf("%d", &n);
                    arvore = inserir(arvore, n);
                    break;
                case 2:
                    preorder(arvore);
                    printf("\n");
                    break;
                case 3:
                    inorder(arvore);
                    printf("\n");
                    break;
                case 4:
                    posorder(arvore);
                    printf("\n");
                    break;
                case 5:
                    printf("Digite o Valor do Elemento:\n");
                    scanf("%d", &n);
                    arvore = remover(arvore, n);
                    break;
                case 6:
                    printf("\n[%d]\n", maior(arvore));
                    break;
                case 7:
                    printf("\n[%d]\n", menor(arvore));
                    break;
                case 8:
                    printf("\n[%d]\n", altura(arvore));
                    break;
                case 9:
                    printf("Digite o valor do Elemento:\n");
                    scanf("%d", &n);
                    printf("\n[%d]\n", elementoPai(arvore, n));
                    break;
                case 10:
                    printf("Digite o valor do Elemento:\n");
                    scanf("%d", &n);
                    sucessor(arvore, n);
                    break;
                case 11:
                    printf("Digite o Valor do Elemento:\n");
                    scanf("%d", &n);
                    antecessor(arvore, n);
                    break;
                case 999:
                    exit(0);
            }

        }

}

