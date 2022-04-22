//#########################
//
// Various useful methods
//
//#########################

#ifndef MARO_H
#define MARO_H

#include <iostream>
#include <functional>

using std::cout;
using std::cerr;
using std::cin;

/// <summary>
/// Outputs welcome_msg to the console, handles user input.
/// If the input type does not satisfy T, outputs err_msg and repeats the input.
/// </summary>
template <typename T>
T SafeConsoleInput(const char* welcome_msg = "", const char* err_msg = "", std::function<bool(T&)> expression = [](T& t){ return true; })
{
    T res;
    bool inputIsNotCorrect = false;
    cout << welcome_msg;
    do {
        if (inputIsNotCorrect) //If the input is faulty
        {
            cout << err_msg;
            cin.clear(); //Switching to the "normal" state
            cin.ignore(32767, '\n'); //Clearing the data in the input
            inputIsNotCorrect = false;
        }
        cin >> res;
        inputIsNotCorrect = !cin || (cin && cin.peek() != '\n') || !expression(res);
    } while (inputIsNotCorrect);

    return res;
}

#endif