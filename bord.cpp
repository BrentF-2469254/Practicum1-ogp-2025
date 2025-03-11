#include "header_bord.h"
#include "header_pion.h"
#include "header_kleur.h"
#include "header_speler.h"
#include "header_entity.h"
#include <random>
#include <iostream>
Bord::Bord()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            arr[i][j] = nullptr;
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
bool Bord::beweeg_piece(int x1, int y1, int x2, int y2, Speler huidigespeler)
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
    if (arr[x1][y1]->getKleur() != huidigespeler.get_kleur()) // Gebruik y1 in plaats van x2
    {
        std::cout << "Jij, bent niet aan de beurt. "
                  << huidigespeler.get_naam() << " is aan de beurt.\n";
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
            if (arr[x1][y1 + 1] == nullptr)
            {
                points.push_back({x1, y1 + 1});
            }
        }
        else
        {
            if (arr[x1][y1 + 1] == nullptr)
            {
                points.push_back({x1, y1 + 1});
            }
            if (arr[x1][y1 + 1] == nullptr && (arr[x1][y1 + 2] == nullptr))
            {
                points.push_back({x1, y1 + 2});
            }
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
            if (arr[x1][y1 - 1] == nullptr)
            {
                points.push_back({x1, y1 - 1});
            }
        }
        else
        {
            if (arr[x1][y1 - 1] == nullptr)
            {
                points.push_back({x1, y1 - 1});
            }
            if (arr[x1][y1 - 1] == nullptr && (arr[x1][y1 - 2] == nullptr))
            {
                points.push_back({x1, y1 - 2});
            }
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
            if (arr[i][j] != nullptr)
            {
                delete arr[i][j];
                arr[i][j] = nullptr;
            }
        }
    }
}

bool Bord::computer_beweeg_piece(Kleur kleur_van_bot)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 7; j >= 0; j--)
        {
            if (arr[i][j] && arr[i][j]->getKleur() == kleur_van_bot)
            {
                if (arr[i][j]->get_piece_type() == "pion")
                {
                    bool firstMove = (arr[i][j]->getKleur() == Kleur::Wit && j == 1) || (arr[i][j]->getKleur() == Kleur::Zwart && j == 6);
                    std::vector<Point> moves = valid_movements_pion(i, j, firstMove, kleur_van_bot);
                    if (moves.empty())
                    {
                        continue;
                    }
                    else
                    {
                        // Create a random number generator
                        std::random_device rd;                                        // Obtain a random seed
                        std::mt19937 gen(rd());                                       // Seed the generator
                        std::uniform_int_distribution<> distrib(0, moves.size() - 1); // Range [0, size-1]

                        // Get a random index
                        int randomIndex = distrib(gen);
                        Point eindpunt = moves[randomIndex];
                        arr[eindpunt.x][eindpunt.y] = arr[i][j];
                        arr[i][j] = nullptr;
                        arr[eindpunt.x][eindpunt.y]->verander_pos(eindpunt.x, eindpunt.y);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    Speler speler_1("", Kleur::Wit, Entity::mens); // Provide a default constructor
    Speler speler_2("", Kleur::Zwart, Entity::mens);
    int keuze;
    do
    {
        std::cout << "Maak een keuze.\n";
        std::cout << "0: Je bent met 2 en wilt tegen elkaar spelen.\n";
        std::cout << "1: Je wilt tegen een computer spelen.\n";
        std::cout << "Voer je keuze in: ";
        std::cin >> keuze;
        if (keuze != 0 && keuze != 1)
        {
            std::cout << "Ongeldige invoer, probeer opnieuw.\n";
        }

    } while (keuze != 0 && keuze != 1);

    if (keuze == 1)
    {
        int begin;
        do
        {
            std::cout << "Maak een keuze.\n";
            std::cout << "0: Jij begint.\n";
            std::cout << "1: Computer begint.\n";
            std::cout << "Voer je keuze in: ";
            std::cin >> begin;
            if (begin != 0 && begin != 1)
            {
                std::cout << "Ongeldige invoer, probeer opnieuw.\n";
            }

        } while (begin != 0 && begin != 1);
        if (begin == 1)
        {
            speler_1 = Speler("Computer", Kleur::Wit, Entity::bot);
            std::string naam;
            std::cout << "geef je naam\n";
            std::cin >> naam;
            speler_2 = Speler(naam, Kleur::Zwart, Entity::mens);
        }
        else
        {
            speler_2 = Speler("Computer", Kleur::Zwart, Entity::bot);
            std::string naam;
            std::cout << "geef je naam\n";
            std::cin >> naam;
            speler_1 = Speler(naam, Kleur::Wit, Entity::mens);
        }
    }
    else
    {
        std::string naam;
        std::cout << "geef naam van beginnende speler\n";
        std::cin >> naam;
        speler_1 = Speler(naam, Kleur::Wit, Entity::mens);

        std::cout << "geef naam van tweede speler\n";
        std::cin >> naam;
        speler_2 = Speler(naam, Kleur::Zwart, Entity::mens);
    }

    Bord bord;
    std::cout << "initiele bord status:\n";
    bord.printbord();
    std::cout << "\n";
    Speler huidigespeler = speler_1;
    int x1, y1, x2, y2;
    if (keuze == 0)
    {
        while (true)
        {
            std::cout << huidigespeler.get_naam() << ", voer een zet in (bijv. 1 2 1 3): ";
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

            bool succes = bord.beweeg_piece(x1, y1, x2, y2, huidigespeler);
            if (succes)
            {
                if (huidigespeler.get_kleur() == Kleur::Wit)
                {
                    huidigespeler = speler_2;
                }
                else
                {
                    huidigespeler = speler_1;
                }
            }
            bord.printbord();
            std::cout << "\n";
        }
    }

    else
    {
        bool succes;
        while (true)
        {

            if (huidigespeler.get_entity() == Entity::bot)
            {
                succes = bord.computer_beweeg_piece(huidigespeler.get_kleur());
            }
            else
            {
                std::cout << huidigespeler.get_naam() << ", voer een zet in (bijv. 1 2 1 3): ";
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

                succes = bord.beweeg_piece(x1, y1, x2, y2, huidigespeler);
            }
            if (succes)
            {
                if (huidigespeler.get_kleur() == Kleur::Wit)
                {
                    huidigespeler = speler_2;
                }
                else
                {
                    huidigespeler = speler_1;
                }
            }
            bord.printbord();
            std::cout << "\n";
        }
    }

    return 0;
}