//
// Created by Павел Жуков on 17/10/2021.
//

#include "CourtCase.h"
#include "useful.h"

CourtCase::CourtCase(): responsible(), criminal(), title("null"), description("null"), unique_monsters_amt(0){
    monsters = (Pair*) calloc(0, sizeof(Pair));
    std::cout << "Empty Case created!" << std::endl;
}

CourtCase::CourtCase(CourtCase &src): responsible(src.getResponsible()),
                                      criminal(src.getCriminal()),
                                      unique_monsters_amt(src.getMonstersAmt()),
                                      title(src.getTitle()),
                                      description(src.getDescription()){
    monsters = (Pair*) calloc(unique_monsters_amt, sizeof(Pair));
    for(int i = 0; i < unique_monsters_amt; i++){
        Pair tmp;
        tmp.first = Monster(src.monsters[i].first);
        tmp.second = src.monsters[i].second;
        monsters[i] = tmp;
    }
    std::cout << "Case copied!" << std::endl;
}

const Hero &CourtCase::getResponsible() const {
    return responsible;
}

void CourtCase::setResponsible(const Hero &responsible) {
    CourtCase::responsible = responsible;
}

const Villain &CourtCase::getCriminal() const {
    return criminal;
}

void CourtCase::setCriminal(const Villain &criminal) {
    CourtCase::criminal = criminal;
}

int CourtCase::getMonstersAmt() const {
    return unique_monsters_amt;
}

const std::string &CourtCase::getTitle() const {
    return title;
}

void CourtCase::setTitle(const std::string &title) {
    CourtCase::title = title;
}

const std::string &CourtCase::getDescription() const {
    return description;
}

void CourtCase::setDescription(const std::string &description) {
    CourtCase::description = description;
}

void CourtCase::addMonster(const Monster &monster) {
    bool flag = true;
    for (int i = 0; i < unique_monsters_amt; i++) {
        if (monsters[i].first == monster) {
            monsters[i].second += 1;
            flag = false;
            break;
        }
    }
    if (flag) {
        monsters = (Pair *) realloc(monsters, ++unique_monsters_amt);
        Pair tmp;
        tmp.first = monster;
        tmp.second = 1;
        monsters[unique_monsters_amt - 1] = tmp;
    }
}

std::string CourtCase::getInfoForFile() {
    std::string tmp;
    tmp += responsible.getInfoForFile() + "\n";
    tmp += criminal.getInfoForFile() + "\n";
    char* a = nullptr;
    sprintf(a, "%d", unique_monsters_amt);
    tmp += std::string(a) + "\n";

    for(int i = 0; i < unique_monsters_amt; i++){
        tmp += monsters[i].first.getInfoForFile() + "\n";
        sprintf(a, "%d", monsters[i].second);
        tmp += std::string(a) + "\n";
    }
    tmp += title + "\n";
    sprintf(a, "%d", get_amt_of_strings(description));
    tmp += std::string(a) + "\n";
    tmp += description + "\n";
    delete a;
    return tmp;
}

void CourtCase::printInfo(std::ostream &out) {
    out << "Case title: " << title << "\n"
        << "Case description: " << description << "\n"
        << "Responsible officer: " << responsible.getName() << "\n"
        << "Suspected criminal: " << criminal.getName() << "\n"
        << "Used monsters: " << "\n";
    for (int i = 0; i < unique_monsters_amt; i++){
        out << i + 1 << ".\n"
            << monsters[i].second << " of " << monsters[i].first.getName() << "\n\n";
    }

}



