#include "engine.h"

void crpg::Game::Play() {
    RandomHeroBuilder enemy_builder;
    HeroEditor hero_editor{};
    Hero* player;

    bool is_still_played = true;
    while(is_still_played)
    {
        system("cls");
        std::cout << "Welcome to CRPG ARENA!\n\nCreate your own character:";

        //User create a hero
        player = hero_editor.build();

        system("cls");
        std::cout << "[YOUR HERO]\n";
        std::cout << std::endl << player->getInfo();
        std::cout << std::endl << "[!!!]Your goal is to win three battles![!!!]\n";
        WaitUserReaction("\nPress any key to continue!");

        //Create all three enemies from the start
        bilist<Hero*> enemys;
        enemys.push_back(enemy_builder.build());
        enemys.push_back(enemy_builder.build());
        enemys.push_back(enemy_builder.build());

        for (auto & enemy : enemys)
        {
            BeginBattle(player, enemy);

            if (player->getHitPoint()<0) break;

            player->setHitPoint(player->getHitPoint()+20);
            system("cls");
            std::cout << "<<<YOU WON THE BATTLE!>>>\n";
            WaitUserReaction("\nPress any key to continue!");
        }

        enemys.clear();

        if (player->getHitPoint()<0) {
            std::cout << "Unfortunately - you lose!\n";
        }
        else {
            is_still_played = false;
            std::cout << "\n\n<<<YOU BECAME ARENA CHAMPION!>>>\n\n";
        }
        WaitUserReaction("\nPress any key to continue!");
    }
}

void crpg::Game::BeginBattle(Hero *player, Hero *enemy) {
    BattleProcessor battle;

    system("cls");
    std::cout << "[YOUR ENEMY]\n";
    std::cout << std::endl << enemy->getInfo(true) << std::endl;
    WaitUserReaction("\nPress any key to start battle!");

    bool is_player_turn = false;
    if (player->getAgility()>enemy->getAgility())
    {
        is_player_turn = true;
    }

    while (player->getHitPoint()>0 && enemy->getHitPoint()>0) {
        if (is_player_turn) {
            battle.PerformBattleAction(player, enemy, battle.GetPlayerTurn());
        } else {
            system("cls");
            std::cout << "[ENEMY TURN]\n\n";
            int enemy_action = battle.GetEnemyTurn();
            battle.PerformBattleAction(enemy, player, enemy_action);
            if (enemy_action == 1)
            {
                std::cout << enemy->getName() << " attacks you!\n";
            }
            WaitUserReaction("\nPress any key to continue!");
        }

        system("cls");
        std::cout << "YOUR TURN\n";
        std::cout << std::endl << player->getInfo();
        std::cout << std::endl << enemy->getInfo(true) << std::endl;

        is_player_turn = !is_player_turn;
    }
}

int crpg::BattleProcessor::GetPlayerTurn() {
    std::cout << "Choose action:\n";
    std::cout << "1] Attack\n";
    std::cout << "2] Use weapon ability\n";
    std::cout << "3] Use race ability\n";
    std::cout << "4] Use potion\n";
    std::cout << "Input: ";
    int num = SafeConsoleInput<int>("", "Incorrect action! Try again: ", [](int &t){
            return t > 0 && t < 5;
        });
    return num;
}

int crpg::BattleProcessor::GetEnemyTurn() {
    return RandomNumber::random(1,4);
}

void crpg::BattleProcessor::Attack(Hero *who, Hero *target) {
    target->setHitPoint(target->getHitPoint() - who->getWeapon()->getDamage());
}

void crpg::BattleProcessor::PerformBattleAction(Hero*who, Hero* target, int num) {
    switch (num) {
        case 1: //ATTACK ACTION
            Attack(who, target);
            break;
        case 2: //USE WEAPON ABILITY ACTION
            who->getWeapon()->ability();
            break;
        case 3: //USE RACE ABILITY ACTION
            who->getRace()->ability();
            break;
        case 4: //USE POTION ACTION
            std::cout << "Let's imagine that you have used a health potion!\n";
            break;
    }
}

void crpg::WaitUserReaction(const string &message) {
    std::cout << message;
    getch();
}
