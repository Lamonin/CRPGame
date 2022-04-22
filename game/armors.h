#ifndef CRPGAME_ARMORS_H
#define CRPGAME_ARMORS_H

#include <iostream>
#include <string>
#include <utility>

class Armor
{
private:
    std::string name;

public:
    Armor() = default;
    explicit Armor(std::string name):name(std::move(name)) { }
    ~Armor() = default;

    [[nodiscard]]const std::string &getName() const;
    void setName(const std::string &name);
};

#endif //CRPGAME_ARMORS_H
