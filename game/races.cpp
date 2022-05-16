#include "races.h"

const std::string &Race::getInfo() const {
    return name;
}

int Race::getStrength() const {
    return strength;
}

int Race::getAgility() const {
    return agility;
}

int Race::getIntellect() const {
    return intelligence;
}


void Human::ability() {
    std::cout << "Способность людей!" << std::endl;
}

void Orc::ability() {
    std::cout << "Способность орков!" << std::endl;
}

void Elf::ability() {
    std::cout << "Способность эльфов!" << std::endl;
}
