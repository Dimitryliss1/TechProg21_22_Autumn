//
// Created by Павел Жуков on 21/11/2021.
//

#include <sstream>
#include "useful.h"

int safe_input(){
    int res;
    std::cin >> res;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cout << "Try again: ";
        std::cin.ignore(32767, '\n');

        std::cin >> res;
    }
    return res;
}

std::string to_lower(std::string src){
    for (char & i : src){
        i = tolower(i);
    }
    return src;
}

