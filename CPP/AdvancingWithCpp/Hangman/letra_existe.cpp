#include "letra_existe.hpp"

namespace Forca
{
    bool letra_existe(const char &chute, const std::string &palavra_secreta)
    {
        for (char letra : palavra_secreta)
        {
            if (chute == letra)
            {
                return true;
            }
        }
        return false;
    }
}