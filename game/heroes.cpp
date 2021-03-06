#include "heroes.h"

const std::string &Hero::getName() const {
    return name;
}

void Hero::setName(const std::string name) {
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

Weapon *Hero::getWeapon() const {
    return weapon;
}

void Hero::setWeapon(Weapon *weapon) {
    Hero::weapon = weapon;
}

Armor *Hero::getArmor() const {
    return armor;
}

void Hero::setArmor(Armor *armor) {
    Hero::armor = armor;
}

std::string Hero::getInfo(bool lite_info) {
    std::string info;

    info += name + " ";
    info += "[" + (race != nullptr ? race->getInfo() : "RACE") + "] ";
    info += "[" + (heroType != nullptr ? heroType->getInfo() : "CLASS") + "]\n";
    info += "[HP] [" + std::to_string(hit_point) + "/" + std::to_string(max_hit_point) + "]\n";

    if (!lite_info) {
        info += weapon->getInfo() + "\n";
        info += armor->getInfo() + "\n";
        info += "Strength: " + std::to_string(getStrength()) + "\n";
        info += "Agility: " + std::to_string(getAgility()) + "\n";
        info += "Intellect: " + std::to_string(getIntellect()) + "\n\n";

        info += "[INVENTORY]\n";
        if (potions.empty()) {
            info += "You have no potions!\n";
        }
        else {
            info += "You have " + std::to_string(potions.size()) + " healing potions!\n";
        }
    }

    return info;
}

int Hero::getHitPoint() const {
    return hit_point;
}

void Hero::setHitPoint(int hitpoint) {
    if (hitpoint > max_hit_point) hitpoint = max_hit_point;
    if (hitpoint < 0) hitpoint = 0;
    Hero::hit_point = hitpoint;
}

int Hero::getMaxHitPoint() const {
    return max_hit_point;
}

void Hero::reset() {
    hit_point = getStrength()*5;
    if (race->getInfo() == "ORC") hit_point *= 2;
    max_hit_point = hit_point;
}

int Hero::getStrength() const {
    int strength = race->getStrength();
    return strength;
}

int Hero::getAgility() const {
    int agility = race->getAgility();
    return agility;
}

int Hero::getIntellect() const {
    int intellect = race->getIntellect();
    return intellect;
}

void Hero::battleTick() {
    race->ability_tick();
}

std::string Hero::usePotion() {
    if (potions.empty()) return "You have no potions!";

    HealthPotion* potion = potions.front();

    potion->Use(*this);
    std::string potion_msg = "You used a potion and recovered " + std::to_string(potion->getPotionPower()) + " hp.";

    potions.pop();
    return potion_msg;
}

void Hero::addPotion(HealthPotion *potion) {
    potions.push(potion);
}

bool RandomNumber::is_initialized = false;

std::string RandomProperty::randomName(bool is_female_gender) {
    std::string male_names[5] = {"Taran", "Dolok", "Darwan", "Semil", "Isaac"};
    std::string female_names[5] = {"Marie", "Ella", "Katherine", "Eleanora", "Sarra"};

    if (is_female_gender)
        return female_names[RandomNumber::random(0, 4)];
    return male_names[RandomNumber::random(0, 4)];
}

Race *RandomProperty::randomRace() {
    Race *race;
    switch (RandomNumber::random(0, 2)) {
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

HeroType *RandomProperty::randomHeroType() {
    HeroType *heroType = nullptr;

    switch (RandomNumber::random(0, 2)) {
        case 0:
            heroType = new Warrior();
            break;
        case 1:
            heroType = new Archer();
            break;
        case 2:
            heroType = new Wizard();
            break;
    }

    return heroType;
}

Weapon *RandomProperty::randomWeapon() {
    Weapon *weapon = nullptr;

    switch (RandomNumber::random(0, 2)) {
        case 0:
            weapon = new Weapon("Sword", 10, WeaponTypeEnum::Melee, DamageTypeEnum::Physical);
            break;
        case 1:
            weapon = new Weapon("Bow", 7, WeaponTypeEnum::LongRange, DamageTypeEnum::Physical);
            break;
        case 2:
            weapon = new Weapon("Staff", 5, WeaponTypeEnum::Melee, DamageTypeEnum::Magical);
            break;
    }

    return weapon;
}

Armor *RandomProperty::randomArmor() {
    Armor *armor = nullptr;

    switch (RandomNumber::random(0, 2)) {
        case 0:
            armor = new Armor("Copper armour", ArmorTypeEnum::Heavy);
            break;
        case 1:
            armor = new Armor("Leather armour", ArmorTypeEnum::Medium);
            break;
        case 2:
            armor = new Armor("Cloth mantle", ArmorTypeEnum::Light);
            break;
    }

    return armor;
}

Hero *RandomHeroBuilder::build() {
    bool gender = RandomNumber::random(0, 1);

    builder.reset();

    builder.setName(RandomProperty::randomName(gender));
    builder.setRace(RandomProperty::randomRace());
    builder.setHeroType(RandomProperty::randomHeroType());
    builder.setWeapon(RandomProperty::randomWeapon());
    builder.setArmor(RandomProperty::randomArmor());

    return builder.getHero();
}
