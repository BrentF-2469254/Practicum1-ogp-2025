#include <iostream>
#include <vector>
#include "header_piece.h"
class Koningin : public Piece
{
private:
    std::string m_type;

public:
    std::vector<Point> valid_movements_koningin(Point p, Piece **array);
};