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

        for(int i = 0; i<RandomNumber::random(1,3); ++i)
        {
            player->addPotion(new HealthPotion(25));
        }

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
            system("cls");
            std::cout << "Unfortunately - you lose!\n";
        }
        else {
            is_still_played = false;
            system("cls");
            std::cout << "<<<YOU BECAME ARENA CHAMPION!>>>\n";
        }
        WaitUserReaction("\nPress any key to continue!");
    }
}

void crpg::Game::BeginBattle(Hero *player, Hero *enemy) {
    BattleProcessor battle;
    battle.battleTickEvent.bind("playerTickHandle", std::bind(&Hero::battleTick, player));
    battle.battleTickEvent.bind("enemyTickHandle", std::bind(&Hero::battleTick, enemy));

    system("cls");
    std::cout << "[YOUR ENEMY]\n";
    std::cout << std::endl << enemy->getInfo(true) << std::endl;
    WaitUserReaction("Press any key to start battle!");

    bool is_player_turn = player->getAgility() > enemy->getAgility();

    while (player->getHitPoint()>0 && enemy->getHitPoint()>0) {
        if (is_player_turn) {
            battle.PerformBattleAction(player, enemy, battle.GetPlayerTurn());
        } else {
            system("cls");
            std::cout << "[ENEMY TURN]\n\n";
            battle.PerformBattleAction(enemy, player, battle.GetEnemyTurn());
        }
        WaitUserReaction("\nPress any key to continue!");

        system("cls");
        std::cout << "[YOUR TURN]\n";
        std::cout << std::endl << player->getInfo();
        std::cout << std::endl << enemy->getInfo(true) << std::endl;

        if (!is_player_turn)
            battle.battleTickEvent.invoke();

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
    std::cout << std::endl;
    return num;
}

int crpg::BattleProcessor::GetEnemyTurn() {
    return RandomNumber::random(1,3);
}

void crpg::BattleProcessor::Attack(Hero *who, Hero *target) {
    Weapon* who_weapon = who->getWeapon();
    Armor* target_armor = target->getArmor();

    int damage = who_weapon->getDamage();


    if (who_weapon->getDamageType() == DamageTypeEnum::Physical)
    {
        //Reduce physical damage by armor
        switch (target_armor->getArmorType()) {
            case ArmorTypeEnum::Heavy:
                damage = damage * 60 / 100;
                break;
            case ArmorTypeEnum::Medium:
                damage = damage * 80 / 100;
                break;
            case ArmorTypeEnum::Light:
                damage = damage * 90 / 100;
                break;
        }

        //Calculate physical damage by strength
        damage = damage * who->getStrength() * 10 / 100;
    }

    if (who_weapon->getDamageType() == DamageTypeEnum::Magical)
    {
        //Increase magical damage by intellect coefficient
        int k = who->getIntellect() - 10;
        if (k<0) k = 0;
        damage += (damage * k * 10) / 100;
    }

    target->setHitPoint(target->getHitPoint() - damage);
    std::cout << who->getName() << " attacks " << target->getName() << std::endl;
}

void crpg::BattleProcessor::PerformBattleAction(Hero*who, Hero* target, int num) {
    switch (num) {
        case 1: //ATTACK ACTION
            Attack(who, target);
            break;
        case 2: //USE WEAPON ABILITY ACTION
            std::cout << who->getWeapon()->ability() << std::endl;
            break;
        case 3: //USE RACE ABILITY ACTION
            std::cout << who->getRace()->ability() << std::endl;
            break;
        case 4: //USE POTION ACTION
            std::cout << who->usePotion();
            break;
    }
}

void crpg::WaitUserReaction(const string &message) {
    std::cout << message;
    getch();
}
