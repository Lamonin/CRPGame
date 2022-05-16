#ifndef CRPGAME_ENGINE_H
#define CRPGAME_ENGINE_H

#include <iostream>
#include <string>
#include "game/character_editor.h"


namespace crpg
{
    class BattleProcessor
    {
    public:
        BattleProcessor()=default;
        ~BattleProcessor()=default;

        void Attack(Hero* who, Hero* target);

        int GetPlayerTurn(Hero* player);

        int GetEnemyTurn(Hero* enemy);

        void PerformBattleAction(Hero*who, Hero* target, int num);
    };

    class Game
    {
    private:
        static void BeginBattle(Hero* player, Hero* enemy);
        static void EndBattle(Hero* player);
    public:
        static void Play();
    };
}

#endif //CRPGAME_ENGINE_H
