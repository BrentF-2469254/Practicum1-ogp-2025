#pragma once
#include <string>
class Speler
{
public:
    Speler(std::string naam, int nieuwe_kleur, int entity); // constructor

private:
    std::string m_naam;
    int m_kleur;
    int m_entity;
};