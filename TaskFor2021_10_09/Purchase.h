//
// Created by Павел Жуков on 09/10/2021.
//

#ifndef TASKFOR2021_10_09_PURCHASE_H
#define TASKFOR2021_10_09_PURCHASE_H

#include <iostream>
#include <vector>

#ifndef TASKFOR2021_10_09_PRODUCT_H
#include "Product.h"
#endif

#ifndef TASKFOR2021_10_09_EXC_H
#include "exc.h"
#endif

template <class T>
struct Counter{
    T first;
    int second;
};


class Purchase {
    std::vector<Counter<Product>> items;
public:
    Purchase();
    virtual ~Purchase();
    const std::vector<Counter<Product>> getPurchases() const;
    void pushUnit(std::string name, int amt, const std::vector<Product>& available_prods);
    void popNUnits(std::string name, int amt, const std::vector<Product>& available_prods);
    void popAllUnitsOfArticle(std::string name, const std::vector<Product>& available_prods);
    virtual void printPurchase() = 0;
};


#endif //TASKFOR2021_10_09_PURCHASE_H
