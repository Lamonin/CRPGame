#include "weapons.h"

const std::string &Weapon::getName() const {
    return name;
}

void Weapon::setName(const std::string &name) {
    Weapon::name = name;
}
