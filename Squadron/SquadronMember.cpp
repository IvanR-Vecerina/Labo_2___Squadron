//
// Created by Ivan Vecerina on 07/04/2022.
//

#include "SquadronMember.hpp"

SquadronMember::SquadronMember(const Ship &ship) : ship(&ship), next(nullptr) {

}

SquadronMember::SquadronMember(const SquadronMember &squadronMember) : ship(squadronMember.ship), next(squadronMember.next){

}

void SquadronMember::setShip(const Ship &ship) {

}

void SquadronMember::setNext(const SquadronMember &next) {

}

const Ship &SquadronMember::getShip() const {
    return *ship;
}

const SquadronMember &SquadronMember::getNext() const {
    return *next;
}

void SquadronMember::addNext(const Ship &ship) {

}

void SquadronMember::delNext(const Ship &ship) {

}


