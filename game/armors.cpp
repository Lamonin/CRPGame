#include "armors.h"

const std::string &Armor::getName() const {
    return name;
}

void Armor::setName(const std::string &name) {
    Armor::name = name;
}
