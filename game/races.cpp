#include "races.h"

const std::string &Race::getName() const {
    return name;
}

int Race::getStrength() const {
    return strength;
}

void Race::setStrength(int strength) {
    Race::strength = strength;
}

int Race::getAgility() const {
    return agility;
}

void Race::setAgility(int agility) {
    Race::agility = agility;
}

int Race::getIntelligence() const {
    return intelligence;
}

void Race::setIntelligence(int intelligence) {
    Race::intelligence = intelligence;
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
