//
// Created by Павел Жуков on 13/11/2021.
//

#ifndef TASKFOR2021_11_06_SETOFSTACKS_H
#define TASKFOR2021_11_06_SETOFSTACKS_H

#include <iostream>
#include <stack>
#include <vector>

template <typename T>
class SetOfStacks {
    std::vector<std::stack<T>>stacks;
    int limit;
public:
    SetOfStacks();
    SetOfStacks(int limit);
    void push(T val);
    T pop();
    void print();
};



#endif //TASKFOR2021_11_06_SETOFSTACKS_H
