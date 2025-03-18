#include <iostream>
#include <vector>
class Koningin : public Piece
{
private:
    std::string m_type;

public:
    std::vector<Point> valid_movements_pion(Point p, Kleur kleur = Kleur::Wit, Bord bord);
};