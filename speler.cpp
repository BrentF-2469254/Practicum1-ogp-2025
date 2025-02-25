#include "header_speler.h"

Speler::Speler(std::string naam) : m_naam(naam) {};
void Speler::setKleur(int nieuwe_kleur)
{
    if (nieuwe_kleur == 0 || nieuwe_kleur == 1)
    {
        kleur = nieuwe_kleur;
    }
}