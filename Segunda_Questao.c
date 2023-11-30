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
    if (pilha == NULL || pilha->proximo == NULL)
    { // Verifica se a pilha está vazia ou o próximo elemento é NULL;
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
        return topoPilha; // Pilha Vázia
    }
    else
    {
        novoTopoPilha = topoPilha->proximo;
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
    printf("5 - Sair\n");
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
            mostrarPilha(pilha);
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
            printf("Saindo do programa...\n");
            limparPilha(pilha);
            break;
        }
        default:
        {
            printf("Opcao invalida!\n");
            break;
        }
        }
    } while (opcao != 5);

    return 0;
}
