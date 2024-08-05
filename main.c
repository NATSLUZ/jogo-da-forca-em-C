#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void jogo_da_forca(int num_jogadores);
void jogo_um_jogador();
void jogo_dois_jogadores();

char bancodepalavras[20][9] = {
    "serpente", "ratazana", "sardinha", "pirarucu", "cascavel",
    "pelicano", "cachorro", "capivara", "avestruz", "golfinho",
    "elefante", "papagaio", "leopardo", "camaleao", "flamingo",
    "guepardo", "toupeira", "jararaca", "suricato", "tamandua"
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    int num_jogadores;

    do {
        printf("Bem-vindo ao Jogo da Forca!\nCada letra correta vale 2 pontos, cada letra errada vale -1 ponto\n\n");
        printf("Escolha o número de jogadores (1 ou 2): ");
        scanf("%d", &num_jogadores);

        while (getchar() != '\n');

        if (num_jogadores == 1 || num_jogadores == 2) {
            jogo_da_forca(num_jogadores);
        } else {
            printf("Opção inválida. Escolha 1 ou 2 jogadores.\n\n");
            printf("Pressione enter para tentar novamente...\n");
            while (getchar() != '\n');
            system("cls");
        }

    } while (num_jogadores != 1 && num_jogadores != 2);

    return 0;
}

void jogo_da_forca(int num_jogadores) {
    if (num_jogadores == 1) {
        jogo_um_jogador();
    } else if (num_jogadores == 2) {
        jogo_dois_jogadores();
    } else {
        printf("Opção inválida. Escolha 1 ou 2 jogadores.\n");
    }
}

void jogo_um_jogador() {
    int tentativas_maximas = 6;
    char palavra[9];
    int tentativas = 0;
    int pontuacao = 0;
    char letras_erradas[7];
    letras_erradas[0] = '\0';

    srand(time(NULL));
    int indice_palavra = rand() % 20;
    strcpy(palavra, bancodepalavras[indice_palavra]);

    char palavra_adivinhada[17];
    int i;
	for (i = 0; i < 8; i++) {
        palavra_adivinhada[i * 2] = '_';
        palavra_adivinhada[i * 2 + 1] = ' ';
    }
    palavra_adivinhada[16] = '\0';

    int letras_restantes = 8;
    while (letras_restantes > 0 && tentativas < tentativas_maximas) {
        printf("\n\n\n%s\n", palavra_adivinhada);
        printf("Letras erradas: %s\n", letras_erradas);
        printf("Tentativas restantes: %d\n", tentativas_maximas - tentativas);
        printf("Pontuação atual: %d\n", pontuacao);

        char letra;
        printf("\n\nDICA: É UM ANIMAL\n\n ");
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);
        system("cls");

        int acertou = 0;
        for (i = 0; i < 8; i++) {
            if (palavra[i] == letra && palavra_adivinhada[i * 2] == '_') {
                palavra_adivinhada[i * 2] = letra;
                acertou = 1;
                letras_restantes--;
                pontuacao += 2;
            }
        }

        if (!acertou) {
            printf("Letra incorreta. Tente novamente.\n");
            letras_erradas[tentativas] = letra;
            letras_erradas[tentativas + 1] = '\0';
            tentativas++;
            pontuacao--;
        }
    }

    if (letras_restantes == 0) {
        printf("\n\nParabéns! Você adivinhou a palavra: %s\n", palavra);
    } else {
        printf("\n\nVocê foi enforcado! A palavra era: %s\n", palavra);
    }

    printf("Pontuação final: %d\n", pontuacao);
    printf("\n\nCRÉDITOS: ANTHONNY GOLÇALVES, NATAN LUZ, YUDE LIMA.\n");
    system("pause");
}

void jogo_dois_jogadores() {
    int pontuacao_jogador1 = 0, pontuacao_jogador2 = 0;
    int tentativas_maximas = 6;

    int j;
	for (j = 0; j < 2; j++) {
        srand(time(NULL));
        printf("\n\nJogador %d, é a sua vez!\n", j + 1);

        int k;
		for (k = 0; k < 3; k++) {
            char palavra[9];
            int tentativas = 0;
            int pontuacao = 0;
            char letras_erradas[7];
            letras_erradas[0] = '\0';

            int indice_palavra = rand() % 20;
            strcpy(palavra, bancodepalavras[indice_palavra]);

            char palavra_adivinhada[17];
            int i;
			for (i = 0; i < 8; i++) {
                palavra_adivinhada[i * 2] = '_';
                palavra_adivinhada[i * 2 + 1] = ' ';
            }
            palavra_adivinhada[16] = '\0';

            int letras_restantes = 8;

            while (letras_restantes > 0 && tentativas < tentativas_maximas) {
                printf("\n\n\n%s\n", palavra_adivinhada);
                printf("Letras erradas: %s\n", letras_erradas);
                printf("Tentativas restantes: %d\n", tentativas_maximas - tentativas);
                printf("Pontuação atual: %d\n", pontuacao);

                char letra;
                printf("\n\nA DICA: É UM ANIMAL\n\n ");
                printf("Digite uma letra: ");
                scanf(" %c", &letra);
                letra = tolower(letra);
                system("cls");

                int acertou = 0;
                int i;
				for (i = 0; i < 8; i++) {
                    if (palavra[i] == letra && palavra_adivinhada[i * 2] == '_') {
                        palavra_adivinhada[i * 2] = letra;
                        acertou = 1;
                        letras_restantes--;
                        pontuacao += 2;
                    }
                }

                if (!acertou) {
                    printf("Letra incorreta. Tente novamente.\n");
                    letras_erradas[tentativas] = letra;
                    letras_erradas[tentativas + 1] = '\0';
                    tentativas++;
                    pontuacao--;
                }
            }

            printf("\n\nFim da palavra %d do Jogador %d\n", k + 1, j + 1);
            printf("Pontuação do Jogador %d nesta palavra: %d pontos\n", j + 1, pontuacao);

            if (letras_restantes == 0) {
                printf("Parabéns! Você adivinhou a palavra: %s\n", palavra);
            } else {
                printf("Você foi enforcado! A palavra era: %s\n", palavra);
            }

            if (j == 0) {
                pontuacao_jogador1 += pontuacao;
            } else {
                pontuacao_jogador2 += pontuacao;
            }
        }
    }

    printf("\n\nPontuação final:\n");
    printf("Jogador 1: %d pontos\n", pontuacao_jogador1);
    printf("Jogador 2: %d pontos\n", pontuacao_jogador2);
    printf("\n\n\n\nCRÉDITOS: ANTHONNY GOLÇALVES, NATAN LUZ, YUDE LIMA.\n\n");
    system("pause");
}
