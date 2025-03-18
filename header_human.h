#include "header_speler.h"

class Human : public Speler
{
public:
    Human(std::string naam, Kleur kleur);
    bool beweeg_piece();
};