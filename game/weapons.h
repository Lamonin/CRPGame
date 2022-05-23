#ifndef CRPGAME_WEAPONS_H
#define CRPGAME_WEAPONS_H

#include <iostream>
#include <string>
#include <utility>

enum class WeaponTypeEnum { Melee, LongRange};
enum class DamageTypeEnum {Physical, Magical};

class Weapon
{
private:
    std::string name;
    int damage{};
    WeaponTypeEnum weapon_type{};
    DamageTypeEnum damage_type{};

public:
    Weapon() = default;
    explicit Weapon(std::string name, int damage): name(std::move(name)), damage(damage) { }
    Weapon(std::string name, int damage, WeaponTypeEnum weapon_type, DamageTypeEnum damage_type): Weapon(std::move(name), damage)
    {
        this->weapon_type = weapon_type;
        this->damage_type = damage_type;
    }

    virtual ~Weapon() = default;

public:
    [[nodiscard]] const std::string &getName() const;
    void setName(const std::string &name);

    [[nodiscard]] std::string getInfo();

    [[nodiscard]] WeaponTypeEnum getWeaponType() const;

    [[nodiscard]] DamageTypeEnum getDamageType() const;

    [[nodiscard]] int getDamage() const;

    virtual std::string ability() { return "Your weapon has no ability!"; };
};

#endif //CRPGAME_WEAPONS_H
