
#include <iostream>
#include "engine.h"
#include "game/heroes.h"
#include "crpgdata.h"
#include "game/character_editor.h"
#include "bilist.h"

using namespace crpg;

int main() {
    system("chcp 65001"); //Отображение кирилицы

    std::cout << "Добро пожаловать на CRPG ARENA!\n\n";
    std::cout << "Создайте себе персонажа:";

    HeroEditor heroEditor{};
    auto h = heroEditor.build();

    cout << endl << h->getInfo() << endl;

    return 0;
}
