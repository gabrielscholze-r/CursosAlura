#include <iostream>
#include <string>
#include <map>
#include <array>
#include "letra_existe.hpp"
#include "imprime_cabecalho.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "adiciona_palavra.hpp"
#include "nao_acertou.hpp"

using namespace std;

static string palavra_secreta;
static map<char, bool> chutou;
static array<char, 5> chutes_errados;
static int numero_chutes = 0;

int main()
{
    imprime_cabecalho();

    palavra_secreta = Forca::sorteia_palavra();

    while (Forca::nao_acertou(palavra_secreta, chutou) && numero_chutes < 5)
    {
        Forca::imprime_erros(chutes_errados);

        Forca::imprime_palavra(palavra_secreta, chutou);

        Forca::chuta(chutou, chutes_errados, palavra_secreta, numero_chutes);

        numero_chutes++;
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if (Forca::nao_acertou(palavra_secreta, chutou))
    {
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "Parabens! Você acertou a palavra secreta!" << endl;

        cout << "Voce deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if (resposta == 'S')
        {
            Forca::adiciona_palavra();
        }
    }

    cin.get();
}