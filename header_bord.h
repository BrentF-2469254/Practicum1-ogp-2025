#include "header_pion.h"
class Bord
{
private:
    Pion arr[8][8];

public:
    void printbord();
    void beweeg_pion(int x1, int y1);
    void beweeg_piece(int x1, int y1, int x2, int y2);
    void valid_pion(int x1, int y1);
    Bord();
};