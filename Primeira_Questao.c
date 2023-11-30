#include <stdio.h>
#include <stdlib.h>
//criar struct
typedef struct no{
    int dado;
    struct no *anterior,*proximo;
} tListaDupla;

//--------OS DADOS DA LISTA DEVEM SER DE FORMA CRESCENTE--------

//informar se essa lista está ou não vazia
int testePilha(tListaDupla *tListaDupla){
    if(tListaDupla == NULL || tListaDupla ->proximo == NULL){
        printf("Lista Vázia !\n");
        return 1;
    }else{
        return 0;
    }
}
//opção para criar uma lista unitária (se estiver vazia)
tListaDupla *criarLista(int dadoNovo){
    
}
//inserção de números inteiros (manter a ordem)

//remoção de qualquer número (manter a ordem)

//pesquisar um número inteiro (informar caso não seja encontrado)

//listar de forma crescente e decrescente

//opção para finalizar o programa, limpar a lista e mencionar a quantidade de nós liberados