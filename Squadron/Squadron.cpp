//
// Created by Ivan Vecerina on 17/03/2022.
//

#include "Squadron.hpp"


Squadron::Squadron(const std::string &name) : name(name), leader(nullptr), first(nullptr) {}

Squadron::Squadron(const Squadron &squadron) : name(squadron.name), leader(nullptr), first(nullptr) {
    for (Member* tmp = squadron.first; tmp != nullptr; tmp = tmp->next)
        addShip(*tmp->ship);
}

Squadron::~Squadron() {
    while (first != nullptr)
        removeShip(*first->ship);
}

void Squadron::setLeader(Ship& ship) {
   addShip(ship); //in case it wasn't included
   leader = &ship;
}

void Squadron::demoteLeader(const Ship &ship) {
   if( leader == &ship)
       leader = nullptr;
}

Squadron& Squadron::addShip(const Ship &ship) {
   Member*& prev = findPredecessor(ship);
   if( prev==nullptr ) // if not null, ship is already in the list
      prev = new Member( nullptr, &ship );
   return *this;
}

Squadron& Squadron::removeShip(const Ship &ship) {
   Member*& prev = findPredecessor(ship);
   Member* next = prev->next;
   delete prev;
   prev = next;
   return *this;
}

Squadron Squadron::add(const Ship &ship) const {
    return Squadron(name).addShip(ship);
}

Squadron Squadron::remove(const Ship &ship) const {
    return Squadron(name).removeShip(ship);
}

Squadron &Squadron::operator+=(const Ship &ship) {
    return addShip(ship);
}

Squadron &Squadron::operator-=(const Ship &ship) {
    return removeShip(ship);
}

Squadron operator+ (const Squadron& squadron, const Ship& ship) {
    return squadron.add(ship);
}

Squadron operator- (const Squadron& squadron, const Ship& ship) {
    return squadron.remove(ship);
}

Squadron::Member** Squadron::findPredecessor(const Ship& ship)  {
    for( Member** scan = &first ;  ; scan = &((*scan)->next) )
        if( *scan==nullptr or  (*scan)->ship == &ship )
            return scan;
}


Squadron::Member* Squadron::findIth(int i)
{
    Member* scan=first;
    while( i-- && scan!=nullptr )
         scan = scan->next;
    return scan;
}
