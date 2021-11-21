#include <iostream>
#include <sstream>
#include <iomanip>
#include "Aeroflot.h"
#include "MyArr.h"

std::string getGraphDesc(MyArr<Aeroflot>&);
std::string convertToGRVZ(const std::string& in);
bool comp(Aeroflot& a, Aeroflot& b);

int main() {
    auto flights = MyArr<Aeroflot>(0);
    while(true){
        std::cout << "Choose lab:\n"
                     "1. Standard streams\n"
                     "2. File and string streams\n"
                     "0. Quit\n"
                     "Your choice: ";
        int choice = safe_input();
        while (choice < 0 || choice > 2) {
            std::cout << "Wrong choice. Try again: ";
            choice = safe_input();
        }
        if(choice == 0) break;
        if(choice == 1) {
            while(true){
                std::cout << "Choose task:\n"
                             "1. Add flight\n"
                             "2. Find flights for that aircraft\n"
                             "3. Print all flights sorted by destination\n"
                             "4. Edit flight\n"
                             "5. Delete flight\n"
                             "6. Get link to graph representation of flight network\n"
                             "0. Return to main menu\n"
                             "Your choice: ";
                int choice2 = safe_input();
                while (choice2 < 0 || choice2 > 6) {
                    std::cout << "Wrong choice. Try again: ";
                    choice2 = safe_input();
                }
                if (choice2 == 0) break;
                if (choice2 == 1){
                    std::cout << "Let's create new flight!" << std::endl;
                    Aeroflot tmp;
                    std::cin >> tmp;
                    flights << tmp;
                }
                if (choice2 == 2){
                    std::cout << "Type in aircraft type. First word will be read: ";
                    std::string tmp;
                    std::cin >> tmp;
                    std::cin.ignore(32767, '\n');
                    MyArr<Aeroflot>res2;
                    for(int i = 0; i < flights.getsz(); i++){
                        if (to_lower(flights[i].getPlaneType()) == to_lower(tmp)){
                            std::cout << flights[i];
                        }
                    }
                    res2.sort(comp);
                    for(int i = 0; i < res2.getsz(); i++){
                        std::cout << res2[i];
                    }
                }
                if (choice2 == 3){
                    flights.sort(comp);
                    for(int i = 0; i < flights.getsz(); i++){
                        std::cout << flights[i];
                    }
                }
                if (choice2 == 4){}
                if (choice2 == 5){}
                if (choice2 == 6){
                    std::cout << convertToGRVZ(getGraphDesc(flights));
                }
            }
        }
        if(choice == 2){

            //TODO:this part
        }
    }
}


std::string getGraphDesc(MyArr<Aeroflot>& arr){
    std::string a;
    a = "digraph G {\n";
    for(int i = 0; i < arr.getsz(); i++){
        a += arr[i].getGraphDesc();
    }
    a += "}\n";
    return a;
}

std::string convertToGRVZ(const std::string& in){
    std::stringstream stream;
    stream << "https://dreampuf.github.io/GraphvizOnline/#";
    for(char i : in){
        stream << "%";
        stream << std::setfill ('0') << std::setw(sizeof(char)*2)  << std::hex << (int) i;
    }
    stream << "\n";
    return stream.str();
}

bool comp(Aeroflot& a, Aeroflot& b){
    return a.getDestination() < b.getDestination();
}