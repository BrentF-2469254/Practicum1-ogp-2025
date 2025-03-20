#include "header_bord_echt.h"
#include <iostream>
void Bord::printbord()
{
    for (int i = 7; i >= 0; i--)
    {
        std::cout << i + 1 << "   ";
        for (int j = 0; j < 8; j++)
        {
            if (arr[j][i] && arr[j][i]->get_kleur() == Kleur::Wit)
            {
                std::cout << "W ";
            }
            else if (arr[j][i] && arr[j][i]->get_kleur() == Kleur::Zwart)
            {
                std::cout << "Z ";
            }
            else
            {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
};

