#include <stdio.h>
#include <stdlib.h>

// criar struct
typedef struct no
{
    int dado;
    struct no *proximo;
} tPilhaSimples;

// testar se a pilha está vazia
int testePilhaVazia(tPilhaSimples *pilha)
{
    if (pilha == NULL)
    { // Verifica se a pilha está vazia;
        return 1;
    }
    else
    {
        return 0;
    }
}

// criar uma pilha unitária (se estiver vazia)
tPilhaSimples *criarPilha(int dadoNovo)
{
    tPilhaSimples *novoNo = (tPilhaSimples *)malloc(sizeof(tPilhaSimples)); // Fazendo a alocaçao dinâmica
    if (novoNo != NULL)
    {
        novoNo->dado = dadoNovo;
        novoNo->proximo = NULL;
    }
    return novoNo;
}

// empilhar números
tPilhaSimples *empilhar(int dadoNovo, tPilhaSimples *topoPilha)
{
    tPilhaSimples *novoTopoPilha;
    novoTopoPilha = malloc(sizeof(tPilhaSimples));
    if (novoTopoPilha == NULL)
    {
        return topoPilha; // Pilha Vázia
    }
    else
    {
        novoTopoPilha->dado = dadoNovo;
        novoTopoPilha->proximo = topoPilha;
        printf("Elemento adicionado !\n");
        printf("\n");
        return novoTopoPilha;
    }
}
// desempilhar números (caso não esteja vazia)
tPilhaSimples *desimpilhar(tPilhaSimples *topoPilha)
{
    tPilhaSimples *novoTopoPilha;
    novoTopoPilha = malloc(sizeof(tPilhaSimples));
    if (novoTopoPilha == NULL)
    { // Verificação se a pilha está vázia
        printf("Pilha Vazia, não é possível desimpilhar !\n");
        printf("\n");
        return topoPilha; // Pilha Vázia
    }
    else
    {
        novoTopoPilha = topoPilha->proximo;
        printf("Elemento %d foi removido com sucesso !\n",topoPilha ->dado);
        printf("\n");
        free(topoPilha); 
        return novoTopoPilha;
    }
}
// mostrar os elementos em forma de pilha
void mostrarPilha(tPilhaSimples *pilha)
{
    tPilhaSimples *auxiliar;
    auxiliar = pilha;
    if (auxiliar == NULL)
    {
        printf("Pilha Vázia !\n");
    }
    else
    {
        while (auxiliar != NULL)
        {
            printf("%d\n", auxiliar->dado);
            auxiliar = auxiliar->proximo;
        }
    }
}
// opção para finalizar o programa, limpar a pilha e mencionar a quantidade de nós liberados
void limparPilha(tPilhaSimples *pilha)
{
    tPilhaSimples *auxiliar;
    int contador = 0;

    while (pilha != NULL)
    {
        auxiliar = pilha->proximo;
        free(pilha);
        pilha = auxiliar;
        contador++;
    }

    printf("Foram apagados %d nos!\n", contador);
}

int menu()
{
    int opcao;
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("3 - Mostrar Pilha\n");
    printf("4 - Limpar Pilha\n");
    printf("5 - Verificar se a fila esta vazia\n");
    printf("6 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%i", &opcao);
    return opcao;
}

int main()
{
    tPilhaSimples *pilha = NULL;
    int opcao;

    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
        {
            int dadoNovo;
            printf("Digite o numero a ser empilhado: ");
            scanf("%d", &dadoNovo);
            pilha = empilhar(dadoNovo, pilha);
            break;
        }
        case 2:
        {
            pilha = desimpilhar(pilha);
            break;
        }
        case 3:
        {
            printf("Conteudo da pilha:\n");
            printf("\n");
            mostrarPilha(pilha);
            printf("\n");
            break;
        }
        case 4:
        {
            limparPilha(pilha);
            pilha = NULL;
            printf("Pilha limpa.\n");
            printf("\n");
            break;
        }
        case 5:
        {
            if (testePilhaVazia(pilha)) {
                printf("A pilha esta vazia.\n");
                printf("\n");
            } else {
                printf("A pilha nao esta vazia.\n");
                printf("\n");
            }
            break;
        }

        case 6:
        {
            printf("Saindo do programa...\n");
            limparPilha(pilha);
            break;
        }
        default:
        {
            printf("Opcao invalida!\n");
            printf("\n");
            break;
        }
        }
    } while (opcao != 6);

    return 0;
}
