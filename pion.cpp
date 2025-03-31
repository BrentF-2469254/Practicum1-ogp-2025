#include "header_pion.h"

Pion::Pion(Kleur kleur, int x, int y) : Piece(kleur, x, y) {}

std::vector<Point> Pion::valid_movements(Point p, Piece *(*array)[8])
{
    std::vector<Point> moves;
    int x = p.x;
    int y = p.y;
    Kleur huidige_kleur = array[x][y]->get_kleur();

    if (huidige_kleur == Kleur::Wit)
    {
        if (y + 1 < 8 && array[x][y + 1] == nullptr)
        {
            moves.push_back(Point(x, y + 1));

            if (y == 1 && array[x][y + 2] == nullptr) // first move check
            {
                moves.push_back(Point(x, y + 2));
            }
        }
        if (x - 1 >= 0 && y + 1 < 8 && array[x - 1][y + 1] != nullptr && array[x - 1][y + 1]->get_kleur() != Kleur::Wit)
        {
            moves.push_back(Point(x - 1, y + 1)); // Capture left diagonally
        }
        if (x + 1 < 8 && y + 1 < 8 && array[x + 1][y + 1] != nullptr && array[x + 1][y + 1]->get_kleur() != Kleur::Wit)
        {
            moves.push_back(Point(x + 1, y + 1)); // Capture right diagonally
        }
    }
    else if (huidige_kleur == Kleur::Zwart)
    {
        if (y - 1 >= 0 && array[x][y - 1] == nullptr)
        {
            moves.push_back(Point(x, y - 1));

            if (y == 6 && array[x][y - 2] == nullptr) // first move check
            {
                moves.push_back(Point(x, y - 2));
            }
        }

        if (x - 1 >= 0 && y - 1 >= 0 && array[x - 1][y - 1] != nullptr && array[x - 1][y - 1]->get_kleur() != Kleur::Zwart)
        {
            moves.push_back(Point(x - 1, y - 1)); // Capture left diagonally
        }
        if (x + 1 < 8 && y - 1 >= 0 && array[x + 1][y - 1] != nullptr && array[x + 1][y - 1]->get_kleur() != Kleur::Zwart)
        {
            moves.push_back(Point(x + 1, y - 1)); // Capture right diagonally
        }
    }

    return moves;
}
