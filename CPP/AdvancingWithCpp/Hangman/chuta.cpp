#include <iostream>
#include "chuta.hpp"
#include "letra_existe.hpp"

namespace Forca{
    void chuta(std::map<char, bool> & chutou, std::array<char,5> & chutes_errados, std::string & palavra_secreta,int& numero_chutes)
    {
        std::cout << "Seu chute: ";
        char chute;
        std::cin >> chute;

        chutou[chute] = true;

        if (letra_existe(chute, palavra_secreta))
        {
            std::cout << "Voce acertou! Seu chute esta na palavra." << std::endl;
        }
        else
        {
            std::cout << "Voce errou! Seu chute nao esta na palavra." << std::endl;
            chutes_errados[numero_chutes]=chute;
        }
        std::cout << std::endl;
    }
}