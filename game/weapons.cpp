#include "weapons.h"

const std::string &Weapon::getName() const {
    return name;
}

void Weapon::setName(const std::string &name) {
    Weapon::name = name;
}

std::string Weapon::getInfo() {
    std::string info = name;

    if (damage_type == Physical)
        info += " [PHYSICAL]";
    else
        info += " [MAGICAL]";

    if (weapon_type == Melee)
        info += " [MELEE]";
    else
        info += " [LONG RANGE]";

    return info;
}

WeaponTypeEnum Weapon::getWeaponType() const {
    return weapon_type;
}

DamageTypeEnum Weapon::getDamageType() const {
    return damage_type;
}

int Weapon::getDamage() const {
    return damage;
}
