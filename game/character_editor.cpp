#include "character_editor.h"

bool HeroEditor::ChooseGender() {
    std::cout << "\n\n1] Male\n";
    std::cout << "2] Female\n";
    std::cout << "Character gender: ";
    int gender_num = SafeConsoleInput<int>("", "", [](int &t) { return t>0 && t<3; });
    return --gender_num;
}

std::string HeroEditor::ChooseName() const {
    std::string input;
    std::cout << "Enter the hero name: ";
    input = SafeConsoleInput<std::string>("","", [](std::string &t){return t.size() > 2;});
    return input;
}

Race *HeroEditor::ChooseRace() const {
    std::vector<Race*> avaiable_races = {new Human, new Orc, new Elf};
    return ChooseType(avaiable_races, "Choose a race: ", 0, 4);
}

HeroType *HeroEditor::ChooseHeroType() const {
    std::vector<HeroType*> avaiable_heroTypes = { new Warrior(), new Archer(), new Wizard() };
    return ChooseType(avaiable_heroTypes, "Choose a class: ", 0, 4);
}

Weapon *HeroEditor::ChooseWeapon() const {
    std::vector<Weapon*> avaiable_weapons= {
            new Weapon("Sword", 10, WeaponTypeEnum::Melee, DamageTypeEnum::Physical),
            new Weapon("Bow", 7, WeaponTypeEnum::LongRange, DamageTypeEnum::Physical),
            new Weapon("Staff", 5, WeaponTypeEnum::Melee, DamageTypeEnum::Magical)
    };
    return ChooseType(avaiable_weapons, "Choose a weapon: ", 0, 4);
}

Armor *HeroEditor::ChooseArmor() const {
    std::vector<Armor*> avaiable_armors = {
            new Armor("Copper armour", ArmorTypeEnum::Heavy),
            new Armor("Leather armour", ArmorTypeEnum::Medium),
            new Armor("Cloth mantle", ArmorTypeEnum::Light)
    };
    return ChooseType(avaiable_armors, "Choose an armour: ", 0, 4);
}

Hero *HeroEditor::build() {
    HeroBuilder builder;
    builder.reset();

    gender = ChooseGender();
    std::cout << std::endl;
    builder.setName(ChooseName());
    builder.setRace(ChooseRace());
    builder.setHeroType(ChooseHeroType());
    builder.setWeapon(ChooseWeapon());
    builder.setArmor(ChooseArmor());

    return builder.getHero();
}
