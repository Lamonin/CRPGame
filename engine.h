#ifndef CRPGAME_ENGINE_H
#define CRPGAME_ENGINE_H

#include <iostream>
#include <string>
#include <conio.h>
#include "bilist.h"
#include "game/events.h"
#include "game/character_editor.h"

namespace crpg
{
    void WaitUserReaction(const std::string& message = "");

    class BattleProcessor
    {
    public:
        event<> battleTickEvent;

    public:
        BattleProcessor()=default;
        virtual ~BattleProcessor()=default;

    public:
        void Attack(Hero* who, Hero* target);

        int GetPlayerTurn();

        int GetEnemyTurn();

        void PerformBattleAction(Hero*who, Hero* target, int num);
    };

    class Game
    {
    private:
        static void BeginBattle(Hero* player, Hero* enemy);
    public:
        static void Play();
    };
}

#endif //CRPGAME_ENGINE_H
