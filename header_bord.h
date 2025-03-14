#pragma once
#include "header_pion.h"
#include "header_speler.h"
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
    int m_keuze;

public:
    void printbord() const;
    bool beweeg_piece(int x1, int y1, int x2, int y2, Speler huidigespeler);
    std::vector<Point> valid_movements_pion(int x1, int y1, bool firstMove = false, Kleur kleur = Kleur::Wit);
    bool is_pion_op_positie(int x, int y) const;
    bool computer_beweeg_piece(Kleur kleur_van_bot); // als deze een false returned dan is die gecheckmate onthoud
    Bord();
    ~Bord();
};