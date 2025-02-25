#pragma once
#include <string>
class Speler
{
public:
    bool aan_de_beurt() const;

private:
    std::string m_naam;
};