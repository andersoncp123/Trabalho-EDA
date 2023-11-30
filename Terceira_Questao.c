#include <stdio.h>
#include <stdlib.h>

//criar struct
typedef struct no{
    int dado;
    struct no *proximo;
} tFilaSimples;

//testar se a fila está vazia
int testeFilaVazia(tFilaSimples *fila) {
    if (fila == NULL || fila->proximo == NULL) return 1;
    else return 0;
}

//criar uma fila unitária (se estiver vazia)
tFilaSimples *criarFila(int novoDado) {
    tFilaSimples *novoNo = malloc(sizeof(tFilaSimples));

    novoNo->dado = novoDado;
    novoNo->proximo = NULL;
    return novoNo;
}

//enfileirar números
tFilaSimples *enfileirar(tFilaSimples *inicio, int num){
    tFilaSimples *temp = inicio, *novo;

    while (temp->proximo != NULL){
        temp = temp->proximo;
    }

    novo = malloc(sizeof(tFilaSimples));
    novo->dado = num;
    novo->proximo = NULL;
    temp->proximo = novo;
    return inicio;
}

//desenfileirar números (caso não esteja vazia)
tFilaSimples *desenfileirar(tFilaSimples *inicio){
    tFilaSimples *novo;

    if (inicio == NULL) return inicio;

    novo = inicio->proximo;
    free(inicio);
    return novo;
}

//mostrar os elementos conforme dispostos na fila
void imprimiFila(tFilaSimples *inicio){
    tFilaSimples *temp = inicio;

    if (temp == NULL){
        printf("Fila Vázia !\n");
    }else{
        while (temp != NULL){
            printf("%d",temp ->dado);
            if (temp->proximo != NULL) printf(" - ");
            temp = temp ->proximo;
        }
    }
    printf("\n");
}

//opção para finalizar o programa, limpar a lista e mencionar a quantidade de nós liberados
void limparFila(tFilaSimples *inicio){
    tFilaSimples *temp = inicio;
    int count =0;

    if (temp == NULL){
        printf("\nFila Vazia !\n");
        count = 0;
    }else{
        while (temp != NULL){
            temp = temp ->proximo;
            free(inicio);
            inicio = temp;
            count += 1;
        }
    }
    printf("Quantidade de nos apagados: %d\n", count);
}

//menu
int menu(){
        int opcao;
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Mostrar Fila\n");
        printf("4 - Limpar Fila\n");
        printf("5 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%i",&opcao);
        return opcao;
}

//main
int main(){
    tFilaSimples *fila = NULL;
    int opcao;

    do {
        opcao = menu();

        switch (opcao) {
            case 1: {
                int novoDado;
                printf("Digite o numero a ser enfileirado: ");
                scanf("%d", &novoDado);
                if (fila != NULL) {
                    fila = enfileirar(fila, novoDado);
                }else{
                    fila = criarFila(novoDado);
                }
                break;
            }
            case 2: {
                fila = desenfileirar(fila);
                break;
            }
            case 3: {
                printf("Conteudo da fila:\n");
                imprimiFila(fila);
                break;
            }
            case 4: {
                limparFila(fila);
                fila = NULL;
                printf("Fila limpa.\n");
                break;
            }
            case 5: {
                printf("Saindo do programa...\n");
                limparFila(fila);
                exit(0);
                break;
            }
            default: {
                printf("Opcao invalida!\n");
                break;
            }
        }
    } while (opcao != 5);

    return 0;
}