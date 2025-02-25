#include "header_bord.h"
#include "header_pion.h"
#include "header_kleur.h"
#include <iostream>
Bord::Bord()
{
    for (int i = 0; i < 8; i++)
    {
        arr[i][1] = Pion(i, 1, Kleur::Wit);
    }

    for (int i = 0; i < 8; i++)
    {
        arr[i][6] = Pion(i, 6, Kleur::Zwart);
    }
}

void Bord::printbord() const
{
    for (int i = 7; i >= 0; i--)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arr[j][i].getKleur() == Kleur::Wit)
            {
                std::cout << "W ";
            }
            else if (arr[j][i].getKleur() == Kleur::Zwart)
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
}