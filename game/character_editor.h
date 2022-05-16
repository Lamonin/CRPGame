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

    [[nodiscard]] std::string ChooseName() const;

    [[nodiscard]] bool ChooseGender();

    template<typename T>
    T* ChooseType(std::vector<T*> whereChoose, const std::string& message, int index_from, int index_to) const
    {
        std::cout << std::endl;
        for (int i = 0; i < whereChoose.size(); ++i)
            std::cout << i+1 << "] " << whereChoose[i]->getInfo() << std::endl;

        std::cout << message;

        int num = SafeConsoleInput<int>("", "", [&index_from, &index_to](int &t)
        {
            return t > index_from && t < index_to;
        });

        T* temp = whereChoose[--num];
        whereChoose[num] = nullptr;
        for (auto r : whereChoose) delete r;

        return temp;
    }

    [[nodiscard]] Race* ChooseRace() const;

    [[nodiscard]] HeroType* ChooseHeroType() const;

    [[nodiscard]] Weapon* ChooseWeapon() const;

    [[nodiscard]] Armor* ChooseArmor() const;

public:
    HeroEditor() = default;
    ~HeroEditor() = default;

    Hero *build();
};

#endif //CRPGAME_CHARACTER_EDITOR_H
