#ifndef CRPGAME_CHARACTER_EDITOR_H
#define CRPGAME_CHARACTER_EDITOR_H

#include <iostream>
#include <string>
#include <vector>
#include "heroes.h"
#include "maro.h"


class HeroEditor {
private:
    bool gender;

    std::string ChooseName() const
    {
        std::string input;
        std::cout << "Введите имя: ";
        input = SafeConsoleInput<std::string>("","", [](std::string &t){return t.size() > 3;});
        return input;
    }

    bool ChooseGender()
    {
        std::cout << "\n\n1] Мужчина\n";
        std::cout << "2] Женщина\n";
        std::cout << "Пол персонажа: ";
        int gender_num = SafeConsoleInput<int>("", "", [](int &t) { return t>0 && t<3; });
        return --gender_num;
    }

    template<typename T>
    T* ChooseType(std::vector<T*> fromWhereChoose, const std::string& chooseMessage, int from, int to) const
    {
        std::cout << std::endl;
        for (int i = 0; i < fromWhereChoose.size(); ++i)
        {
            std::cout << i+1 << "] " << fromWhereChoose[i]->getName() << std::endl;
        }
        std::cout << chooseMessage;
        int num = SafeConsoleInput<int>("", "", [&from, &to](int &t) { return t > from && t < to; });

        T* temp = fromWhereChoose[--num];
        fromWhereChoose[num] = nullptr;
        for (auto r : fromWhereChoose) delete r;

        return temp;
    }

    Race* ChooseRace() const;

    HeroType* ChooseHeroType() const;

    Weapon* ChooseWeapon() const;

    Armor* ChooseArmor() const;

public:
    HeroEditor() = default;
    ~HeroEditor() = default;

    Hero *build()
    {
        HeroBuilder builder;

        builder.reset();
        gender = ChooseGender();
        builder.setName(ChooseName());
        builder.setRace(ChooseRace());
        builder.setHeroType(ChooseHeroType());
        builder.setWeapon(ChooseWeapon());
        builder.setArmor(ChooseArmor());

        return builder.getHero();
    }
};

#endif //CRPGAME_CHARACTER_EDITOR_H
