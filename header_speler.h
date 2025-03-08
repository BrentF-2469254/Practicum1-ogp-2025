#pragma once
#include <string>
#include "header_entity.h"
#include "header_kleur.h"
class Speler
{
public:
    Speler(std::string naam, Kleur nieuwe_kleur, Entity entity); // constructor
    Speler();
    Kleur get_kleur();

private:
    std::string m_naam;
    Kleur m_kleur;
    Entity m_entity;
};