#include <iostream>
#include <set>
#include "SetOfStacks.cpp"

std::set<char> construct(std::string s){ //Представление строки в виде сета
    std::set<char> res;
    for (char i : s){
        res.insert(i);
    }
    return res;
}

int getMostOnesLength(std::string s){
    int res = !s.empty() ? 1 : 0; // Очевидно, что если строка не пустая, то минимальная длина -- 1
    int prev_len = 0; // Инициализация переменных
    int dist = 0;
    bool flag = false;
    int cur_len = 0;
    if (construct(s) == construct("1")) return s.size(); // Если строка состоит из одних единиц, то ответ -- длина строки

    for (char i: s){ // Поэлементный проход по строке
        if (i == '0'){
            dist += 1; // Расстояние от предыдущей последовательности единиц увеличивается на один
            if (flag){ // Если только закончили последовательность единиц
                prev_len = cur_len;
                cur_len = 0;
                flag = false;
                dist = 1;
            }
        } else if (i == '1'){
            cur_len++;
            if (!flag){
                flag = true;
            }
        }
        int corr = (dist == 1 || prev_len == 0) ? 1 : 0; // Прибавка, если расстояние равно единице или блок единиц -- первый
        if (dist == 1) res = std::max(res, prev_len + corr + cur_len);
        else res = std::max(res, cur_len + 1);
    }
    return res; // Один проход по строке -- следовательно асимптотика O(n);
}

std::string convertToBin(long long num){ // Школьный алгоритм с делением в столбик числа на 2 и проходом от конца к началу
    if (num == 0) return "0";
    std::string res;
    bool sign = num < 0;
    while (num != 0){
        res = (num % 2  == 0 ? "0" : "1") + res;
        num /= 2;
    }
    return res;

}

template<typename T>
void stckmnu(T param){
    std::cout << "Type in size of stack. If it's wrong, then the standard limit of 100 will be applied: ";
    int size;
    SetOfStacks<T>*a;
    std::cin >> size;
    std::cin.ignore(32767, '\n');
    if (std::cin.fail()){
        a = new SetOfStacks<T>();
    } else {
        a = new SetOfStacks<T>(size);
    }
    while (true){
        a->print();
        std::cout << "Choose task:\n"
                     "1. Push value.\n"
                     "2. Pop value.\n"
                     "0. Quit.\n"
                     "Your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(32767, '\n');
        while (std::cin.fail() || choice < 0 || choice > 2) {
            std::cin.clear();
            std::cout << "Try again: ";
            std::cin.ignore(32767, '\n');
            std::cin >> choice;
        }
        if (choice == 0) break;
        if (choice == 1) {
            T val;
            if (typeid(T) == typeid(std::string)){
                std::cout << "Only the first word is accepted" << std::endl;
            }
            if (typeid(T) == typeid(char)){
                std::cout << "Only the first non-whitespace symbol is accepted" << std::endl;
            }
            std::cout << "Input value: ";
            std::cin >> val;
            std::cin.ignore(32767, '\n');
            while (std::cin.fail()) {
                std::cin.clear();
                std::cout << "Try again: ";
                std::cin.ignore(32767, '\n');
                std::cin >> val;
            }
            a->push(val);
        } else {
            try {
                T res = a->pop();
                std::cout << "Result: " << res << std::endl;
            } catch (std::bad_function_call&){
                std::cout << "Stack is empty" << std::endl;
            }
        }
    }
    delete a;
}

int main(){
    while (true) {
        int choice;
        std::cout << "Choose task:\n"
                     "1. Find length of longest subsequence of ones.\n"
                     "2. Work with SetOfStacks.\n"
                     "0. Quit.\n"
                     "Your choice: ";
        std::cin >> choice;
        std::cin.ignore(32767, '\n');
        while (std::cin.fail() || choice < 0 || choice > 2) {
            std::cin.clear();
            std::cout << "Try again: ";
            std::cin.ignore(32767, '\n');

            std::cin >> choice;
        }
        if (choice == 0) return 0;
        if (choice == 1) {
            unsigned long long num;
            std::cout << "Input the number. It must be non-negative: ";
            std::cin >> num;
            std::cin.ignore(32767, '\n');
            while (std::cin.fail()) {
                std::cin.clear();
                std::cout << "Try again: ";
                std::cin.ignore(32767, '\n');
                std::cin >> num;
            }
            std::cout << "Binary representation: " << convertToBin(num) << std::endl
                      << "Answer: " << getMostOnesLength(convertToBin(num)) << std::endl;
        }
        if (choice == 2) {
            std::cout << "Choose type of stack:\n"
                         "1. long long\n"
                         "2. char\n"
                         "3. string\n"
                         "4. bool\n"
                         "Your choice: ";
            int num;
            std::cin >> num;
            std::cin.ignore(32767, '\n');
            while (std::cin.fail() || num < 1 || num > 4) {
                std::cin.clear();
                std::cout << "Try again: ";
                std::cin.ignore(32767, '\n');
                std::cin >> num;
            }
            if (num == 1) {
                stckmnu((long long) 1);
            } else if (num == 2) {
                stckmnu('a');
            } else if (num == 3) {
                stckmnu(std::string("asef"));
            } else if (num == 4) {
                stckmnu(true);
            }
        }
    }
}
