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
    virtual ~Ship() = default;
/* à compléter */
    virtual std::ostream& toStream(std::ostream& os) const;
    virtual double getWeight() const;

    void setNickname(const std::string& name);

    unsigned int getMaxVelocity() const;
    double getFuelConsumption(unsigned long distance, unsigned long velocity) const;


private:
    std::string nickname;

    const std::string id;
    const unsigned int weight;
    const unsigned int max_velocity;

   Ship& operator=(const Ship&) = delete;
   Ship(const Ship&) = delete;

protected:
   Ship(std::string id, unsigned int weight, unsigned int max_velocity);
};


#endif //LABO_2___SQUADRON_SHIP_HPP
