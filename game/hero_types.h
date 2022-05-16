
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

        [[nodiscard]] const std::string &getInfo() const { return name; }

        virtual void ability() = 0;
    };

    class Warrior : public HeroType {
    public:
        explicit Warrior() : HeroType() { name = "WARRIOR"; }
        void ability() override;
    };

    class Archer : public HeroType {
    public:
        explicit Archer() : HeroType() { name = "ARCHER"; }
        void ability() override;
    };

    class Wizard : public HeroType {
    public:
        explicit Wizard() : HeroType() { name = "WIZARD"; }
        void ability() override;
    };

#endif //CRPGAME_HERO_TYPES_H
