#include "header_speler.h"

Speler::Speler(std::string naam, Kleur nieuwe_kleur, Entity entity) : m_naam(naam), m_kleur(nieuwe_kleur), m_entity(entity) {};
Speler::Speler() {};
Kleur Speler::get_kleur()
{
    return m_kleur;
};

Entity Speler::get_entity()
{
    return m_entity;
};