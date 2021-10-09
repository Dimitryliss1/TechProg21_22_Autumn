//
// Created by Павел Жуков on 09/10/2021.
//

#include "useful.h"

template<typename T>
T safe_input(std::istream &in){
    T res;
    in >> res;
    while (in.fail()){
        std::cout << "Что-то пошло не так" << std::endl
                  << "Попробуйте еще раз: ";
        in.clear();
        in.ignore(32767, '\n');
        in >> res;
    }
    return res;
}

template<>
std::string safe_input(std::istream &in){
    std::string res;
    getline(in, res);
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
    std::cout << "Статистика по всем чекам: " << std::endl;
    int cnt = 1;
    for (const auto &item: res) {
        std::cout << cnt << "." << std::endl
                  << "Название товара: " << item.first.getProductName() << std::endl
                  << "Цена за единицу товара: " << item.first.getProductPrice() << std::endl
                  << "Всего куплено: " << item.second << " единиц." << std::endl
                  << "На сумму " << item.second * item.first.getProductPrice() << std::endl << std::endl;
    }

}

void printStatsForProduct(std::string name, const std::vector<Product>& available_prods, const std::vector<Receipt>& receipts){
    name = to_lower(name);
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
        throw (NotFoundInListException("No such item in available products"));
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
                  << "На сумму " << res.second * res.first.getProductPrice() << std::endl;
    }

}