//
// Created by Павел Жуков on 21/11/2021.
//

#ifndef LR2_AEROFLOT_H
#define LR2_AEROFLOT_H

#include <iostream>

class Aeroflot {
    std::string origin;
    std::string destination;
    std::string planeType;
    std::string flightNo;
public:
    Aeroflot(const std::string &origin, const std::string &destination, const std::string &planeType,
             const std::string &flightNo);
    Aeroflot();
    Aeroflot(Aeroflot& a);
    const std::string &getOrigin() const;
    void setOrigin(const std::string &origin);
    const std::string &getDestination() const;
    void setDestination(const std::string &destination);
    const std::string &getPlaneType() const;
    void setPlaneType(const std::string &planeType);
    const std::string &getFlightNo() const;
    void setFlightNo(const std::string &flightNo);
    std::string getGraphDesc();
    ~Aeroflot();
};


#endif //LR2_AEROFLOT_H
