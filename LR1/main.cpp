#include <iostream>
#include "Keeper.h"
#include "useful.h"
#include "exc.h"


int main() {
    Keeper* keeper = Keeper::getInstance();
    while(true){
        std::cout << "Choose class group:\n"
                     "1. Hero\n"
                     "2. Villain\n"
                     "3. Monster\n"
                     "4. Case\n"
                     "5. Dump Keeper to file\n"
                     "6. Read Keeper from file\n"
                     "0. Quit\n"
                     "Your choice: ";
        int choice = safe_input();
        while (choice < 0 || choice > 6){
            std::cout << "No such choice!\n"
                         "Try again: ";
            choice = safe_input();
        }
        if (choice == 0){
            break;
        } else if (choice == 1){
            while(true){
                std::cout << "Choose action:\n"
                             "1. Create new Hero\n"
                             "2. Edit Hero\n"
                             "3. Delete Hero\n"
                             "4. Print full stats of Hero\n"
                             "5. Print all Heroes\n"
                             "0. Return\n"
                             "Your choice: ";
                int ic = safe_input();
                while (ic < 0 || ic > 5){
                    std::cout << "No such choice.\n"
                                 "Try again: ";
                    ic = safe_input();
                }
                if (ic == 0){
                    break;
                } else if (ic == 1){
                    keeper->CreateOfficer();
                } else if (ic == 2){
                    keeper->EditOfficer();
                } else if (ic == 3){
                    keeper->DeleteOfficer();
                } else if (ic == 4){
                    keeper->PrintOfficer();
                } else if (ic == 5){
                    try{
                        keeper->PrintAvailableOfficers();
                    } catch (EmptyListException& a) {
                        std::cout << a.what() << std::endl;
                    }
                }
            }
        } else if (choice == 2){
            while(true){
                std::cout << "Choose action:\n"
                             "1. Create new Villain\n"
                             "2. Edit Villain\n"
                             "3. Delete Villain\n"
                             "4. Print full stats of Villain\n"
                             "5. Print all Villains\n"
                             "0. Return\n"
                             "Your choice: ";
                int ic = safe_input();
                while (ic < 0 || ic > 5){
                    std::cout << "No such choice.\n"
                                 "Try again: ";
                    ic = safe_input();
                }
                if (ic == 0){
                    break;
                } else if (ic == 1){
                    keeper->CreateVillain();
                } else if (ic == 2){
                    keeper->EditVillain();
                } else if (ic == 3){
                    keeper->DeleteVillain();
                } else if (ic == 4){
                    keeper->PrintVillain();
                } else if (ic == 5){
                    try{
                        keeper->PrintAvailableVillains();
                    } catch (EmptyListException& a) {
                        std::cout << a.what() << std::endl;
                    }
                }
            }
        } else if (choice == 3){
            while(true){
                std::cout << "Choose action:\n"
                             "1. Create new Monster\n"
                             "2. Edit Monster\n"
                             "3. Delete Monster\n"
                             "4. Print full stats of Monster\n"
                             "5. Print all Monster\n"
                             "0. Return\n"
                             "Your choice: ";
                int ic = safe_input();
                while (ic < 0 || ic > 5){
                    std::cout << "No such choice.\n"
                                 "Try again: ";
                    ic = safe_input();
                }
                if (ic == 0){
                    break;
                } else if (ic == 1){
                    keeper->CreateMonster();
                } else if (ic == 2){
                    keeper->EditMonster();
                } else if (ic == 3){
                    keeper->DeleteMonster();
                } else if (ic == 4){
                    keeper->PrintMonster();
                } else if (ic == 5){
                    try{
                        keeper->PrintAvailableMonsters();
                    } catch (EmptyListException& a) {
                        std::cout << a.what() << std::endl;
                    }
                }
            }
        } else if (choice == 4){
            while(true){
                std::cout << "Choose action:\n"
                             "1. Create new Case\n"
                             "2. Edit Case\n"
                             "3. Delete Case\n"
                             "4. Print full stats of Case\n"
                             "5. Print all Case\n"
                             "0. Return\n"
                             "Your choice: ";
                int ic = safe_input();
                while (ic < 0 || ic > 5){
                    std::cout << "No such choice.\n"
                                 "Try again: ";
                    ic = safe_input();
                }
                if (ic == 0){
                    break;
                } else if (ic == 1){
                    keeper->CreateCase();
                } else if (ic == 2){
                    keeper->EditCase();
                } else if (ic == 3){
                    keeper->DeleteCase();
                } else if (ic == 4){
                    keeper->PrintCase();
                } else if (ic == 5){
                    try{
                        keeper->PrintAvailableCases();
                    } catch (EmptyListException& a) {
                        std::cout << a.what() << std::endl;
                    }
                }
            }
        } else if (choice == 5){
            std::string tmp = keeper->getStringForFile();
            std::cout << tmp << std::endl;
        }
    }
    return 0;
}
