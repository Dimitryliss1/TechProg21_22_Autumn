//
// Created by Павел Жуков on 09/10/2021.
//

#include "Receipt.h"

Receipt::~Receipt() = default;

Receipt::Receipt() = default;

void Receipt::printPurchase() {
    std::vector<Counter<Product>>res = getPurchases();
    std::cout << "Список покупок:" << std::endl;
    unsigned int total = 0;
    for(int i = 0; i < res.size(); i++){
        std::cout << i + 1 << "." << std::endl
                  << "Название товара: " << res[i].first.getProductName() << std::endl
                  << "Цена за единицу: " << res[i].first.getProductPrice() << std::endl
                  << "Всего куплено: " << res[i].second << " ед. товара "
                  << "На сумму " << res[i].second * res[i].first.getProductPrice() << std::endl;
        total += res[i].second * res[i].first.getProductPrice();
    }
    std::cout << "Общая стоимость покупки: " << total << " у.е." << std::endl;
}
