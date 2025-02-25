#pragma once
#include "header_pion.h"
#include <iostream>
#include <vector>
struct Point
{
    int x, y;
};
class Bord
{
private:
    Pion *arr[8][8];

public:
    void printbord() const;
    void beweeg_piece(int x1, int y1, int x2, int y2);
    std::vector<Point> valid_movements_pion(int x1, int y1, bool firstMove = false);
    Bord();
    ~Bord();
};