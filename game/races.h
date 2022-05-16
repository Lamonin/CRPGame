#ifndef CRPGAME_RACES_H
#define CRPGAME_RACES_H

#include <iostream>
#include <string>

class Race {
protected:
    std::string name{};
    int strength{};
    int agility{};
    int intelligence{};

public:
    Race() = default;
    virtual ~Race() = default;

    [[nodiscard]] const std::string &getInfo() const;

    [[nodiscard]] int getStrength() const;

    [[nodiscard]] int getAgility() const;

    [[nodiscard]] int getIntellect() const;

    virtual void ability() = 0;
};

class Human : public Race {
public:
    Human() : Race() {
        name = "HUMAN";
        strength = 12;
        agility = 12;
        intelligence = 12;
    }

    void ability() override;
};

class Orc : public Race {
public:
    Orc() : Race() {
        name = "ORC";
        strength = 14;
        agility = 12;
        intelligence = 10;
    }

    void ability() override;
};

class Elf : public Race {
public:
    Elf() : Race() {
        name = "ELF";
        strength = 10;
        agility = 12;
        intelligence = 14;
    }

    void ability() override;
};

#endif //CRPGAME_RACES_H
