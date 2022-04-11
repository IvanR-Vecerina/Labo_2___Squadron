//
// Created by Ivan Vecerina on 07/04/2022.
//

#ifndef LABO_2___SQUADRON_SQUADRONMEMBER_HPP
#define LABO_2___SQUADRON_SQUADRONMEMBER_HPP


#include "../Ships/Ship.hpp"

class SquadronMember {
public:
    SquadronMember(const Ship& ship);
    SquadronMember(const SquadronMember& squadronMember);

    void setShip(const Ship& ship);
    void setNext(const SquadronMember& next);

    const Ship& getShip() const;
    const SquadronMember& getNext() const;

    void addNext(const Ship& ship);
    void delNext(const Ship& ship);

    // SquadronMember &operator=(const Ship& ship); // TODO: check if OK

private:
    const Ship* ship;
    SquadronMember* next;
};


#endif //LABO_2___SQUADRON_SQUADRONMEMBER_HPP
