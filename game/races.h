#ifndef CRPGAME_RACES_H
#define CRPGAME_RACES_H

#include <iostream>
#include <string>

class Race {
protected:
    std::string name{};
    int strength{};
    int agility{};
    int intellect{};
    int ability_ticks;

public:
    Race() = default;
    virtual ~Race() = default;

    [[nodiscard]] const std::string &getInfo() const;

    [[nodiscard]] int getStrength() const;

    [[nodiscard]] int getAgility() const;

    [[nodiscard]] int getIntellect() const;

    virtual void ability_tick() = 0;

    virtual std::string ability() = 0;
};

class Human : public Race {
public:
    Human() : Race() {
        name = "HUMAN";
        strength = 12;
        agility = 12;
        intellect = 12;
    }

    std::string ability() override;

    void ability_tick() override;
};

class Orc : public Race {
public:
    Orc() : Race() {
        name = "ORC";
        strength = 14;
        agility = 12;
        intellect = 10;
    }

    std::string ability() override;

    void ability_tick() override;
};

class Elf : public Race {
public:
    Elf() : Race() {
        name = "ELF";
        strength = 10;
        agility = 12;
        intellect = 14;
    }

    std::string ability() override;

    void ability_tick() override;
};

#endif //CRPGAME_RACES_H
