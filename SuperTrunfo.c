#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 100

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
} Cidade;

void cadastrarCarta(Cidade *cidade) {
    printf("Estado: ");
    scanf("%s", cidade->estado);
    printf("Código da carta: ");
    scanf("%d", &cidade->codigo);
    printf("Nome da cidade: ");
    scanf("%s", cidade->nome);
    printf("População: ");
    scanf("%d", &cidade->populacao);
    printf("Área: ");
    scanf("%f", &cidade->area);
    printf("PIB: ");
    scanf("%f", &cidade->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);

    cidade->densidade_populacional = cidade->populacao / cidade->area;
}

void exibirCarta(Cidade cidade) {
    printf("\nEstado: %s\n", cidade.estado);
    printf("Código da carta: %d\n", cidade.codigo);
    printf("Nome da cidade: %s\n", cidade.nome);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f\n", cidade.area);
    printf("PIB: %.2f\n", cidade.pib);
    printf("Número de pontos turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade populacional: %.2f\n", cidade.densidade_populacional);
}

void compararCartas(Cidade cidade1, Cidade cidade2, int criterio) {
    switch (criterio) {
        case 1:
            if (cidade1.populacao > cidade2.populacao)
                printf("A carta vencedora é: %s\n", cidade1.nome);
            else
                printf("A carta vencedora é: %s\n", cidade2.nome);
            break;
        case 2:
            if (cidade1.area > cidade2.area)
                printf("A carta vencedora é: %s\n", cidade1.nome);
            else
                printf("A carta vencedora é: %s\n", cidade2.nome);
            break;
        case 3:
            if (cidade1.pib > cidade2.pib)
                printf("A carta vencedora é: %s\n", cidade1.nome);
            else
                printf("A carta vencedora é: %s\n", cidade2.nome);
            break;
        case 4:
            if (cidade1.pontos_turisticos > cidade2.pontos_turisticos)
                printf("A carta vencedora é: %s\n", cidade1.nome);
            else
                printf("A carta vencedora é: %s\n", cidade2.nome);
            break;
        case 5:
            if (cidade1.densidade_populacional < cidade2.densidade_populacional)
                printf("A carta vencedora é: %s\n", cidade1.nome);
            else
                printf("A carta vencedora é: %s\n", cidade2.nome);
            break;
        default:
            printf("Critério inválido!\n");
    }
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int numCidades = 0;
    int opcao;
    int crit;

    printf("Quantas cidades deseja cadastrar? ");
    scanf("%d", &numCidades);

    for (int i = 0; i < numCidades; i++) {
        printf("Cadastro da carta %d:\n", i + 1);
        cadastrarCarta(&cidades[i]);
    }

    for (int i = 0; i < numCidades; i++) {
        printf("\nCarta %d:\n", i + 1);
        exibirCarta(cidades[i]);
    }

    printf("\nDigite o índice da primeira carta para comparar (1 a %d): ", numCidades);
    scanf("%d", &opcao);
    Cidade cidade1 = cidades[opcao - 1];

    printf("Digite o índice da segunda carta para comparar (1 a %d): ", numCidades);
    scanf("%d", &opcao);
    Cidade cidade2 = cidades[opcao - 1];

    printf("Escolha o critério de comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    scanf("%d", &crit);

    compararCartas(cidade1, cidade2, crit);

    return 0;
}
