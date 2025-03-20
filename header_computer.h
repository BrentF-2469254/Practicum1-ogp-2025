#include "header_speler.h"
class Computer : public Speler
{
public:
    Computer(Kleur kleur, std::string naam = "computer");
    bool beweeg_piece(Piece ***array);
};