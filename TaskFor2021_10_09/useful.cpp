//
// Created by Павел Жуков on 09/10/2021.
//

#include "useful.h"


int safe_input(){
    int res;
    std::cin >> res;
    while (std::cin.fail()) {
        std::cout << "Что-то пошло не так" << std::endl
                  << "Попробуйте еще раз: ";
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cin >> res;
    }
    return res;
}

std::string safe_input_str(){
    std::string res;
//    std::cin.ignore();
    getline(std::cin >> std::ws, res);
    return res;
}

void printStatsForAllReceipts(const std::vector<Receipt>& receipts) {
    std::vector<Counter<Product>> res;
    for (const auto &receipt : receipts) {
        std::vector<Counter<Product>> tmp = receipt.getPurchases();
        for (const auto &item : tmp) {
            bool flag = false;
            for (auto &re : res) {
                if (re.first == item.first) {
                    re.second += item.second;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                res.push_back(item);
            }
        }
    }

    int total;
    if (res.empty()){
        std::cout << "Вы пока не создали ни одного чека, либо все они были пустые\n";
        return;
    }
    std::cout << "Статистика по всем чекам: " << std::endl;
    int cnt = 1;
    for (const auto &item: res) {
        std::cout << cnt << "." << std::endl
                  << "Название товара: " << item.first.getProductName() << std::endl
                  << "Цена за единицу товара: " << item.first.getProductPrice() << std::endl
                  << "Всего куплено: " << item.second << " единиц." << std::endl
                  << "На сумму " << item.second * item.first.getProductPrice() << " у.е." << std::endl;
        cnt++;
    }

}

void printStatsForProduct(std::string name, const std::vector<Product>& available_prods, const std::vector<Receipt>& receipts){
    name = trim(to_lower(name));
    bool flag = false;
    Product found;
    for (auto & available_prod : available_prods){
        if (available_prod.getProductName() == name){
            flag = true;
            found = available_prod;
            break;
        }
    }
    if (!flag) {
        throw (NotFoundInListException("Такого товара нет в списке доступных товаров"));
    }

    Counter<Product> res;
    res.first = found;
    res.second = 0;
    for (const auto &receipt : receipts) {
        std::vector<Counter<Product>> tmp = receipt.getPurchases();
        for (const auto& item : tmp){
            if (item.first == res.first){
                res.second += item.second;
                break;
            }
        }
    }

    if (res.second){
        std::cout << "Товар " << res.first.getProductName() << ":" << std::endl
                  << "Цена за единицу: " << res.first.getProductPrice() << std::endl
                  << "Всего куплено: " << res.second << " шт." << std::endl
                  << "На сумму " << res.second * res.first.getProductPrice() << " у.е." << std::endl;
    } else {
        std::cout << "К сожалению, этот товар еще не фигурировал ни в одном чеке.\n";
    }

}

void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

std::string trim(std::string s){
    ltrim(s);
    rtrim(s);
    return s;
}