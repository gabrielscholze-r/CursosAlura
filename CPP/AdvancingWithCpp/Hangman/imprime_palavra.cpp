#include <iostream>
#include "imprime_palavra.hpp"
namespace Forca
{
    void imprime_palavra(const std::string &palavra_secreta, std::map<char, bool> &chutou)
    {
        for (char letra : palavra_secreta)
        {
            if (chutou.find(letra) == chutou.end() || !chutou.at(letra))
            {
                std::cout << "_ ";
            }
            else
            {
                std::cout << letra << " ";
            }
        }
        std::cout << std::endl;
    }
}