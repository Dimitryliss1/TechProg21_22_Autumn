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
    while (std::cin.fail()){
        std::cout << "Try again!" << std::endl;
        std::cin.ignore(32767, '\n');
        std::cin >> res;
    }
    return res;
}

std::string* to_lower(std::string input){
    std::string* res = new std::string();
    for (char i : input){
        res += tolower(i);
    }
    return res;
}