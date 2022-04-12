#include <iostream>
#include "engine.h"
#include "crpgdata.h"
#include "bilist.h"

int main() {
    system("chcp 65001"); //Отображение кирилицы
    system("cls");

    crpg::HeroBuilder builder;

    builder.setRace(new crpg::Orc());
    auto h = builder.getHero();

    cout << h.getRace()->name << endl << endl;

    builder.setRace(new crpg::Elf());
    cout << h.getRace()->name << endl;

    return 0;
}
