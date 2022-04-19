#include <iostream>
#include "engine.h"
#include "game/heroes.h"
#include "crpgdata.h"
#include "bilist.h"

using namespace crpg;

int main() {
    system("chcp 65001"); //Отображение кирилицы

    RandomHeroBuilder rHeroBuilder;

    Hero* hero1 = rHeroBuilder.build();
    cout << hero1->getInfo();

    Hero* hero2 = rHeroBuilder.build();
    cout << hero2->getInfo();

    Hero* hero3 = rHeroBuilder.build();
    cout << hero3->getInfo();

    return 0;
}
