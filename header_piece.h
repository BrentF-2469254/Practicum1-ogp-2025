#include "header_point.h"
#include "header_kleur.h"
#include <string>
#include <vector>
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
    virtual std::vector<Point> valid_movements(Point p, Piece **array) = 0;
    Piece(Kleur kleur, int x, int y);
    void verander_pos(int x, int y);
};