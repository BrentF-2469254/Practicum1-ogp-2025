#pragma once
#include <string>
#include <vector>
#include "header_kleur.h"
#include "header_piece.h"
class Pion : public Piece
{
private:
    std::string piece_type = "pion";

public:
    Pion(Kleur kleur, int x, int y);

    std::string get_piece_type()
    {
        return piece_type;
    }
    std::vector<Point> valid_movements_pion(Point p, Piece **array);
};