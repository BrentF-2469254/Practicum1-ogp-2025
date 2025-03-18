#include "header_speler.h"

Speler::Speler(std::string naam, Kleur nieuwe_kleur) : m_naam(naam), m_kleur(nieuwe_kleur) {};

Kleur Speler::get_kleur()
{
    return m_kleur;
};

std::string Speler::get_naam()
{
    return m_naam;
}