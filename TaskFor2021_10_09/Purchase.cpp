//
// Created by Павел Жуков on 09/10/2021.
//

#include "Purchase.h"

Purchase::Purchase() = default;

const std::vector<Counter<Product>> Purchase::getPurchases() const {
    return items;
}

void Purchase::pushUnit(std::string name, int amt, const std::vector<Product>& available_prods) {
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
        throw(NotFoundInListException("Такого товара нет в списке доступных продуктов"));
    }
    for (auto & item: items){
        if (item.first == found){
            item.second += amt;
            return;
        }
    }
    Counter<Product>tmp;
    tmp.first = found;
    tmp.second = amt;
    items.push_back(tmp);
}

void Purchase::popNUnits(std::string name, int amt, const std::vector<Product>& available_prods) {
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
        throw(NotFoundInListException("Такого товара нет в списке доступных продуктов"));
    }
    int cnt = 0;
    for (auto & item: items){
        if (item.first == found){
            if (amt < item.second){
                item.second -= amt;
            } else {
                items.erase(items.begin() + cnt);
            }
            return;
        }
        cnt++;
    }
    throw(NotFoundInListException("Такого товара нет в чеке"));
}

void Purchase::popAllUnitsOfArticle(std::string name, const std::vector<Product>& available_prods) {
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
        throw(NotFoundInListException("Такого товара нет в списке доступных"));
    }
    int cnt = 0;
    for (auto & item: items){
        if (item.first == found){
            items.erase(items.begin() + cnt);
            return;
        }
        cnt++;
    }
}

Purchase::~Purchase() {}

int getTotalSum(Purchase* purchase) {
    std::vector<Counter<Product>>tmp = purchase->getPurchases();
    int total = 0;
    for(auto & i : tmp){
        total += i.first.getProductPrice() * i.second;
    }
    return total;
}


