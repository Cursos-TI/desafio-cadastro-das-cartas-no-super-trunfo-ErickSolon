#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define TOTAL_CIDADES (NUM_ESTADOS * CIDADES_POR_ESTADO)

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    char codigoCidade[TOTAL_CIDADES][4];
    char nome[TOTAL_CIDADES][100]; 
    unsigned int populacao[TOTAL_CIDADES];
    float area[TOTAL_CIDADES]; 
    float pib[TOTAL_CIDADES]; 
    unsigned int pontosTuristicos[TOTAL_CIDADES];
    int indice = 0;

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
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

    printf("\n=== Cartas das Cidades ===\n");
    for (int i = 0; i < TOTAL_CIDADES; i++) {
        printf("\n=== Código da Cidade %s ===\n", codigoCidade[i]);
        printf("Nome da cidade: %s\n", nome[i]);
        printf("População da cidade: %u\n", populacao[i]);
        printf("Área da cidade: %.2f km²\n", area[i]);
        printf("PIB da cidade: %.2f bilhões\n", pib[i]);
        printf("Número de pontos turísticos: %u\n", pontosTuristicos[i]);
    }


    return 0;
}
