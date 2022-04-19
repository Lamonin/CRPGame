#ifndef CRPGAME_WEAPONS_H
#define CRPGAME_WEAPONS_H

#include <iostream>
#include <string>

class Weapon
{
private:

public:
    Weapon() = default;
    ~Weapon() = default;

    virtual void ability() { std::cout << "У оружия нет способности!" << std::endl; };
};

#endif //CRPGAME_WEAPONS_H
