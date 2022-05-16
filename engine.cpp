#include "engine.h"
#include "bilist.h"

void crpg::Game::Play() {
    system("cls");
    std::cout << "Welcome to CRPG ARENA!\n\n";
    std::cout << "Create your own character:";

    //User create a hero
    HeroEditor heroEditor{};
    Hero* player = heroEditor.build();
    std::cout << std::endl << player->getInfo() << std::endl;

    std::cout << std::endl << "\nYour goal is to win three battles!\n";

    //Create all three enemies from the start
    bilist<Hero*> enemys;

    RandomHeroBuilder enemy_builder;
    enemys.push_back(enemy_builder.build());
    enemys.push_back(enemy_builder.build());
    enemys.push_back(enemy_builder.build());

    BeginBattle(player, enemys[0]);
    if (player->getHitPoint()>0) {
        BeginBattle(player, enemys[1]);
    }
    if (player->getHitPoint()>0) {
        BeginBattle(player, enemys[2]);

        std::cout << "\n\nYOU BECAME ARENA CHAMPION!\n\n";
        std::cout << "You have defeated these heroes:\n";
        for (Hero* enemy : enemys)
        {
            std::cout << std::endl << enemy->getInfo(true);
        }

        char t; std::cin>>t;
    }
}

void crpg::Game::BeginBattle(Hero *player, Hero *enemy) {
    BattleProcessor battle;

    bool is_player_turn = false;

    if (player->getAgility()>enemy->getAgility())
    {
        is_player_turn = true;
    }

    while (player->getHitPoint()>0 && enemy->getHitPoint()>0) {
        if (is_player_turn) {
            battle.PerformBattleAction(player, enemy, battle.GetPlayerTurn(player));
        } else {
            battle.PerformBattleAction(enemy, player, battle.GetEnemyTurn(enemy));
        }

        std::cout << std::endl << player->getInfo() << std::endl;
        std::cout << std::endl << enemy->getInfo(true) << std::endl;

        is_player_turn = !is_player_turn;
    }

    EndBattle(player);
}

void crpg::Game::EndBattle(Hero *player) {
    if (player->getHitPoint()<0) //Player is lose!
    {
        std::cout << "Unfortunately - you lose!\n";
        std::cout << "\nEnter any symbol and press [Enter] to continue!\n";
        char t; std::cin>>t;
        Play();
    }
    else
    {
        player->setHitPoint(player->getHitPoint()+20);
        std::cout << "You won the battle!\n";
    }
}

int crpg::BattleProcessor::GetPlayerTurn(Hero *player) {
    std::cout << "YOUR TURN!\n";

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

int crpg::BattleProcessor::GetEnemyTurn(Hero *enemy) {
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
            std::cout << "Let's imagine that you have used a health potion!";
            break;
    }
}
