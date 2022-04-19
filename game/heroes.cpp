#include "heroes.h"

const std::string &Hero::getName() const {
    return name;
}

void Hero::setName(const std::string &name) {
    Hero::name = name;
}

Race *Hero::getRace() const {
    return race;
}

void Hero::setRace(Race *race) {
    Hero::race = race;
}

HeroType *Hero::getHeroType() const {
    return heroType;
}

void Hero::setHeroType(HeroType *heroType) {
    Hero::heroType = heroType;
}

std::string RandomProperty::generateName(bool is_female_gender) {
    if (is_female_gender)
        return female_names[random(0, 4)];
    return male_names[random(0, 4)];
}

Race *RandomProperty::generateRace() {
    Race *race;
    switch (random(0, 2)) {
        case 0:
            race = new Human();
            break;
        case 1:
            race = new Orc();
            break;
        case 2:
            race = new Elf();
            break;
    }
    return race;
}

HeroType *RandomProperty::generateHeroType(bool is_female_gender) {
    HeroType *heroType = nullptr;

    switch (random(0, 2)) {
        case 0:
            heroType = new Warrior(is_female_gender);
            break;
        case 1:
            heroType = new Archer(is_female_gender);
            break;
        case 2:
            heroType = new Wizard(is_female_gender);
            break;
    }

    return heroType;
}

Hero *RandomHeroBuilder::build() {
    bool gender = rProperty.random(0, 1);

    builder.reset();

    builder.setName(rProperty.generateName(gender));
    builder.setRace(rProperty.generateRace());
    builder.setHeroType(rProperty.generateHeroType(gender));

    return builder.getHero();
}
