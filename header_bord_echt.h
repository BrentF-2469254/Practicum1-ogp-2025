#include "header_piece.h"
#include <vector>
class Bord
{
private:
    Piece *arr[8][8];

public:
    void printbord();
    Piece **get_current_bord()
    {
        return *arr;
    }
};