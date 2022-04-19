#ifndef CRPGAME_HEROES_H
#define CRPGAME_HEROES_H

#include <iostream>
#include <string>
#include "races.h"
#include "hero_types.h"

class Hero {
private:
    std::string name{};
    int strength{};
    int agility{};
    int intelligence{};

    Race *race{};
    HeroType *heroType{};
    //Weapon* weapon;
    //Armor* armor;

public:
    Hero() = default;

    ~Hero() {
        delete race;
        delete heroType;
    }

    [[nodiscard]] const std::string &getName() const;
    void setName(const std::string &name);

    [[nodiscard]] Race *getRace() const;
    void setRace(Race *race);

    [[nodiscard]] HeroType *getHeroType() const;
    void setHeroType(HeroType *heroType);

    std::string getInfo() {
        std::string info;

        info += name + " ";
        info += "[" + heroType->getName() + "] ";
        info += "[" + race->getName() + "]\n";

        return info;
    }

};

class HeroBuilder {
private:
    Hero *hero;

public:
    HeroBuilder() : hero(nullptr) {}
    ~HeroBuilder() { delete hero; }

    void setRace(Race *race) { hero->setRace(race); }
    void setHeroType(HeroType *heroType) { hero->setHeroType(heroType); }
    void setName(const std::string &name) { hero->setName(name); }

    void reset() {
        delete hero;
        hero = new Hero();
    }

    [[nodiscard]] Hero *getHero() {
        Hero *temp = hero;
        hero = nullptr;
        return temp;
    }
};

class RandomNumber {
public:
    RandomNumber() {
        srand(time(nullptr));
    }

    int random(const int min, const int max) { return rand() % (max - min + 1) + min; }
};

class RandomProperty {
private:
    RandomNumber rNumber;
private:
    std::string male_names[5] = {"Таран", "Долок", "Дарван", "Семил", "Исаак"};
    std::string female_names[5] = {"Мари", "Элла", "Катерин", "Элеанор", "Сарра"};

public:
    RandomProperty() = default;
    ~RandomProperty() = default;

    std::string generateName(bool is_female_gender);
    Race *generateRace();
    HeroType *generateHeroType(bool is_female_gender);

    int random(const int min, const int max) { return rNumber.random(min, max); }
};

class RandomHeroBuilder {
private:
    HeroBuilder builder;
    RandomProperty rProperty;

public:
    RandomHeroBuilder() = default;
    ~RandomHeroBuilder() = default;
    [[nodiscard]] Hero *build();
};

#endif //CRPGAME_HEROES_H
