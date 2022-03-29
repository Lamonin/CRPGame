#include <iostream>
#include <algorithm>
#include "engine.h"
#include "crpgdata.h"
#include "bilist.h"

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

    vector<int> v;
    auto it = v.begin();
    --it;

/*
    bilist<int> list;
    list.begin()--;
    list.end()++;
    list.push_back(2);
    list.push_back(3);
    list.push_back(9);
    list.push_back(1);
    list.pop_front();
    list.pop_front();
    list.push_back(3);
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
    cout << endl << "HULAHOP  " << list.size() << endl;
    reverse(list.begin(), list.end());
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.write_list();
    auto t = list.begin();
    advance(t, 3);
    cout << endl << "GGG  " << *t << endl;

    list.push_back(2);
    reverse(list.begin(), list.end());
    list.push_back(3);
    list.push_back(9);
    list.push_back(1);
    cout << endl;
    for (int & l : list)
    {
        cout << l << " elem" << endl;
    }

    //std::sort(list.begin(), list.end());

    cout << endl;

    list.pop_front();
    cout << endl;
    cout << endl;
    list.write_list();
    cout << endl;

    cout<< list.size() << endl;
    cout<<endl;*/

    //cout << list[5] << endl;

//    char h; std::cin>>h;
    return 0;
}
