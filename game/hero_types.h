
#ifndef CRPGAME_HERO_TYPES_H
#define CRPGAME_HERO_TYPES_H

#include <iostream>
#include <string>

class HeroType {
    protected:
        std::string name;
    public:
        HeroType() = default;
        virtual ~HeroType() = default;

        [[nodiscard]] const std::string &getName() const { return name; }

        virtual void ability() = 0;
    };

    class Warrior : public HeroType {
    public:
        explicit Warrior(bool gender) : HeroType() { name = gender ? "Воительница" : "Воин"; }
        void ability() override;
    };

    class Archer : public HeroType {
    public:
        explicit Archer(bool gender) : HeroType() { name = gender ? "Лучница" : "Лучник"; }
        void ability() override;
    };

    class Wizard : public HeroType {
    public:
        explicit Wizard(bool gender) : HeroType() { name = gender ? "Волшебница" : "Волшебник"; }
        void ability() override;
    };

#endif //CRPGAME_HERO_TYPES_H
