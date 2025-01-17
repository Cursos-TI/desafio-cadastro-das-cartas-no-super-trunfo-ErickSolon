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

float calcularSuperPoder(unsigned int populacao, float area, float pib, unsigned int pontosTuristicos) {
    float densidadePopulacional = calcularDensidadePopulacional(populacao, area);
    float pibPerCapita = calcularPibPerCapita(pib, populacao);
    return (densidadePopulacional + pibPerCapita + pontosTuristicos);
}

int obterIndiceCidade(char *codigoCidade, char codigo[TOTAL_CIDADES][4]) {
    for (int i = 0; i < TOTAL_CIDADES; i++) {
        if (strcmp(codigoCidade, codigo[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void compararCartas(char *codigoCidade1, char *codigoCidade2, unsigned int populacao[], float area[], float pib[], unsigned int pontosTuristicos[], char codigo[TOTAL_CIDADES][4]) {
    int cidade1 = -1, cidade2 = -1;
    
    // Encontrar o índice das cidades
    for (int i = 0; i < TOTAL_CIDADES; i++) {
        if (strcmp(codigo[i], codigoCidade1) == 0) {
            cidade1 = i;
        }
        if (strcmp(codigo[i], codigoCidade2) == 0) {
            cidade2 = i;
        }
    }

    if (cidade1 == -1 || cidade2 == -1) {
        printf("Código da cidade não encontrado.\n");
        return;
    }

    float superPoder1 = calcularSuperPoder(populacao[cidade1], area[cidade1], pib[cidade1], pontosTuristicos[cidade1]);
    float superPoder2 = calcularSuperPoder(populacao[cidade2], area[cidade2], pib[cidade2], pontosTuristicos[cidade2]);

    printf("Comparando Cidade %s e Cidade %s:\n", codigoCidade1, codigoCidade2);

    if (superPoder1 > superPoder2) {
        printf("Cidade %s vence com Super Poder: %.2f\n", codigoCidade1, superPoder1);
    } else if (superPoder2 > superPoder1) {
        printf("Cidade %s vence com Super Poder: %.2f\n", codigoCidade2, superPoder2);
    } else {
        printf("Empate no Super Poder: %.2f\n", superPoder1);
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
    char digitarCodigoCidade1[4], digitarCodigoCidade2[4];
    int escolhaTipoJogo;
    
    printf("<><><><><> Super Trunfo (Países) <><><><><>\n");
    printf("1 ... Inserção de cidades manualmente.\n");
    printf("2 ... Inserção de cidades automaticamente.\n");
    printf("Escolha >>> ");
    scanf("%d", &escolhaTipoJogo);

    if (escolhaTipoJogo == "") {
        printf("escolha novamente... fechando jogo...");
    } else {
        switch (escolhaTipoJogo) {
            case 1: {
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

                break;
            }

            case 2: {
                for (char estado = 'A'; estado <= 'H'; estado++) {
                    for (int cidade = 1; cidade <= 4; cidade++) {                        
                        sprintf(codigoCidade[indice], "%c%02d", estado, cidade);
                        printf("\n=== Cidade Cadastrada %s ===\n", codigoCidade[indice]);
                        sprintf(nome[indice], "Cidade %d", indice + 1);
                        populacao[indice] = 100000 + indice * 1000;
                        area[indice] = 200 + indice * 10;
                        pib[indice] = 50 + indice * 5;
                        pontosTuristicos[indice] = indice % 10;

                        indice++;
                    }
                }

                break;
            }

            default: {
                printf("Item não compreendido, fechado jogo! tente novamente...");
                break;
            }
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

    printf("\n=== Fim das Cartas ===\n");

    do {
        printf("\n\nDigite o código de duas cidades para que sejam comparadas!\n");
        printf("Digite \"-1\" em qualquer input de código de cidade para parar de comparar as cartas e sair do programa!\n");
        printf("Cidade 1: ");
        scanf("%s", &digitarCodigoCidade1);
        printf("Cidade 2: ");
        scanf("%s", &digitarCodigoCidade2);

        if (strcmp(digitarCodigoCidade1, "-1") == 0 || strcmp(digitarCodigoCidade2, "-1") == 0) {
            break;
        }
        
        compararCartas(digitarCodigoCidade1, digitarCodigoCidade2, populacao, area, pib, pontosTuristicos, codigoCidade);
    } while (1);

    return 0;
}
