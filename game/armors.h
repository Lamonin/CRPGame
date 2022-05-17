#ifndef CRPGAME_ARMORS_H
#define CRPGAME_ARMORS_H

#include <iostream>
#include <string>
#include <utility>


enum ArmorTypeEnum { Heavy, Medium, Light };

class Armor
{
private:
    std::string name;
    ArmorTypeEnum armor_type {};

public:
    Armor() = default;
    explicit Armor(std::string name):name(std::move(name)) { }
    Armor(std::string name, ArmorTypeEnum armor_type):Armor(std::move(name))
    {
        this->armor_type = armor_type;
    }
    ~Armor() = default;

    [[nodiscard]] ArmorTypeEnum getArmorType() const;
    [[nodiscard]] const std::string &getName() const;
    [[nodiscard]] std::string getInfo();
};

#endif //CRPGAME_ARMORS_H
