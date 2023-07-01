#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int tentativas;
    double pontos = 1000.0;
    int contagem = 0;
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;

    cout << "Escolha uma dificuldade" << endl;
    cout << "-> Facil (1) | Medio (2) | Dificil (3) <-" << endl;

    int entrada;
    cin >> entrada;
    cout << "Dificuldade escolhida: ";
    switch (entrada)
    {
    case 1:
        cout << "Facil" << endl;
        tentativas = 20;
        break;
    case 2:
        cout << "Medio" << endl;
        tentativas = 10;
        break;
    case 3:
        cout << "Dificil" << endl;
        tentativas = 5;
        break;
    default:
        cout << "Invalida" << endl;
        return -1;
    }

    int chute;
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    while (contagem<tentativas)
    {
        cout << "Chute um numero: ";
        cin >> chute;
        cout << endl;
        contagem++;
        cout << "Tentativa " << contagem << endl;

        bool acertou= chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;
        if (acertou)
        {
            cout << "Parabens! Voce acertou o numero secreto: " << NUMERO_SECRETO << " em " << contagem << " tentativas" << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Voce fez " << pontos << " pontos"<<endl;
            return 0;
        }
        else
        {
            pontos -= abs(NUMERO_SECRETO-chute)/2.0;
            if (maior)
            {
                cout << "Seu chute foi MAIOR que o numero secreto" << endl;
            }
            else
            {
                cout << "Seu chute foi MENOR que o numero secreto" << endl;
            }
            
        }
    }
    cout << "Voce nao acertou o numero secreto ->" << NUMERO_SECRETO << "<- em " << contagem << " tentativas" << endl;
    return 0;
}
