// Desafio nível novato
#include <stdio.h>
#include <string.h>



// Função para calcular o PIB per capita
float pib_per_capita(float pib, int population) {
    if (population == 0) return 0.0f;
    return (pib * 1000000000) / population;
}

// Função para calcular a densidade populacional
float calc_densidade_populacional(int population, float area) {
    if (area == 0.0f) return 0.0f;
    return population / area;
}

// Função para calcular o super poder
float calc_super_pow(int population, int pontosTuristicos, float area, 
                    float pib, float densidadePopulacional, float pibPerCapita) {
    return population + pontosTuristicos + area + pib + densidadePopulacional + pibPerCapita;
}

// Função auxiliar para limpar o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char estadoCidade[3], codCarta[10], nome[50];
    int population, pontosTuristicos;
    float area, pib;
    
    char estadoCidade2[3], codCarta2[10], nome2[50];
    int population2, pontosTuristicos2;
    float area2, pib2;

    // Cadastro da primeira carta
    printf("Cadastro da carta 01\n");
    printf("Digite o estado da carta: ");
    scanf("%2s", estadoCidade);
    limpar_buffer();
    printf("Digite o código da cidade: ");
    scanf("%9s", codCarta);
    limpar_buffer();
    printf("Digite o nome da cidade: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("Digite a população da cidade: ");
    scanf("%d", &population);
    printf("Digite a área da cidade (km²): ");
    scanf("%f", &area);
    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib);
    printf("Digite a quantidade de pontos turísticos da cidade: ");
    scanf("%d", &pontosTuristicos);
    limpar_buffer();

    // Cálculos para a primeira carta
    float densidadePopulacional = calc_densidade_populacional(population, area);
    float pibPerCapita = pib_per_capita(pib, population);
    float superPow = calc_super_pow(population, pontosTuristicos, area, pib, densidadePopulacional, pibPerCapita);

    // Exibição dos dados da primeira carta
    printf("\nDados da carta cadastrada:\n");
    printf("Estado: %s\n", estadoCidade);
    printf("Código da Carta: %s\n", codCarta);
    printf("Nome da Cidade: %s\n", nome);
    printf("População: %d\n", population);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Pontos turísticos: %d\n", pontosTuristicos);
    printf("Densidade Populacional: %.2f pessoas/km²\n", densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita);
    printf("Super Poder: %.2f\n\n", superPow);

    // Cadastro da segunda carta
    printf("Cadastro da carta 02\n");
    printf("Digite o estado da carta: ");
    scanf("%2s", estadoCidade2);
    limpar_buffer();
    printf("Digite o código da cidade: ");
    scanf("%9s", codCarta2);
    limpar_buffer();
    printf("Digite o nome da cidade: ");
    fgets(nome2, sizeof(nome2), stdin);
    nome2[strcspn(nome2, "\n")] = '\0';
    printf("Digite a população da cidade: ");
    scanf("%d", &population2);
    printf("Digite a área da cidade (km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib2);
    printf("Digite a quantidade de pontos turísticos da cidade: ");
    scanf("%d", &pontosTuristicos2);
    limpar_buffer();

    // Cálculos para a segunda carta
    float densidadePopulacional2 = calc_densidade_populacional(population2, area2);
    float pibPerCapita2 = pib_per_capita(pib2, population2);
    float superPow2 = calc_super_pow(population2, pontosTuristicos2, area2, pib2, densidadePopulacional2, pibPerCapita2);

    // Exibição dos dados da segunda carta
    printf("\nDados da carta cadastrada:\n");
    printf("Estado: %s\n", estadoCidade2);
    printf("Código da Carta: %s\n", codCarta2);
    printf("Nome da Cidade: %s\n", nome2);
    printf("População: %d\n", population2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f pessoas/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n\n", superPow2);

    // Comparação das cartas
    printf("Comparando as cartas:\n");
    printf("Carta 1 - %s (%s): População %d\n", estadoCidade, nome, population);
    printf("Carta 2 - %s (%s): População %d\n", estadoCidade2, nome2, population2);
    
    if (population > population2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nome);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
    }

    return 0;
}