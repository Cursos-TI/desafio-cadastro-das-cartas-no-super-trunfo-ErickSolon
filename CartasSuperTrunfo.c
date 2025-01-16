#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    char codigoCidade[4]; // Exemplo: "A01"
    char nome[100]; 
    unsigned int populacao;
    float area; 
    float pib; 
    unsigned int pontosTuristicos;

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    for (char estado = 'A'; estado <= 'H'; estado++) {
        for (int cidade = 1; cidade <= 4; cidade++) {
            sprintf(codigoCidade, "%c%02d", estado, cidade);
            printf("\n=== Cadastro da Cidade %s ===\n", codigoCidade);
            printf("Digite o nome da cidade: ");
            getchar();
            fgets(nome, sizeof(nome), stdin); 
            nome[strcspn(nome, "\n")] = '\0';
            printf("Digite a população da cidade: ");
            scanf("%u", &populacao);
            printf("Digite a área da cidade (em km²): ");
            scanf("%f", &area); 
            printf("Digite o PIB da cidade (em bilhões): ");
            scanf("%f", &pib);
            printf("Digite o número de pontos turísticos da cidade: ");
            scanf("%u", &pontosTuristicos);

            printf("\n=== Cidade Cadastrada ===\n");
            printf("Código da cidade: %s\n", codigoCidade);
            printf("Nome da cidade: %s\n", nome);
            printf("População da cidade: %u\n", populacao);
            printf("Área da cidade: %.2f km²\n", area);
            printf("PIB da cidade: %.2f bilhões\n", pib); 
            printf("Número de pontos turísticos: %u\n", pontosTuristicos);
        }
    }

    return 0;
}
