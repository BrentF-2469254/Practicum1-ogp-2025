#pragma once
#include <string>
#include "header_kleur.h"
#include "header_piece.h"
class Speler
{
public:
    Speler(std::string naam, Kleur kleur);
    Kleur get_kleur();
    std::string get_naam();
    virtual bool beweeg_piece(Piece **array) = 0;

private:
    std::string m_naam;
    Kleur m_kleur;
};