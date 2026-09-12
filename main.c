#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int turma[5][6];
    int melhores[6];
    int quantidade80[5];

    float calculo[6];

    int x, y;
    int soma;
    int maior;
    int menor;
    int acima_media;
    int localizada;
    int opcao;
    int continuar;

    char busca[10];

    char modalidade[6][20] = {
        "Futsal",
        "Volei",
        "Basquete",
        "Handebol",
        "Tenis Mesa",
        "Xadrez"
    };

    char turma_nome[5][10] = {
        "1o F",
        "1o H",
        "1o I",
        "1o J",
        "1o L"
    };


    do {


        soma = 0;
        acima_media = 0;

        calculo[0] = 0;
        calculo[1] = 0;
        calculo[2] = 0;
        calculo[3] = 0;
        calculo[4] = 0;
        calculo[5] = 0;

        for (x = 0; x < 5; x++) {
            quantidade80[x] = 0;
        }


        printf("\n=======================================\n");
        printf("       CAMPEONATO INTERCLASSES\n");
        printf("=======================================\n\n");



        for (x = 0; x < 5; x++) {

            for (y = 0; y < 6; y++) {

                printf("Digite os pontos da turma %s em %s: ",
                       turma_nome[x], modalidade[y]);

                scanf("%d", &turma[x][y]);

                while (turma[x][y] < 10) {

                    printf("Valor invalido! O ponto nao pode ser menor que 10.\n");

                    printf("Digite novamente os pontos da turma %s em %s: ",
                           turma_nome[x], modalidade[y]);

                    scanf("%d", &turma[x][y]);
                }
            }
        }



        maior = turma[0][0];
        menor = turma[0][0];

        for (x = 0; x < 5; x++) {

            for (y = 0; y < 6; y++) {

                soma = soma + turma[x][y];

                if (turma[x][y] > maior) {
                    maior = turma[x][y];
                }

                if (turma[x][y] < menor) {
                    menor = turma[x][y];
                }

                if (turma[x][y] > 80) {
                    calculo[4]++;
                    quantidade80[x]++;
                }
            }
        }



        calculo[0] = soma / 30.0;

        calculo[1] = maior;
        calculo[2] = menor;



        for (x = 0; x < 5; x++) {

            int soma_turma = 0;
            float media_turma;

            for (y = 0; y < 6; y++) {
                soma_turma = soma_turma + turma[x][y];
            }

            media_turma = soma_turma / 6.0;

            if (media_turma > calculo[0]) {
                acima_media++;
            }
        }

        calculo[3] = acima_media;



        maior = quantidade80[0];
        calculo[5] = 0;

        for (x = 1; x < 5; x++) {

            if (quantidade80[x] > maior) {
                maior = quantidade80[x];
                calculo[5] = x;
            }
        }



        for (y = 0; y < 6; y++) {

            melhores[y] = 0;

            for (x = 1; x < 5; x++) {

                if (turma[x][y] > turma[melhores[y]][y]) {
                    melhores[y] = x;
                }
            }
        }



        printf("\n\n===============================================\n");
        printf("              TABELA DE PONTUACOES\n");
        printf("===============================================\n\n");

        printf("%-10s", "Turma");

        for (y = 0; y < 6; y++) {
            printf("%-12s", modalidade[y]);
        }

        printf("\n");

        for (x = 0; x < 5; x++) {

            printf("%-10s", turma_nome[x]);

            for (y = 0; y < 6; y++) {
                printf("%-12d", turma[x][y]);
            }

            printf("\n");
        }



        printf("\n===============================================\n");
        printf("             ESTATISTICAS GERAIS\n");
        printf("===============================================\n");

        printf("Media geral: %.2f\n", calculo[0]);
        printf("Maior pontuacao: %.0f\n", calculo[1]);
        printf("Menor pontuacao: %.0f\n", calculo[2]);
        printf("Turmas acima da media: %.0f\n", calculo[3]);
        printf("Quantidade de pontuacoes acima de 80: %.0f\n",
               calculo[4]);

        printf("Turma com mais pontuacoes acima de 80: %s\n",
               turma_nome[(int)calculo[5]]);



        printf("\n===============================================\n");
        printf("             MELHORES POR ESPORTE\n");
        printf("===============================================\n");

        for (y = 0; y < 6; y++) {

            printf("%s: %s (%d pontos)\n",
                   modalidade[y],
                   turma_nome[melhores[y]],
                   turma[melhores[y]][y]);
        }



        do {

            localizada = -1;

            printf("\n===============================================\n");
            printf("                BUSCAR TURMA\n");
            printf("===============================================\n");

            printf("Digite o nome da turma (ex: 1o F): ");
            scanf(" %[^\n]", busca);



            for (x = 0; x < 5; x++) {

                if (strcmp(busca, turma_nome[x]) == 0) {
                    localizada = x;
                }
            }


            if (localizada != -1) {

                int soma_turma = 0;
                float media_turma;

                printf("\n-----------------------------------------------\n");
                printf("Turma encontrada: %s\n", turma_nome[localizada]);
                printf("-----------------------------------------------\n");

                for (y = 0; y < 6; y++) {

                    printf("%-12s: %d pontos\n",
                           modalidade[y],
                           turma[localizada][y]);

                    soma_turma = soma_turma + turma[localizada][y];
                }

                media_turma = soma_turma / 6.0;

                printf("Media da turma: %.2f\n", media_turma);
                printf("-----------------------------------------------\n");

            } else {

                printf("\n[ERRO] Turma nao localizada na base de dados.\n");
            }


            printf("\nDigite 1 para realizar outra busca.\n");
            printf("Digite qualquer outro numero para encerrar as buscas.\n");
            scanf("%d", &opcao);

        } while (opcao == 1);


		
        printf("\n===============================================\n");
        printf("Digite 1 para iniciar outro campeonato.\n");
        printf("Digite qualquer outro numero para encerrar o programa.\n");
        printf("Opcao: ");
        scanf("%d", &continuar);
       
		

    } while (continuar == 1);


    printf("\n\n===============================================\n");
    printf("             FIM DO PROGRAMA\n");
    printf("===============================================\n");

    return 0;
}
