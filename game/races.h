
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

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] int getStrength() const;
    void setStrength(int strength);

    [[nodiscard]] int getAgility() const;
    void setAgility(int agility);

    [[nodiscard]] int getIntelligence() const;
    void setIntelligence(int intelligence);

    virtual void ability() = 0;
};

class Human : public Race {
public:
    Human() : Race() {
        name = "Человек";
        strength = 12;
        agility = 12;
        intelligence = 12;
    }

    void ability() override;
};

class Orc : public Race {
public:
    Orc() : Race() {
        name = "Орк";
        strength = 14;
        agility = 12;
        intelligence = 10;
    }

    void ability() override;
};

class Elf : public Race {
public:
    Elf() : Race() {
        name = "Эльф";
        strength = 10;
        agility = 12;
        intelligence = 14;
    }

    void ability() override;
};

#endif //CRPGAME_RACES_H
