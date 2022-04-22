//
// Created by mazez on 22.04.2022.
//

#include "character_editor.h"

Race *HeroEditor::ChooseRace() const {
    std::vector<Race*> avaiable_races = {new Human, new Orc, new Elf};
    return ChooseType(avaiable_races, "Выберите расу: ", 0, 4);
}

HeroType *HeroEditor::ChooseHeroType() const {
    std::vector<HeroType*> avaiable_heroTypes = {new Warrior(gender), new Archer(gender), new Wizard(gender)};
    return ChooseType(avaiable_heroTypes, "Выберите класс: ", 0, 4);
}

Weapon *HeroEditor::ChooseWeapon() const {
    std::vector<Weapon*> avaiable_heroTypes = {new Weapon("Меч"),new Weapon("Лук"),new Weapon("Посох") };
    return ChooseType(avaiable_heroTypes, "Выберите оружие: ", 0, 4);
}

Armor *HeroEditor::ChooseArmor() const {
    std::vector<Armor*> avaiable_heroTypes = {new Armor("Нагрудник"),new Armor("Шлем"),new Armor("Мантия") };
    return ChooseType(avaiable_heroTypes, "Выберите броню: ", 0, 4);
}


