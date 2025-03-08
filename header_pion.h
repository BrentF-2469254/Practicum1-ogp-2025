#pragma once
#include <string>
#include "header_kleur.h"
class Pion
{
private:
    int m_kleur;
    int m_x;
    int m_y;
    std::string piece_type = "pion";

public:
    void verander_pos(int x, int y);
    Pion(int x, int y, Kleur kleur);
    Pion();
    int getKleur() const
    {
        return m_kleur;
    }
    std::string get_piece_type()
    {
        return piece_type;
    }
};