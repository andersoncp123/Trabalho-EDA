//criar struct
typedef struct no{
    int dado;
    struct no *proximo; 
} tPilhaSimples;

//testar se a pilha está vazia
int testePilhaVazia(tPilhaSimples *pilha) {
    if (pilha == NULL || pilha->proximo == NULL) {// Verifica se a pilha está vazia ou o próximo elemento é NULL;
        return 0;
    } else {
        return 1;
    }
}

//criar uma pilha unitária (se estiver vazia)
tPilhaSimples *criarPilha(int dadoNovo) {
    tPilhaSimples *novoNo = (tPilhaSimples *)malloc(sizeof(tPilhaSimples));// Fazendo a alocaçao dinâmica 
    if (novoNo != NULL) {
        novoNo->dado = dadoNovo;
        novoNo->proximo = NULL;
    }
    return novoNo;
}

//empilhar números
tPilhaSimples *empilhar(int dadoNovo,tPilhaSimples *topoPilha){
    tPilhaSimples *novoTopoPilha;
    novoTopoPilha = malloc(sizeof(tPilhaSimples));
    if (novoTopoPilha == NULL){
        return topoPilha; // Pilha Vázia 
    }else{
        novoTopoPilha ->dado = dadoNovo;
        novoTopoPilha ->proximo = topoPilha;
        return novoTopoPilha;
    }
}
//desempilhar números (caso não esteja vazia)
tPilhaSimples *empilhar(tPilhaSimples *topoPilha){
    tPilhaSimples *novoTopoPilha;
    novoTopoPilha = malloc(sizeof(tPilhaSimples));
    if (novoTopoPilha == NULL){
        return topoPilha; // Pilha Vázia 
    }else{
        novoTopoPilha = topoPilha -> proximo;
        free(topoPilha);
        return novoTopoPilha;
    }
}
//mostrar os elementos em forma de pilha

//opção para finalizar o programa, limpar a pilha e mencionar a quantidade de nós liberados