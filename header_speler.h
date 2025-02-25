#pragma once
#include <string>
class Speler
{
public:
    bool aan_de_beurt() const;
    Speler(std::string naam);        // constructor
    void setKleur(int nieuwe_kleur); // setter

private:
    std::string m_naam;
    int kleur;
};