#include <string>
class Pion
{
private:
    int m_kleur;
    int m_x;
    int m_y;
    std::string naam = "pion";

public:
    void verander_pos(int x, int y);
    Pion(int x, int y, int kleur);
};