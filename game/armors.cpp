#include "armors.h"

const std::string &Armor::getName() const {
    return name;
}

std::string Armor::getInfo() {
    std::string info = name + " [ARMOUR] ";

    switch (armor_type) {
        case ArmorTypeEnum::Heavy:
            info += "[HEAVY]";
            break;
        case ArmorTypeEnum::Medium:
            info += "[MEDIUM]";
            break;
        case ArmorTypeEnum::Light:
            info += "[LIGHT]";
            break;
    }

    return info;
}

ArmorTypeEnum Armor::getArmorType() const {
    return armor_type;
}
