#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
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
                    bool flag = false;
                    for(int i = 0; i < flights.getsz(); i++){
                        if (to_lower(flights[i].getPlaneType()) == to_lower(tmp)){
                            std::cout << flights[i];
                            flag = true;
                        }
                    }

                    if (!flag) {
                        std::cout << "No flight matching your query found.\n";
                    }
                }
                if (choice2 == 3){
                    flights.sort(comp);
                    for(int i = 0; i < flights.getsz(); i++){
                        std::cout << flights[i];
                    }
                }
                if (choice2 == 4){
                    std::cout << "Pass id of flight you want to edit.\n"
                                 "Available ids from 0 to " << flights.getsz() - 1<< ":";
                    int id = safe_input();
                    while (id < 0 || id > flights.getsz() - 1){
                        std::cout << "Wrong id. Try again: ";
                        id = safe_input();
                    }
                    std::cout << "Editing flight\n" << flights[id];
                    while(true){
                        std::cout << "Pass the field you want to edit:\n"
                                     "1. origin\n"
                                     "2. destination\n"
                                     "3. planeType\n"
                                     "4. flightNo\n"
                                     "0. Exit\n"
                                     "Your choice: ";
                        int choice3 = safe_input();
                        while (choice3 < 0 || choice3 > 4){
                            std::cout << "Wrong choice. Try again: ";
                            choice3 = safe_input();
                        }
                        if (choice3 == 0) break;
                        if (choice3 == 1){
                            std::string tmpOrigin;
                            std::cout << "Old value: " << flights[id].getOrigin();
                            std::cout << "New value. First word will be read: ";
                            std::cin >> tmpOrigin;
                            std::cin.ignore(32767, '\n');
                            flights[id].setOrigin(tmpOrigin);
                        }
                        if (choice3 == 2){
                            std::string tmpDestination;
                            std::cout << "Old value: " << flights[id].getDestination();
                            std::cout << "New value. First word will be read: ";
                            std::cin >> tmpDestination;
                            std::cin.ignore(32767, '\n');
                            flights[id].setDestination(tmpDestination);
                        }
                        if (choice3 == 3){
                            std::string tmpPlaneType;
                            std::cout << "Old value: " << flights[id].getPlaneType();
                            std::cout << "New value. First word will be read: ";
                            std::cin >> tmpPlaneType;
                            std::cin.ignore(32767, '\n');
                            flights[id].setOrigin(tmpPlaneType);
                        }
                        if (choice3 == 4){
                            std::string tmpFlightNo;
                            std::cout << "Old value: " << flights[id].getFlightNo();
                            std::cout << "New value. First word will be read: ";
                            std::cin >> tmpFlightNo;
                            std::cin.ignore(32767, '\n');
                            flights[id].setOrigin(tmpFlightNo);
                        }
                    }
                }
                if (choice2 == 5){
                    std::cout << "Pass id of flight you want to delete.\n"
                                 "Available ids from 0 to " << flights.getsz() - 1<< ":";
                    int id = safe_input();
                    while (id < 0 || id > flights.getsz() - 1){
                        std::cout << "Wrong id. Try again: ";
                        id = safe_input();
                    }
                    std::cout << "Deleted Flight: " << (flights >> id) << std::endl;
                }
                if (choice2 == 6){
                    std::cout << convertToGRVZ(getGraphDesc(flights));
                }
            }
        }
        if(choice == 2){
            // Предложением считаеся последовательность слов, причем после последнего слова предложения идет точка
            // без разделителя. После точки идет пробел и следующее предложение.
            std::cout << "Type in absolute or relative path to .txt file >> ";
            std::string path;
            std::cin >> path;
            std::ifstream fin(path);
            while (!fin){
                std::cout << "Error occurred during file opening. "
                             "Try again with other file\n"
                             ">> ";
                std::cin >> path;
                fin.open(path);
            }
            std::string sentences[3];
            std::stringstream sent;
            int strcnt = 0;
            while (fin && strcnt != 3){
                std::string a;
                fin >> a;
                sent << a;
                if (a[a.size() - 1] == '.' && a.size() != 1){
                    sentences[strcnt++] = sent.str();
                    sent.str("");
                } else {
                    sent << ' ';
                }
            }
            if (strcnt != 3){
                std::cout << "File does not contain three sentences";
            } else {
                std::cout << "Pass the path to the output file.\n"
                             "The contents of the file will be erased if present.\n"
                             ">> ";
                std::string opath;
                std::cin >> opath;
                std::ofstream fout(opath);
                while (!fout){
                    std::cout << "Error occurred during file opening. "
                                 "Try again with other file\n"
                                 ">> ";
                    std::cin >> opath;
                    fout.open(opath);
                }
                for(int i = 2; i > -1; i--){
                    std::cout << sentences[i] << "\n";
                }
            }

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