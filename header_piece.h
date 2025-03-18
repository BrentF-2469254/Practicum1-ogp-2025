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
};