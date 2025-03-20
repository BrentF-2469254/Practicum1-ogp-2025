#include "header_human.h"

Human::Human(std::string naam, Kleur kleur) : Speler(naam, kleur) {};

bool Human::beweeg_piece(Piece **array)
{
    int x1, y1, x2, y2;
    int keuze;
    while (true)
    {
        /*std::cout << m_naam << ", wil je opgeven?\n0: Ja\n1: Nee\n";
        std::cin >> keuze;

        if (keuze == 0) {
            std::cout << m_naam << " heeft opgegeven.\n";
            return false;  // Speler geeft op
        }*/

        std::cout << m_naam << " geef x en y waarde van wat je wilt selecteren: ";
        std::cin >> x1 >> y1;
        x1--;
        y1--;
        Point p1 = {x1, y1};

        // Controleer of het geselecteerde stuk van de juiste kleur is
        if (get_kleur() != array[x1][y1].get_kleur())
        {
            std::cout << "Ongeldige keuze! Je kunt alleen je eigen stukken verplaatsen.\n";
            continue; // Opnieuw vragen om invoer
        }

        std::vector<Point> valid = array[x1][y1].valid_movements(p1, array);

        std::cout << m_naam << " geef x en y waar je wilt zetten: ";
        std::cin >> x2 >> y2;
        x2--;
        y2--;
        Point p2 = {x2, y2};

        // Controleer of de gekozen zet geldig is
        if (std::find(valid.begin(), valid.end(), p2) == valid.end())
        {
            std::cout << "Ongeldige zet! Kies een geldige positie.\n";
            continue; // Opnieuw vragen om invoer
        }

        // Als beide checks goed zijn, breek de lus
        break;
    }
    array[x2][y2] = array[x1][y2];
    array[x1][y1] = nullptr;
    array[x2][y2].verander_pos(x2, y2);
    // Voer de zet uit (dit deel kun je verder uitbreiden)
    std::cout << "Zet uitgevoerd van (" << x1 + 1 << ", " << y1 + 1 << ") naar (" << x2 + 1 << ", " << y2 + 1 << ").\n";
    return true;
}