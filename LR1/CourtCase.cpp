//
// Created by Павел Жуков on 17/10/2021.
//

#include "CourtCase.h"
#include "useful.h"
#include "exc.h"

CourtCase::CourtCase(): responsible(), criminal(), title("null"), description("null"), unique_monsters_amt(0){
    monsters = (Pair**) calloc(0, sizeof(Pair));
    std::cout << "Empty Case created!" << std::endl;
}

CourtCase::CourtCase(CourtCase &src): responsible(src.getResponsible()),
                                      criminal(src.getCriminal()),
                                      unique_monsters_amt(src.getMonstersAmt()),
                                      title(src.getTitle()),
                                      description(src.getDescription()){
    monsters = (Pair**) calloc(unique_monsters_amt, sizeof(Pair));
    for(int i = 0; i < unique_monsters_amt; i++){
        Pair* tmp = new Pair;
        tmp->first = Monster(src.monsters[i]->first);
        tmp->second = src.monsters[i]->second;
        monsters[i] = tmp;
    }
    std::cout << "Case copied!" << std::endl;
}

const Hero &CourtCase::getResponsible() const {
    return responsible;
}

void CourtCase::setResponsible(const Hero &responsible) {
    CourtCase::responsible = Hero(responsible);
}

const Villain &CourtCase::getCriminal() const {
    return criminal;
}

void CourtCase::setCriminal(const Villain &criminal) {
    CourtCase::criminal = Villain(criminal);
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
        if (monsters[i]->first == monster) {
            monsters[i]->second += 1;
            flag = false;
            break;
        }
    }
    if (flag) {
        monsters = (Pair **) realloc(monsters, ++unique_monsters_amt);
        Pair* tmp = new Pair;
        tmp->first = Monster(monster);
        tmp->second = 1;
        monsters[unique_monsters_amt - 1] = tmp;
    }
}

std::string CourtCase::getInfoForFile() {
    std::string tmp;
    tmp += responsible.getInfoForFile();
    tmp += criminal.getInfoForFile();

    tmp += std::to_string(unique_monsters_amt) + "\n";

    for(int i = 0; i < unique_monsters_amt; i++){
        tmp += monsters[i]->first.getInfoForFile();
        tmp += std::to_string(monsters[i]->second) + "\n";
    }
    tmp += title + "\n";
    tmp += std::to_string(get_amt_of_strings(description)) + "\n";
    tmp += description;
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
            << monsters[i]->second << " of " << monsters[i]->first.getName() << "\n\n";
    }

}

CourtCase::~CourtCase() {
    free(monsters);
    std::cout << "Case destroyed!";
}

std::istream &operator>>(std::istream &in, CourtCase *a) {
    try {
        in >> &(a->responsible);
    } catch (FormatException& b){
        throw b;
    }

    try {
        in >> &(a->criminal);
    } catch (FormatException& b){
        throw b;
    }

    int n_monsters;
    in >> n_monsters;
    if (in.fail()){
        throw FormatException("Error reading file");
    }
    if (n_monsters > 0) in.ignore();
    for (int i = 0; i < n_monsters; i++){
        Monster* tmp = new Monster();
        try {
            in >> tmp;
        } catch (FormatException& b){
            throw b;
        }
        int n;
        in >> n;
        in.ignore();
        for (int k = 0; k < n; k++) a->addMonster(*tmp);
    }

    std::getline(in >> std::ws, a->title);
    if (!in) throw FormatException("Error reading file");

    int ab_length;
    in >> ab_length;

    if (in.fail()){
        throw FormatException("Error reading file");
    }
    if (ab_length > 0) in.ignore();
    a->description = "";
    for(int i = 0; i < ab_length; i++){
        std::string tmp;
        std::getline(in, tmp);
        if (!in) throw FormatException("Error reading file");
        a->description += tmp + '\n';
    }
    return in;
}




