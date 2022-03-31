#include <iostream>
#include <algorithm>
#include "engine.h"
#include "crpgdata.h"
#include "bilist.h"

int main() {
    system("chcp 65001"); //Отображение кирилицы
    system("cls");

    //INITIALIZER_LIST's
    bilist<int> list = {0,0,1,2};
    list.cout_list();
    list.push_back({3,4,5,6,7});
    list.cout_list();

    //PUSH_BACK
    list.push_back(8);
    list.push_back(9);
    list.push_back(0);
    list.push_back(0);

    list.cout_list();

    //POP_FRONT
    list.pop_front();
    list.pop_front();

    list.cout_list();

    //POP_BACK
    list.pop_back();
    list.pop_back();

    list.cout_list();

    //ITERATOR_MAGIC
    cout << "\nREVERSE: ";
    std::reverse(list.begin(), list.end());
    for (auto l : list)
        cout << l << " ";

    cout << "\nREVERSE AGAIN: ";
    std::reverse(list.begin(), list.end());
    for (auto it = list.begin(); it != list.end(); it++)
        cout << *it << " ";

    //ACCESS BY INDEX
    cout << endl;
    cout << list[0] << endl;
    cout << list[list.size()-1] << endl;

    //REMOVE BY INDEX
    cout << endl;
    list.removeAt(3);
    list.removeAt(4);
    list.removeAt(list.size()-1);
    list.cout_list();

    //CLEAR
    list.clear();
    cout << "\nCLEAR LIST";
    list.cout_list();

    return 0;
}
