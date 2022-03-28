#include <iostream>
#include "engine.h"
#include "crpgdata.h"
#include "doublelist.h"

int main() {
    system("chcp 65001"); //Отображение кирилицы
    system("cls");
    Data::DataHandler d;
    d.OpenFile("data/user_data.json");

    std::string name1;
    d.GetValue("/name", name1);
    std::string ageS;
    d.GetValue("/goblin/name", ageS);

    std::cout << name1 << " ";
    std::cout << ageS << std::endl << std::endl;

    doublelist<int> list;
    list.push_back(0);
    list.push_back(0);
    list.compare();
    list.write_list();
    list.clear();
    list.write_list();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.write_list();
    cout << endl;

    cout<< list.get_size() << endl;
    cout<<endl;

    //cout << list[5] << endl;

//    char h; std::cin>>h;
    return 0;
}
