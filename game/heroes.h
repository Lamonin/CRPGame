#ifndef CRPGAME_HEROES_H
#define CRPGAME_HEROES_H

#include <iostream>
#include <string>
#include <vector>
#include "races.h"
#include "hero_types.h"
#include "weapons.h"
#include "armors.h"
#include "items.h"

class Hero {
private:
    std::string name{};
    int hit_point{};
    int max_hit_point{};

    Race *race{};
    HeroType *heroType{};
    Weapon* weapon{};
    Armor* armor{};

    std::vector<HealthPotion*> potions;

public:
    Hero()
    {
        name = "DEFAULT";
    }

    virtual ~Hero() {
        delete race;
        delete heroType;
    }

public:
    //Reset HP to full
    void reset();

    void battleTick()
    {
        race->ability_tick();
    }

    std::string usePotion();

    void addPotion(HealthPotion* potion)
    {
        potions.push_back(potion);
    }

public:

    [[nodiscard]] const std::string &getName() const;
    void setName(std::string name);

    [[nodiscard]] Race *getRace() const;
    void setRace(Race *race);

    [[nodiscard]] HeroType *getHeroType() const;
    void setHeroType(HeroType *heroType);

    [[nodiscard]] Weapon *getWeapon() const;
    void setWeapon(Weapon *weapon);

    [[nodiscard]] Armor *getArmor() const;
    void setArmor(Armor *armor);

    [[nodiscard]] int getHitPoint() const;
    void setHitPoint(int hitpoint);

    [[nodiscard]] int getMaxHitPoint() const;

    [[nodiscard]] int getStrength() const;

    [[nodiscard]] int getAgility() const;

    [[nodiscard]] int getIntellect() const;

    std::string getInfo(bool lite_info = false);
};

class HeroBuilder {
private:
    Hero *hero;

public:
    HeroBuilder() : hero(nullptr) {}
    virtual ~HeroBuilder() { delete hero; }

    void setRace(Race *race) { hero->setRace(race); }
    void setHeroType(HeroType *heroType) { hero->setHeroType(heroType); }
    void setName(const std::string &name) { hero->setName(name); }
    void setWeapon(Weapon *weapon) { hero->setWeapon(weapon); }
    void setArmor(Armor *armor) { hero->setArmor(armor); }

    void reset() {
        delete hero;
        hero = new Hero();
    }

    [[nodiscard]] Hero *getHero() {
        hero->reset();
        Hero *temp = hero;
        hero = nullptr;
        return temp;
    }
};

class RandomNumber {
public:
    RandomNumber() = default;
    virtual ~RandomNumber() = default;

    static bool is_initialized;

    static int random(const int min, const int max)
    {
        if (!is_initialized) {
            srand(time(nullptr));
            is_initialized = true;
        }
        return rand() % (max - min + 1) + min;
    }
};

class RandomProperty {
public:
    RandomProperty() = default;
    virtual ~RandomProperty() = default;

    static std::string randomName(bool is_female_gender);
    static Race *randomRace();
    static HeroType *randomHeroType();
    static Weapon *randomWeapon();
    static Armor *randomArmor();
};

class RandomHeroBuilder {
private:
    HeroBuilder builder;
    RandomProperty rProperty;

public:
    RandomHeroBuilder() = default;
    virtual ~RandomHeroBuilder() = default;
    [[nodiscard]] Hero *build();
};

#endif //CRPGAME_HEROES_H
