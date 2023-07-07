#include "imprime_erros.hpp"
#include <iostream>

namespace Forca
{
    void imprime_erros(const std::array<char,5> &chutes_errados)
    {
        std::cout << "Chutes errados: ";
        for (char letra : chutes_errados)
        {
            std::cout << letra << " ";
        }
        std::cout << std::endl;
    }
} 