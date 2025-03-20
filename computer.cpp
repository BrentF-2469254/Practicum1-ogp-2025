#include "header_computer.h"
#include <random>
#include <iostream>

Computer::Computer(Kleur kleur, std::string naam = "computer") : Speler(naam, kleur) {};

bool Computer::beweeg_piece(Piece ***array)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 7; j >= 0; j--)
        {
            if (&array[i][j] != nullptr && array[i][j]->get_kleur() == m_kleur)
            {
                Point p1 = {i, j};
                std::vector<Point> valid = array[i][j]->valid_movements(p1, *array);
                if (valid.empty())
                {
                    continue;
                }
                else
                {
                    std::random_device rd;                                        // Obtain a random seed
                    std::mt19937 gen(rd());                                       // Seed the generator
                    std::uniform_int_distribution<> distrib(0, valid.size() - 1); // Range [0, size-1]

                    // Get a random index
                    int randomIndex = distrib(gen);
                    Point p2 = valid[randomIndex];
                    array[p2.x][p2.y] = array[i][j];
                    array[i][j] = nullptr;
                    array[p2.x][p2.y]->verander_pos(p2.x, p2.y);
                    return true;
                }
            }
        }
        return false;
    }
};