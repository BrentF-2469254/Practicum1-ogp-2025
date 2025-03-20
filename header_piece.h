#include <string>
#include <vector>
#include "header_point.h"
#include "header_kleur.h"
class Piece
{
private:
    Kleur m_kleur;
    int m_x, m_y;

public:
    Kleur get_kleur()
    {
        return m_kleur;
    };

    Piece(Kleur kleur, int x, int y);
    void verander_pos(int x, int y);
    virtual std::vector<Point> valid_movements(Point p, Piece **array) = 0;
};