#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n=== MOCHILA – NÍVEL AVENTUREIRO ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item por nome\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            if(total >= MAX_ITENS) {
                printf("A mochila está cheia!\n");
                continue;
            }

            printf("Nome do item: ");
            scanf("%s", mochila[total].nome);

            printf("Tipo: ");
            scanf("%s", mochila[total].tipo);

            printf("Quantidade: ");
            scanf("%d", &mochila[total].quantidade);

            total++;
            printf("Item adicionado!\n");
        }
        else if(opcao == 2) {
            char nomeRemover[30];
            printf("Nome do item a remover: ");
            scanf("%s", nomeRemover);

            int achou = 0;
            for(int i = 0; i < total; i++) {
                if(strcmp(mochila[i].nome, nomeRemover) == 0) {
                    for(int j = i; j < total - 1; j++)
                        mochila[j] = mochila[j+1];
                    total--;
                    achou = 1;
                    printf("Item removido!\n");
                    break;
                }
            }
            if(!achou)
                printf("Item não encontrado.\n");
        }
        else if(opcao == 3) {
            printf("\n--- Itens na mochila ---\n");
            for(int i = 0; i < total; i++) {
                printf("%d) %s | %s | qtd: %d\n",
                       i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            }
        }
        else if(opcao == 4) {
            char nomeBuscado[30];
            printf("Nome do item: ");
            scanf("%s", nomeBuscado);

            int achou = 0;
            for(int i = 0; i < total; i++) {
                if(strcmp(mochila[i].nome, nomeBuscado) == 0) {
                    printf("\nItem encontrado!\n");
                    printf("Nome: %s\n", mochila[i].nome);
                    printf("Tipo: %s\n", mochila[i].tipo);
                    printf("Quantidade: %d\n", mochila[i].quantidade);
                    achou = 1;
                    break;
                }
            }
            if(!achou)
                printf("Item não encontrado.\n");
        }

    } while(opcao != 0);

    return 0;
}
