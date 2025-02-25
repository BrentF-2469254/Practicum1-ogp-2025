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
bool Bord::is_pion_op_positie(int x, int y) const
{
    return arr[x][y] != nullptr; // Return true als er een pion op de positie staat
}

void Bord::printbord() const
{
    for (int i = 7; i >= 0; i--)
    {
        std::cout << i + 1 << "   ";
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
bool Bord::beweeg_piece(int x1, int y1, int x2, int y2, Kleur huidigeKleur)
{
    // Invalid coordinates

    if (x1 < 0 || x1 >= 8 || y1 < 0 || y1 >= 8 || x2 < 0 || x2 >= 8 || y2 < 0 || y2 >= 8)
    {
        std::cout << "Ongeldige coördinaten! De zet is buiten het bord.\n";
        return false;
    }

    // No piece at (x1, y1)
    if (!arr[x1][y1]) // Dit checkt al op nullptr
    {
        std::cout << "Geen pion op (" << x1 << ", " << y1 << ").\n";
        return false;
    }

    // Controleer of de speler aan de beurt is
    if (arr[x1][y1]->getKleur() != huidigeKleur) // Gebruik y1 in plaats van x2
    {
        std::cout << "Jij, " << arr[x1][y1]->getKleur() << ", bent niet aan de beurt. "
                  << huidigeKleur << " is aan de beurt.\n";
        return false;
    }
    // First move check
    bool firstMove = (arr[x1][y1]->getKleur() == Kleur::Wit && y1 == 1) ||
                     (arr[x1][y1]->getKleur() == Kleur::Zwart && y1 == 6);
    Kleur kleur = static_cast<Kleur>(arr[x1][y1]->getKleur());

    // Get valid moves for the piece
    std::vector<Point> moves = valid_movements_pion(x1, y1, firstMove, kleur);
    for (const Point &move : moves)
    {
        if (move.x == x2 && move.y == y2)
        {
            arr[x2][y2] = arr[x1][y1];
            arr[x1][y1] = nullptr;
            arr[x2][y2]->verander_pos(x2, y2);
            return true; // Correctly return true if valid move
        }
    }

    // If no valid move was found
    std::cout << "Ongeldige zet! Pion kan niet naar (" << x2 + 1 << ", " << y2 + 1 << ").\n";
    return false; // Ensure a return at the end
}

std::vector<Point> Bord::valid_movements_pion(int x1, int y1, bool firstMove, Kleur kleur)
{
    std::vector<Point> points;

    if (kleur == Kleur::Wit)
    {
        if (!firstMove)
        {
            points.push_back({x1, y1 + 1});
        }
        else
        {
            points.push_back({x1, y1 + 1});
            points.push_back({x1, y1 + 2});
        }

        // Check rechts diagonaal slaan
        if (x1 + 1 < 8 && y1 + 1 < 8 && arr[x1 + 1][y1 + 1] && arr[x1 + 1][y1 + 1]->getKleur() == Kleur::Zwart)
        {
            points.push_back({x1 + 1, y1 + 1});
        }

        // Check links diagonaal slaan
        if (x1 - 1 >= 0 && y1 + 1 < 8 && arr[x1 - 1][y1 + 1] && arr[x1 - 1][y1 + 1]->getKleur() == Kleur::Zwart)
        {
            points.push_back({x1 - 1, y1 + 1});
        }
    }

    if (kleur == Kleur::Zwart)
    {
        if (!firstMove)
        {
            if (y1 - 1 >= 0 && !arr[x1][y1 - 1])
                points.push_back({x1, y1 - 1});
        }
        else
        {
            if (y1 - 1 >= 0 && !arr[x1][y1 - 1])
                points.push_back({x1, y1 - 1});
            if (y1 - 2 >= 0 && !arr[x1][y1 - 2])
                points.push_back({x1, y1 - 2});
        }

        // Check rechts diagonaal slaan
        if (x1 + 1 < 8 && y1 - 1 >= 0 && arr[x1 + 1][y1 - 1] && arr[x1 + 1][y1 - 1]->getKleur() == Kleur::Wit)
        {
            points.push_back({x1 + 1, y1 - 1});
        }

        // Check links diagonaal slaan
        if (x1 - 1 >= 0 && y1 - 1 >= 0 && arr[x1 - 1][y1 - 1] && arr[x1 - 1][y1 - 1]->getKleur() == Kleur::Wit)
        {
            points.push_back({x1 - 1, y1 - 1});
        }
    }

    return points;
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
    Kleur huidigeKleur = Kleur::Wit;

    int x1, y1, x2, y2;

    while (true)
    {
        std::cout << "Voer een zet in (bijv. 1 2 1 3): ";
        std::cin >> x1 >> y1 >> x2 >> y2;

        // Pas aan zodat de indexen kloppen met de matrix
        x1 -= 1; // Converteer naar 0-gebaseerde index;
        y1 -= 1;
        x2 -= 1; // Converteer naar 0-gebaseerde index
        y2 -= 1;
        if (!bord.is_pion_op_positie(x1, y1))
        {
            std::cout << "Geen pion op de gekozen startpositie (" << x1 + 1 << ", " << y1 + 1 << "). Probeer opnieuw.\n";
            continue;
        }

        bool succes = bord.beweeg_piece(x1, y1, x2, y2, huidigeKleur);
        if (succes)
        {
            if (huidigeKleur == Kleur::Wit)
            {
                huidigeKleur = Kleur::Zwart;
            }
            else
            {
                huidigeKleur = Kleur::Wit;
            }
        }
        bord.printbord();
    }

    return 0;
}