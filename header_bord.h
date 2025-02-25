#pragma once
#include "header_pion.h"
class Bord
{
private:
    Pion *arr[8][8];

public:
    void printbord() const;
    void beweeg_piece(int x1, int y1, int x2, int y2);
    void valid_movements_pion(int x1, int y1);
    Bord();
    ~Bord();
};