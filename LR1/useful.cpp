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