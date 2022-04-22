#ifndef CRPGAME_WEAPONS_H
#define CRPGAME_WEAPONS_H

#include <iostream>
#include <string>
#include <utility>

class Weapon
{
private:
    std::string name;

public:
    Weapon() = default;
    explicit Weapon(std::string name):name(std::move(name)) { }
    ~Weapon() = default;

    [[nodiscard]] const std::string &getName() const;
    void setName(const std::string &name);

    virtual void ability() { std::cout << "У оружия нет способности!" << std::endl; };
};

#endif //CRPGAME_WEAPONS_H
