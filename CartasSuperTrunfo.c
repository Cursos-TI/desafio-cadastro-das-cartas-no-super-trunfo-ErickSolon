#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define TOTAL_CIDADES (NUM_ESTADOS * CIDADES_POR_ESTADO)

float calcularDensidadePopulacional(unsigned int populacao, float area) {
    if (area > 0) {
        return populacao / area;
    } else {
        return 0;
    }
}

float calcularPibPerCapita(float pib, unsigned int populacao) {
    if (populacao > 0) {
        return pib / populacao;
    } else {
        return 0;
    }
}

int main() {
    char codigoCidade[TOTAL_CIDADES][4];
    char nome[TOTAL_CIDADES][100]; 
    unsigned int populacao[TOTAL_CIDADES];
    float area[TOTAL_CIDADES]; 
    float pib[TOTAL_CIDADES]; 
    unsigned int pontosTuristicos[TOTAL_CIDADES];
    int indice = 0;
    double pibPerCapita;
    double densidadePopulacional;

    for (char estado = 'A'; estado <= 'H'; estado++) {
        for (int cidade = 1; cidade <= 4; cidade++) {
            sprintf(codigoCidade[indice], "%c%02d", estado, cidade);
            printf("\n=== Cadastro da Cidade %s ===\n", codigoCidade[indice]);
            printf("Digite o nome da cidade: ");
            getchar();
            fgets(nome[indice], sizeof(nome[indice]), stdin); 
            nome[indice][strcspn(nome[indice], "\n")] = '\0';
            printf("Digite a população da cidade: ");
            scanf("%u", &populacao[indice]);
            printf("Digite a área da cidade (em km²): ");
            scanf("%f", &area[indice]); 
            printf("Digite o PIB da cidade (em bilhões): ");
            scanf("%f", &pib[indice]);
            printf("Digite o número de pontos turísticos da cidade: ");
            scanf("%u", &pontosTuristicos[indice]);

            indice++;
        }
    }

    printf("\n=== Cartas das cidades ===\n");
    for (int i = 0; i < TOTAL_CIDADES; i++) {
        densidadePopulacional = calcularDensidadePopulacional(populacao[i], area[i]);
        pibPerCapita = calcularPibPerCapita(pib[i], populacao[i]);

        printf("\n=== Código da cidade %s ===\n", codigoCidade[i]);
        printf("Nome da cidade: %s\n", nome[i]);
        printf("População da cidade: %u\n", populacao[i]);
        printf("Área da cidade: %.2f km²\n", area[i]);
        printf("PIB da cidade: %.2f bilhões\n", pib[i]);
        printf("Número de pontos turísticos: %u\n", pontosTuristicos[i]);
        printf("Densidade populacional: %.2f hab/km²\n", densidadePopulacional);
        printf("PIB per capita: %.2f bilhões/habitante\n", pibPerCapita);
    }


    return 0;
}
