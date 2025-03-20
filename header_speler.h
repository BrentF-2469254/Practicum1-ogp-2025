#pragma once
#include <string>
#include "header_kleur.h"
#include "header_piece.h"
#include <iostream>
#include "header_point.h"
class Speler
{
public:
    Speler(std::string naam, Kleur kleur);
    Kleur get_kleur();
    std::string get_naam();
    virtual bool beweeg_piece(Piece **array) = 0;

protected:
    std::string m_naam;
    Kleur m_kleur;
};