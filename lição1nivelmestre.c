//mestre//
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

typedef struct {
    int tipoMissao; // 1 = eliminar cor verde; 2 = conquistar 3 territórios
    int conquistas;
} Missao;

// -------------------------------
// Funções auxiliares
// -------------------------------

void inicializarTerritorios(Territorio *mapa) {
    const char *nomes[5] = {"Alaska", "Egito", "Brasil", "Japão", "Índia"};
    const char *cores[5] = {"Vermelho", "Verde", "Azul", "Amarelo", "Preto"};
    int tropasIniciais[5] = {3, 4, 5, 2, 3};

    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        strcpy(mapa[i].nome, nomes[i]);
        strcpy(mapa[i].cor, cores[i]);
        mapa[i].tropas = tropasIniciais[i];
    }
}

void exibirMapa(const Territorio *mapa) {
    printf("\n=== Mapa Atual ===\n");

    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("  Nome: %s\n", mapa[i].nome);
        printf("  Cor: %s\n", mapa[i].cor);
        printf("  Tropas: %d\n", mapa[i].tropas);
    }
}

int simularAtaque(Territorio *a, Territorio *d, Missao *m) {
    int dadoA = rand() % 6 + 1;
    int dadoD = rand() % 6 + 1;

    printf("\n--- Batalha entre %s (A) e %s (D) ---\n", a->nome, d->nome);
    printf("Dado ataque: %d\n", dadoA);
    printf("Dado defesa: %d\n", dadoD);

    if (dadoA >= dadoD) {
        d->tropas--;

        printf("Ataque venceu! O defensor perdeu 1 tropa.\n");

        if (d->tropas <= 0) {
            printf(">>> %s foi conquistado!\n", d->nome);

            // Atualiza missão
            m->conquistas++;

            strcpy(d->cor, a->cor);
            d->tropas = 1;

            return 1;
        }
    } else {
        printf("Defensor resistiu!\n");
    }

    return 0;
}

void gerarMissao(Missao *m) {
    m->tipoMissao = rand() % 2 + 1; // 1 ou 2
    m->conquistas = 0;

    if (m->tipoMissao == 1)
        printf("\nMissão: Destruir todos os territórios Verdes.\n");
    else
        printf("\nMissão: Conquistar 3 territórios.\n");
}

int verificarMissao(const Territorio *mapa, const Missao *m) {
    if (m->tipoMissao == 1) {
        // Missão: destruir verdes
        for (int i = 0; i < QTD_TERRITORIOS; i++) {
            if (strcmp(mapa[i].cor, "Verde") == 0)
                return 0;
        }
        return 1;
    }

    if (m->tipoMissao == 2) {
        return m->conquistas >= 3;
    }

    return 0;
}

// -------------------------------
// MAIN – Nível Mestre
// -------------------------------

int main() {
    srand(time(NULL));

    Territorio mapa[QTD_TERRITORIOS];
    Missao missao;

    inicializarTerritorios(mapa);
    gerarMissao(&missao);

    int opcao, a, d;

    while (1) {
        exibirMapa(mapa);

        printf("\n=== MENU ===\n");
        printf("1 - Atacar\n");
        printf("2 - Verificar Missão\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 0)
            break;

        if (opcao == 1) { // atacar
            printf("Atacante (1-5): ");
            scanf("%d", &a);
            getchar();

            printf("Defensor (1-5): ");
            scanf("%d", &d);
            getchar();

            simularAtaque(&mapa[a - 1], &mapa[d - 1], &missao);
        }

        if (opcao == 2) { // verificar missão
            if (verificarMissao(mapa, &missao)) {
                printf("\n🎉 MISSÃO COMPLETA! VOCÊ VENCEU! 🎉\n");
                break;
            } else {
                printf("\nMissão ainda não concluída.\n");
            }
        }
    }

    printf("\nFim do jogo.\n");
    return 0;
}
