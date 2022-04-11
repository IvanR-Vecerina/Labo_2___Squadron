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
    virtual ~Ship();
/* à compléter */
    virtual std::ostream& toStream(std::ostream& os) const;
    virtual double getWeight();

    void setNickname(const std::string& nickname);

    unsigned int getMaxVelocity();


private:
    std::string nickname;

    const std::string id;
    const unsigned int weight;
    const unsigned int max_velocity;

   Ship& operator=(const Ship&) = delete;
   Ship(const Ship&) = delete;

protected:
   Ship(std::string i_id, ...);
    Ship();
};


#endif //LABO_2___SQUADRON_SHIP_HPP
