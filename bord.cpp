#include "header_bord.h"
#include "header_pion.h"
#include "header_kleur.h"
Bord::Bord()
{
    for (int i = 0; i < 8; i++)
    {
        arr[i][1] = Pion(i, 1, Kleur::Wit);
    }

    for (int i = 0; i < 8; i++)
    {
        arr[i][6] = Pion(i, 6, Kleur::Zwart);
    }
}