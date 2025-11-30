//novato//
#include <stdio.h>
#include <string.h>

#define MAX_STR 50
#define QTD_TERRITORIOS 5

// -------------------------------
// Definição da struct Territorio
// -------------------------------
typedef struct {
    char nome[MAX_STR];
    char cor[MAX_STR];
    int tropas;
} Territorio;

int main() {
    Territorio mapa[QTD_TERRITORIOS];

    printf("=== Cadastro Inicial dos Territorios ===\n\n");

    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("Territorio %d:\n", i + 1);

        // Lê nome do território
        printf("  Nome: ");
        fgets(mapa[i].nome, MAX_STR, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0'; // remove \n do fim

        // Lê cor do exército
        printf("  Cor do Exercito: ");
        fgets(mapa[i].cor, MAX_STR, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        // Lê número de tropas
        printf("  Numero de tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar(); // consome o \n deixado pelo scanf

        printf("\n");
    }

    // --------------------------
    // Exibição final do mapa
    // --------------------------
    printf("\n=== Estado Atual do Mapa ===\n");

    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("  Nome: %s\n", mapa[i].nome);
        printf("  Cor do Exercito: %s\n", mapa[i].cor);
        printf("  Tropas: %d\n", mapa[i].tropas);
    }

    return 0;
}
