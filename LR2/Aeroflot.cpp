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
          "\n" +
          planeType +
          "\"" +
          "];";
    return tmp;
}

