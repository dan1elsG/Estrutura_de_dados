#include <stdio.h>
#include <stdlib.h>

static  char categorias[3][20] = {"Eletrodomestico", "Informatica", "Moda"};  // MEMORIA ESTATICA


void cadastro_praduto(int sku, char nome_produto[100], int quantidade, char categoria[20]){
    FILE *arquivo = fopen("estoque.txt", "a");
    fprintf(arquivo, "SKU do produto: %i, Produto: %s, Quantidade: %i, Categoria: %s\n",sku, nome_produto, quantidade, categoria);
    printf("Produto cadastrado com sucesso!\n");
    printf("----------------------------------------------------------------------\n");
    fclose(arquivo);
}

void ver_estoque(){
    char linha[100]; // MEMORIA AUTOMATICA
    int contador_linha = 1;
    FILE *arquivo = fopen("estoque.txt", "r");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) { 
        printf("----------------------------------------------------------------------\n");
        printf(" %d - Item: %s", contador_linha, linha);
        contador_linha = contador_linha + 1;
    }
 }

int main() {
    char *nome_produto = (char*)malloc(20 * sizeof(char)); // MEMORIA DINAMICA
    int *opcao = (int*)malloc(sizeof(int)); // MEMORIA DINAMICA
    int *quantidade = (int*)malloc(sizeof(int)); // MEMORIA DINAMICA
    int *sku = (int*)malloc(sizeof(int)); // MEMORIA DINAMICA
    int *opcao_categoria = (int*)malloc(sizeof(int)); // MEMORIA DINAMICA
    int *quantidade_produto = (int*)malloc(sizeof(int)); // MEMORIA DINAMICA

    if (!nome_produto || !opcao || !quantidade || !sku || !opcao_categoria || !quantidade_produto) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    while (1){
        if(*opcao == 3){
            break;
        }
        printf("----------------------------------------------------------------------\n");
        printf("|                     SISTEMA DE ESTOQUE DE PRODUTOS                 |\n");
        printf("----------------------------------------------------------------------\n");
        printf("|                        MENU DO SISTEMA                             |\n");
        printf("| 1 - CADASTRO DE PRODUTOS                                           |\n"
               "| 2 - VER ESTOQUE DE PRODUTOS                                        |\n"
               "| 3 - FECHAR O PROGRAMA                                              |\n"
               "----------------------------------------------------------------------\n"
               "Escolha uma das opcoes: ");
        scanf("%d", opcao);

        switch (*opcao) {
        case 1:
            printf("----------------------------------------------------------------------\n");
            printf("Deseja cadastrar quantos produtos: ");
            scanf("%d", quantidade);
            printf("\n----------------------------------------------------------------------\n");

            for (int j = 0; j < *quantidade; j++) {
                for (int i = 0; i < 3; i++) {
                    printf("Categoria[%d]: %s\n", i, categorias[i]);
                }
                printf("Selecione a Categoria do produto: ");
                scanf("%d", opcao_categoria);
                printf("\n----------------------------------------------------------------------\n");
                printf("Digite o SKU do produto: ");
                scanf("%d", sku);
                printf("Nome Produto: ");
                scanf("%s", nome_produto);
                printf("Quantidade do produto: ");
                scanf("%d", quantidade_produto);
                printf("\n----------------------------------------------------------------------\n");
                cadastro_praduto(*sku, nome_produto, *quantidade_produto, categorias[*opcao_categoria]);
            }
            break;

        case 2:
            ver_estoque();
            break;
        case 3:
        printf("\n----------------------------------------------------------------------\n");
        printf("Saindo do programa.....\n");
        printf("----------------------------------------------------------------------\n");
            break;
        default:
            printf("----------------------------------------------------------------------\n");
            printf("Opcao invalida tente novamente!\n");
            printf("----------------------------------------------------------------------\n");
            continue;
        }
    }
    free(opcao);
    free(quantidade);
    free(sku);
    free(opcao_categoria);
    free(quantidade_produto);
    free(nome_produto);

    return 0;
}