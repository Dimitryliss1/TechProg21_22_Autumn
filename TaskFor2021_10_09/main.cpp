#include <iostream>
#include <vector>

#include "useful.h"
#include "Product.h"
#include "Receipt.h"
#include "exc.h"

int main() {
    std::vector<Receipt>receipts;
    std::vector<Product>all_prod;
    system("clear");
    std::cout << "Здравствуйте!\nДля корректной работы магазина необходимо иметь хотя бы продукт.\n";
    while(true){
        std::cout << "Введите название продукта: ";
        std::string name = to_lower(safe_input_str());
        std::cout << "Введите цену за единицу. Она не может быть нулем или отрицательной.\n"
                     "Цена -- целое число, поэтому дробная часть, при введении, будет отсечена\n"
                     "Цена: ";
        int price = safe_input();
        while (price <= 0){
            std::cout << "Цена должна быть строго положительной.\nПопробуйте еще раз: ";
            price = safe_input();
        }
        bool flag = false;
        for (auto & i : all_prod){
            if (i.getProductName() == name && i.getProductPrice() == price){
                std::cout << "Точно такой же продукт Вы добавили ранее.\n";
                flag = true;
                break;
            } else if (i.getProductName() == name){
                std::cout << "Продукт с таким именем, но другой ценой уже есть в списке.\n"
                             "Старая цена: " << i.getProductPrice() << "\n"
                             "Ваша цена: " << price << "\n"
                             "Поменять цену?\n"
                             "0 -- Нет\n"
                             "1 -- Да\n"
                             "Ваш выбор: \n";
                int change_choice = safe_input();
                while (change_choice < 0 || change_choice > 1){
                    std::cout << "Такого действия нет.\nПопробуйте ещё раз: ";
                    change_choice = safe_input();
                }
                if (change_choice == 1){
                    i.setProductPrice(price);
                }
                flag = true;
                break;
            }
        }
        if (!flag) all_prod.push_back(Product(price, name));
        std::cout << "Выберите действие: \n"
                     "0. Перейти в главное меню\n"
                     "1. Продолжить добавлять товары\n"
                     "Ваш выбор: ";
        int choice = safe_input();
        while (choice < 0 || choice > 1){
            std::cout << "Такого действия нет.\nПопробуйте ещё раз: ";
            choice = safe_input();
        }
        if (choice == 0){
            system("clear");
            break;
        }
        else continue;
    }
    Receipt cur;
    while(true){
        std::cout << "Выберите действие:\n"
                     "1. Создать чек.\n"
                     "2. Вывести содержимое последнего чека\n"
                     "3. Вывести статистику по проданным товарам\n"
                     "4. Найти статистику для конкретного товара\n"
                     "5. Добавить товар/ы в список доступных\n"
                     "0. Выход\n"
                     "Ваш выбор: ";
        int choice = safe_input();
        while (choice < 0 || choice > 5){
            std::cout << "Такого действия нет.\nПопробуйте еще раз: ";
            choice = safe_input();
        }
        if (choice == 0) break;
        else if (choice == 1){
            cur = Receipt();
            system("clear");
            while(true){
                std::cout << "Выберите действие:\n"
                             "1. Добавить товар в чек\n"
                             "2. Удалить одну единицу товара из чека\n"
                             "3. Удалить все позиции товара из чека\n"
                             "4. Показать чек\n"
                             "5. Вывести список доступных товаров\n"
                             "0. Закрыть чек и выйти в меню\n"
                             "Ваш выбор: ";
                int rec_choice = safe_input();
                while (rec_choice < 0 || rec_choice > 5){
                    std::cout << "Такого действия нет.\nПопробуйте еще раз: ";
                    rec_choice = safe_input();
                }
                if (rec_choice == 0) break;
                else if (rec_choice == 1){
                    system("clear");
                    while(true) {
                        std::cout << "Введите имя желаемого товара: ";
                        std::string name = safe_input_str();
                        std::cout << "Введите количество товара.\nЭто число обязательно целое и положительное, дробная часть будет отсечена: ";
                        int amt = safe_input();
                        while (amt <= 0) {
                            std::cout
                                    << "Количество товара обязательно целое и положительное, дробная часть будет отсечена.\n"
                                       "Попробуйте еще раз: ";
                            amt = safe_input();
                        }
                        try {
                            cur.pushUnit(name, amt, all_prod);
                        } catch (NotFoundInListException &e) {
                            std::cout << e.what() << std::endl;
                            continue;
                        }
                        std::cout << "Успешно!" << std::endl;
                        break;
                    }
                } else if (rec_choice == 2){
                    system("clear");
                    while(true) {
                        std::cout << "Введите имя удаляемого товара: ";
                        std::string name = safe_input_str();
                        std::cout << "Введите количество товара, которое вы хотите убрать.\nЭто число обязательно целое и положительное, дробная часть будет отсечена: ";
                        int amt = safe_input();
                        while (amt <= 0) {
                            std::cout
                                    << "Количество товара обязательно целое и положительное, дробная часть будет отсечена.\n"
                                       "Попробуйте еще раз: ";
                            amt = safe_input();
                        }
                        try {
                            cur.popNUnits(name, amt, all_prod);
                        } catch (NotFoundInListException &e) {
                            std::cout << e.what() << std::endl;
                            continue;
                        }
                        std::cout << "Успешно!" << std::endl;
                        break;
                    }
                } else if (rec_choice == 3){
                    system("clear");
                    while(true) {
                        std::cout << "Введите имя удаляемого товара: ";
                        std::string name = safe_input_str();
                        try {
                            cur.popAllUnitsOfArticle(name, all_prod);
                        } catch (NotFoundInListException &e) {
                            std::cout << e.what() << std::endl;
                            continue;
                        }
                        std::cout << "Успешно!" << std::endl;
                        break;
                    }
                } else if (rec_choice == 4){
                    system("clear");
                    cur.printPurchase();
                } else if (rec_choice == 5){
                    system("clear");
                    for (auto & i : all_prod){
                        std::cout << i.getProductName() << " " << i.getProductPrice() << std::endl;
                    }
                }
            }
            system("clear");
            if (!cur.isEmpty()) {
                cur.printPurchase();
                receipts.push_back(cur);
                std::cout << "\n";
            } else {
                std::cout << "Чек пустой, он не будет сохранен в истории.\n";
            }
        } else if (choice == 2){
            system("clear");
            if (receipts.empty()){
                std::cout << "Вы еще не создали ни одного чека" << std::endl;
            } else {
                receipts.back().printPurchase();
            }
        } else if (choice == 3){
            system("clear");
            printStatsForAllReceipts(receipts);
        } else if (choice == 4){
            system("clear");
            while(true) {
                std::cout << "Введите имя искомого товара: ";
                std::string name = safe_input_str();
                try {
                    printStatsForProduct(name, all_prod, receipts);
                } catch (NotFoundInListException &e) {
                    std::cout << e.what() << std::endl;
                    continue;
                }
                std::cout << "Успешно!" << std::endl;
                break;
            }
        } else if (choice == 5){
            system("clear");
            while(true){
                std::cout << "Введите название продукта: ";
                std::string name = to_lower(safe_input_str());
                std::cout << "Введите цену за единицу. Она не может быть нулем или отрицательной.\n"
                             "Цена -- целое число, поэтому дробная часть, при введении, будет отсечена\n"
                             "Цена: ";
                int price = safe_input();
                while (price <= 0){
                    std::cout << "Цена должна быть строго положительной.\nПопробуйте еще раз: ";
                    price = safe_input();
                }
                bool flag = false;
                for (auto & i : all_prod){
                    if (i.getProductName() == name && i.getProductPrice() == price){
                        std::cout << "Точно такой же продукт Вы добавили ранее.\n";
                        flag = true;
                        break;
                    } else if (i.getProductName() == name){
                        std::cout << "Продукт с таким именем, но другой ценой уже есть в списке.\n"
                                     "Старая цена: " << i.getProductPrice() << "\n"
                                     "Ваша цена: " << price << "\n"
                                     "Поменять цену?\n"
                                     "0 -- Нет\n"
                                     "1 -- Да\n"
                                     "Ваш выбор: \n";
                        int change_choice = safe_input();
                        while (change_choice < 0 || change_choice > 1){
                            std::cout << "Такого действия нет.\nПопробуйте ещё раз: ";
                            change_choice = safe_input();
                        }
                        if (change_choice == 1){
                            i.setProductPrice(price);
                        }
                        flag = true;
                        break;
                    }
                }
                if (!flag) all_prod.push_back(Product(price, name));
                std::cout << "Выберите действие: \n"
                             "0. Перейти в главное меню\n"
                             "1. Продолжить добавлять товары\n"
                             "Ваш выбор: ";
                int continue_choice = safe_input();
                while (continue_choice < 0 || continue_choice > 1){
                    std::cout << "Такого действия нет.\nПопробуйте ещё раз: ";
                    continue_choice = safe_input();
                }
                if (continue_choice == 0){
                    system("clear");
                    break;
                }
                else continue;
            }
        }
    }
}
