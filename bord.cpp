#include "header_bord.h"
#include "header_pion.h"
#include "header_kleur.h"
#include <iostream>
Bord::Bord()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        arr[i][1] = new Pion(i, 1, Kleur::Wit);
    }

    for (int i = 0; i < 8; i++)
    {
        arr[i][6] = new Pion(i, 6, Kleur::Zwart);
    }
}

void Bord::printbord() const
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arr[j][i] && arr[j][i]->getKleur() == Kleur::Wit)
            {
                std::cout << "W ";
            }
            else if (arr[j][i] && arr[j][i]->getKleur() == Kleur::Zwart)
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
bool Bord::beweeg_piece(int x1, int y1, int x2, int y2)
{
    bool firstMove = (y1 == 1);
    std::vector<Point> moves = valid_movements_pion(x1, y1, firstMove);
    for (const Point &move : moves)
    {
        if (move.x == x2 && move.y == y2)
        {
            arr[x2][y2]->verander_pos(x2, y2);
            return true;
        }
    }

    return false;
}
Bord::~Bord()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arr[i][j] != 0)
            {
                delete arr[i][j];
            }
        }
    }
}

int main()
{
    Bord bord;

    std::cout << "initiele bord status:\n";
    bord.printbord();

    return 0;
}
