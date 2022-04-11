//
// Created by Ivan Vecerina on 17/03/2022.
//

#ifndef LABO_2___SQUADRON_SQUADRON_HPP
#define LABO_2___SQUADRON_SQUADRON_HPP


#include "../Ships/Ship.hpp"
#include "SquadronMember.hpp"

class Squadron;

Squadron operator+ (const Squadron& squadron, const Ship& ship);
Squadron operator- (const Squadron& squadron, const Ship& ship);
std::ostream& operator<<(std::ostream& os, const Squadron& squadron);

class Squadron {
public:
    Squadron();
    Squadron(std::string name);
    Squadron(const Squadron& squadron);
    ~Squadron();



    void setLeader(const Ship& ship);
    void demoteLeader(const Ship& ship);

    Squadron& addShip(const Ship& ship);
    Squadron& removeShip(const Ship& ship);

    Squadron add(const Ship& ship) const;
    Squadron remove(const Ship& ship) const;

    Ship& at(size_t i);
    Ship& operator[](size_t i);
    const Ship& operator[](size_t i) const;
    // TODO: make "squadron[0] = ship" possible

    Squadron& operator+=(const Ship& ship);
    Squadron& operator-=(const Ship& ship);

    unsigned long getMaxVelocity();
    unsigned long getTotalWeight();
    double getFuelConsumption();

private:
    std::string name;
    SquadronMember* firstmember;
    Ship* Leader;

    void allocate();
    void deallocate();
};


#endif //LABO_2___SQUADRON_SQUADRON_HPP
