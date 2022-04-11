//
// Created by Ivan Vecerina on 17/03/2022.
//

#ifndef LABO_2___SQUADRON_SHIP_HPP
#define LABO_2___SQUADRON_SHIP_HPP

#include <ostream>

class Ship;

std::ostream& operator<< (std::ostream& os, const Ship& ship);

class Ship
{
public:
    Ship& operator=(const Ship&) = delete;

    virtual ~Ship();
/* à compléter */
    virtual std::ostream& toStream(std::ostream& os) const;

    void setNickname(std::string nickname);

    double getWeight();
    unsigned int getMaxVelocity();


private:
    std::string nickname;

    const std::string id;
    const unsigned int weight;
    const unsigned int max_velocity;


protected:
    Ship();
};


#endif //LABO_2___SQUADRON_SHIP_HPP
