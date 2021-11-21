//
// Created by Павел Жуков on 21/11/2021.
//

#include "Aeroflot.h"

Aeroflot::Aeroflot(const std::string &origin, const std::string &destination, const std::string &planeType,
                   const std::string &flightNo) : origin(origin), destination(destination), planeType(planeType),
                                                  flightNo(flightNo) {
    std::cout << "Constructing Aeroflot with params" << std::endl;
}

Aeroflot::Aeroflot(): origin("null"), destination("null"), planeType("null"), flightNo("null") {
    std::cout << "Constructing Aeroflot without params" << std::endl;
}

Aeroflot::~Aeroflot() {
    std::cout << "Destructing Aeroflot" << std::endl;
}

Aeroflot::Aeroflot(Aeroflot &a): origin(a.origin), destination(a.destination), planeType(a.planeType), flightNo(a.flightNo) {
    std::cout << "Copying Aeroflot" << std::endl;
}

const std::string &Aeroflot::getOrigin() const {
    return origin;
}

void Aeroflot::setOrigin(const std::string &origin) {
    Aeroflot::origin = origin;
}

const std::string &Aeroflot::getDestination() const {
    return destination;
}

void Aeroflot::setDestination(const std::string &destination) {
    Aeroflot::destination = destination;
}

const std::string &Aeroflot::getPlaneType() const {
    return planeType;
}

void Aeroflot::setPlaneType(const std::string &planeType) {
    Aeroflot::planeType = planeType;
}

const std::string &Aeroflot::getFlightNo() const {
    return flightNo;
}

void Aeroflot::setFlightNo(const std::string &flightNo) {
    Aeroflot::flightNo = flightNo;
}

std::string Aeroflot::getGraphDesc() {
    std::string tmp;
    tmp = "\"" +
          origin +
          "\"" +
          " -> " +
          "\"" +
          destination +
          "\"" +
          "[label=" +
          "\"" +
          flightNo +
          "|" +
          planeType +
          "\"" +
          "];\n";
    return tmp;
}

std::istream &operator>>(std::istream &in, Aeroflot& right) {
    std::cout << "Type in city of origin. First word will be read: ";
    in >> right.origin;
    in.ignore(32767, '\n');
    std::cout << "Type in destination. First word will be read: ";
    in >> right.destination;
    in.ignore(32767, '\n');
    std::cout << "Type in flightNo. First word will be read: ";
    in >> right.flightNo;
    in.ignore(32767, '\n');
    std::cout << "Type in planeType. First word will be read: ";
    in >> right.planeType;
    in.ignore(32767, '\n');
    return in;
}

std::ostream &operator<<(std::ostream &out, Aeroflot right) {
    out << "Flight No: " << right.getFlightNo() << std::endl
        << "from " << right.getOrigin() << " to " << right.getDestination() << std::endl
        << "Aircraft: " << right.getPlaneType() << std::endl;
    return out;
}

Aeroflot &Aeroflot::operator=(Aeroflot &right) {
    this->destination = right.destination;
    this->planeType = right.planeType;
    this->flightNo = right.flightNo;
    this->origin = right.origin;
    return *this;
}

