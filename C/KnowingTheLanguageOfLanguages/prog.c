#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int segundos = time(0);
    double pontos = 1000;
    srand(segundos);
    int numeroSecreto = rand() % 100;
    int chute;
    int tentativas = 5;
    int acerto = 0;

    int dif;
    printf("Qual nível de dificuldade?\n");
    printf("(1) Facil | (2) Medio | (3) Dificil\n");
    scanf("%d", dif);
    while (dif < 1 || dif > 3)
    {
        printf("VALOR INVALIDO, DIGITE NOVAMENTE");
        scanf("%d", dif);
    }
    switch (dif)
    {
    case 1:
        printf("Nível fácil escolhido!");
        tentativas = 20;
        break;
    case 2:
        printf("Nível médio escolhido!");
        tentativas = 10;
        break;
    case 3:
        printf("Nível Dificil escolhido!");
        tentativas = 5;
        break;
    }

    printf("**********************************\n");
    printf("Bem vindo ao jogo de adivinhação\n");
    printf("**********************************\n");
    while (!acerto && (tentativas--) > 0)
    {
        printf("chute um numero\n");
        scanf("%d", &chute);
        acerto = chute == numeroSecreto;
        if (chute < 0)
        {
            printf("Não chute números negativos\n");
            continue;
        }
        if (acerto)
        {
            break;
        }
        else
        {

            tentativas++;
            printf("Número errado!\n");
            if (chute < numeroSecreto)
            {
                pontos -= (numeroSecreto - (chute / 2.0));
                printf("O número que você colocou é MENOR que o número correto\n");
            }
            else
            {
                pontos -= ((chute / 2.0) - numeroSecreto);
                printf("O número que você colocou é MAIOR que o número correto\n");
            }
        }
    }
    if (acerto)
    {
        printf("Parabéns, você acertou!");
    }
    else
    {
        printf("Que pena, mais sorte da próxima!");
    }
}