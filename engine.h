#ifndef CRPGAME_ENGINE_H
#define CRPGAME_ENGINE_H

#include <iostream>
#include <string>

namespace crpg
{
    class Race
    {
    public:
        int strength{};
        int agility{};
        int intelligence{};
        std::string name{};

        Race() = default;
    };

    class Human: public Race
    {
    public:
        Human() : Race()
        {
            name  = "Человек";
            strength = 10;
            agility = 10;
            intelligence = 10;
        }
    };

    class Orc: public Race
    {
    public:
        Orc() : Race()
        {
            name  = "Орк";
            strength = 10;
            agility = 10;
            intelligence = 10;
        }
    };

    class Elf: public Race
    {
    public:
        Elf() : Race()
        {
            name  = "Эльф";
            strength = 10;
            agility = 10;
            intelligence = 10;
        }
    };

    class Hero
    {
    private:
        int strength{};
        int agility{};
        int intelligence{};

        Race* race{};

    public:
        Hero() = default;
        Hero(Hero&& rhs) noexcept { std::cout << "CPP HELL"; }

        void setRace(Race* _race)
        {
            race = _race;
        }

        const Race* getRace()
        {
            return race;
        }
    };

    class HeroBuilder
    {
    private:
        Hero hero;

    public:
        HeroBuilder() = default;
        ~HeroBuilder() = default;

        void setRace(Race* _race)
        {
            hero.setRace(_race);
        }

        Hero&& getHero()
        {
            return std::move(hero);
        }
    };


}

#endif //CRPGAME_ENGINE_H
