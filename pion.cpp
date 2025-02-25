#include "header_pion.h"
#include "header_kleur.h"
void Pion::verander_pos(int x, int y)
{
    m_x = x;
    m_y = y;
}

Pion::Pion(int x, int y, Kleur kleur)
{
    m_x = x,
    m_y = y;
    m_kleur = kleur;
}

Pion::Pion() : m_x(0), m_y(0), m_kleur(0) {}