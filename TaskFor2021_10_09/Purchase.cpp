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
        throw(NotFoundInListException("No such item in available products"));
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
        throw(NotFoundInListException("No such item in available products"));
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
    throw(NotFoundInListException("No such item in current receipt"));
}

void Purchase::popAllUnitsOfArticle(std::string name, std::vector<Product> available_prods) {
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
        throw(NotFoundInListException("No such item in available products"));
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


