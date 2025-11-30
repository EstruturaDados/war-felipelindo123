//aventureiro//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR 50
#define QTD_TERRITORIOS 5

typedef struct {
    char nome[MAX_STR];
    char cor[MAX_STR];
    int tropas;
} Territorio;

void simularAtaque(Territorio *atacante, Territorio *defensor) {
    int dadoAtaque = rand() % 6 + 1;
    int dadoDefesa = rand() % 6 + 1;

    printf("\n--- Batalha entre %s (A) e %s (D) ---\n",
           atacante->nome, defensor->nome);

    printf("Dado do ataque: %d\n", dadoAtaque);
    printf("Dado da defesa: %d\n", dadoDefesa);

    if (dadoAtaque >= dadoDefesa) {
        defensor->tropas--;
        printf("Ataque bem-sucedido! O defensor perdeu 1 tropa.\n");

        if (defensor->tropas <= 0) {
            printf(">>> Território %s foi conquistado!\n", defensor->nome);
            strcpy(defensor->cor, atacante->cor);
            defensor->tropas = 1; // ocupa com uma tropa
        }
    } else {
        printf("O defensor resistiu ao ataque!\n");
    }
}

int main() {
    srand(time(NULL));

    Territorio *mapa = calloc(QTD_TERRITORIOS, sizeof(Territorio));

    printf("=== Cadastro dos Territórios (Aventureiro) ===\n\n");

    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);

        printf("  Nome: ");
        fgets(mapa[i].nome, MAX_STR, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("  Cor do Exército: ");
        fgets(mapa[i].cor, MAX_STR, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("  Número de tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar();
        printf("\n");
    }

    int atacante, defensor;

    while (1) {
        printf("\n=== Fase de Ataque ===\n");
        printf("Escolha o território atacante (1-5, 0 para sair): ");
        scanf("%d", &atacante);
        getchar();

        if (atacante == 0)
            break;

        printf("Escolha o território defensor (1-5): ");
        scanf("%d", &defensor);
        getchar();

        simularAtaque(&mapa[atacante - 1], &mapa[defensor - 1]);
    }

    printf("\n=== Estado Final do Mapa ===\n");
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("  Nome: %s\n", mapa[i].nome);
        printf("  Cor do Exérc
