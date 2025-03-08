#pragma once
#include <string>
#include "header_entity.h"
class Speler
{
public:
    Speler(std::string naam, int nieuwe_kleur, Entity entity); // constructor

private:
    std::string m_naam;
    int m_kleur;
    Entity m_entity;
};