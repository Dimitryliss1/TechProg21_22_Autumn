//
// Created by Павел Жуков on 13/11/2021.
//

#include "SetOfStacks.h"
template<typename T>
SetOfStacks<T>::SetOfStacks(): limit(100) {}

template<typename T>
SetOfStacks<T>::SetOfStacks(int limit): limit(limit) {}

template<typename T>
void SetOfStacks<T>::push(T val) {
    if (stacks.size() == 0 || stacks[stacks.size()-1].size() == limit){
        stacks.push_back(std::stack<T>());
    }
    stacks[stacks.size() - 1].push(val);
}

template<typename T>
T SetOfStacks<T>::pop() {
    if (stacks.size() == 0){ throw std::bad_function_call(); }
    T res = stacks[stacks.size() - 1].top();
    stacks[stacks.size() - 1].pop();
    if (stacks[stacks.size() - 1].size() == 0){
        stacks.pop_back();
    }
    return res;
}

