#include "header_piece.h"

Piece::Piece(Kleur kleur, int x, int y) : m_kleur(kleur), m_x(x), m_y(y) {};

void Piece::verander_pos(int x, int y)
{
    m_x = x;
    m_y = y;
};