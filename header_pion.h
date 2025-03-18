#pragma once
#include <string>
#include <vector>
#include "header_kleur.h"
#include "header_piece.h"
class Pion : public Piece
{
private:
    int m_kleur;
    int m_x;
    int m_y;
    std::string piece_type = "pion";

public:
    Pion(Kleur kleur, int x, int y);
    int getKleur() const
    {
        return m_kleur;
    }
    std::string get_piece_type()
    {
        return piece_type;
    }
    std::vector<Point> valid_movements_pion(Point p);
};