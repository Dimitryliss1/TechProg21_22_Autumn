//
// Created by Павел Жуков on 17/10/2021.
//

#include "useful.h"

int get_amt_of_strings(std::string& a){
    int cnt = 0;
    for(auto& i: a){
        if(i == '\n'){
            cnt++;
        }
    }
    return cnt;
}

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