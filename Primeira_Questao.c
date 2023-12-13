#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *anterior, *proximo;
} tListaDupla;

void inicializarLista(tListaDupla **lista) {
    *lista = NULL;
}

//Verificar se a lista está vazia
int listaVazia(tListaDupla *lista) {
    return lista == NULL;
}

// Criação da Lista Unitária
void criarListaUnitaria(tListaDupla **lista, int valor) {
    if (listaVazia(*lista)) {
        *lista = (tListaDupla *)malloc(sizeof(tListaDupla));
        (*lista)->dado = valor;
        (*lista)->anterior = (*lista)->proximo = NULL;
    } else {
        printf("A lista nao esta vazia ! Nao foi possivel criar a lista unitaria !\n");
    }
}

//Inserir elemento na lista duplamente encadeada
void inserirElemento(tListaDupla **lista, int valor) {
    tListaDupla *novo = (tListaDupla *)malloc(sizeof(tListaDupla));
    novo->dado = valor;
    novo->anterior = novo->proximo = NULL;

    if (listaVazia(*lista)) {
        *lista = novo;
    } else {
        tListaDupla *atual = *lista;
        tListaDupla *anterior = NULL;

        while (atual != NULL && atual->dado < valor) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL) {
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        } else {
            anterior->proximo = novo;
            novo->anterior = anterior;
            novo->proximo = atual;
            if (atual != NULL) {
                atual->anterior = novo;
            }
        }
    }
}

//Remover elemento da lista duplamente encadeada
void removerElemento(tListaDupla **lista, int valor) {
    if (listaVazia(*lista)) {
        printf("A lista esta vazia. Nao foi possivel remover o elemento !\n");
        return;
    }

    tListaDupla *atual = *lista;
    tListaDupla *anterior = NULL;

    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Elemento nao encontrado. Nao foi possivel remover !\n");
        return;
    }

    if (anterior == NULL) {
        *lista = atual->proximo;
        if (*lista != NULL) {
            (*lista)->anterior = NULL;
        }
    } else {
        anterior->proximo = atual->proximo;
        if (atual->proximo != NULL) {
            atual->proximo->anterior = anterior;
        }
    }

    free(atual);
}

//Pesquisar elemento na lista dupla
int pesquisarElemento(tListaDupla *lista, int valor) {
    tListaDupla *atual = lista;

    while (atual != NULL) {
        if (atual->dado == valor) {
            printf("Elemento %d encontrado na lista.\n", valor);
            return 1;
        }
        atual = atual->proximo;
    }

    printf("Elemento %d nao encontrado na lista.\n", valor);
    return 0;
}

//Exibir lista em ordem crescente e descrescente, verificando através do if dentro do método
void exibirLista(tListaDupla *lista, int ordem) {
    if (listaVazia(lista)) {
        printf("A lista esta vazia !\n");
        return;
    }

    if (ordem == 1) {// Crescente
        printf("Listagem em ordem crescente:\n");
        while (lista != NULL) {
            printf("%d ", lista->dado);
            lista = lista->proximo;
        }
    } else {// Descrescente
        tListaDupla *ultimo = lista;
        while (ultimo->proximo != NULL) {
            ultimo = ultimo->proximo;
        }

        printf("Listagem em ordem decrescente:\n");
        while (ultimo != NULL) {
            printf("%d ", ultimo->dado);
            ultimo = ultimo->anterior;
        }
    }

    printf("\n");
}

// Destruir lista, liberando a alocação de mémoria
void destruirLista(tListaDupla **lista) {
    tListaDupla *atual = *lista;
    tListaDupla *prox = NULL;

    while (atual != NULL) {
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }

    *lista = NULL;
}

int main() {
    tListaDupla *lista;
    inicializarLista(&lista);

    int opcao, valor;

    do {
        printf("\n1. Verificar se a lista esta vazia\n");
        printf("2. Criar lista unitaria\n");
        printf("3. INSERIR elemento \n");
        printf("4. REMOVER elemento \n");
        printf("5. Pesquisar elemento \n");
        printf("6. Exibir lista crescente\n");
        printf("7. Exibir lista decrescente\n");
        printf("8. Finalizar o programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                if (listaVazia(lista)) {
                    printf("A lista esta vazia !\n");
                } else {
                    printf("A lista nao esta vazia !\n");
                }
                break;
            case 2:
                printf("Digite o valor para criar a lista unitaria: ");
                scanf("%d", &valor);
                criarListaUnitaria(&lista, valor);
                break;
            case 3:
                printf("Digite o valor para inserir na lista: ");
                scanf("%d", &valor);
                inserirElemento(&lista, valor);
                break;
            case 4:
                printf("Digite o valor para remover da lista: ");
                scanf("%d", &valor);
                removerElemento(&lista, valor);
                break;
            case 5:
                printf("Digite o valor para pesquisar na lista: ");
                scanf("%d", &valor);
                pesquisarElemento(lista, valor);
                break;
            case 6:
                exibirLista(lista, 1);
                break;
            case 7:
                exibirLista(lista, 2);
                break;
            case 8:
                destruirLista(&lista);
                printf("Programa finalizado. Lista destruida.\n");
                break;
            default:
                printf("Opcao invalida ! Tente novamente !\n");
        }
    } while (opcao != 8);

    return 0;
}
