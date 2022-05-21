#include "races.h"

std::string Race::getInfo() const {
    return name;
}

int Race::getStrength() const {
    return strength;
}

int Race::getAgility() const {
    return agility;
}

int Race::getIntellect() const {
    return intellect;
}

std::string Human::ability() {
    if (ability_ticks != 0)
    {
        return "Race ability is already used!";
    }
    ability_ticks = 3;

    strength += 1;
    agility += 1;
    intellect += 1;

    std::string ability_msg = "Human ability used! All characteristics are increased by 1 unit for 3 turns.";
    return ability_msg;
}

void Human::ability_tick() {
    if (ability_ticks<=0) return;
    ability_ticks--;

    if (ability_ticks==0)
    {
        strength -= 1;
        agility -= 1;
        intellect -= 1;
    }
}

std::string Orc::ability() {
    if (ability_ticks != 0)
    {
        return "Race ability is already used!";
    }
    ability_ticks = 3;

    strength += 5;
    std::string ability_msg = "Orc ability used! Strength increased by 5 units for 3 turns.";
    return ability_msg;
}

void Orc::ability_tick() {
    if (ability_ticks<=0) return;
    ability_ticks--;

    if (ability_ticks==0)
    {
        strength -= 5;
    }
}

std::string Elf::ability() {
    if (ability_ticks != 0)
    {
        return "Race ability is already used!";
    }
    ability_ticks = 3;

    intellect += 5;
    std::string ability_msg = "Elf ability used! Intellect increased by 5 units for 3 turns.";
    return ability_msg;
}

void Elf::ability_tick() {
    if (ability_ticks<=0) return;
    ability_ticks--;

    if (ability_ticks==0)
    {
        intellect -= 5;
    }
}
