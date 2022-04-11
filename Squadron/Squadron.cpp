//
// Created by Ivan Vecerina on 17/03/2022.
//

#include "Squadron.hpp"

Squadron::Squadron() {
   first = nullptr;
}

Squadron::Squadron(std::string name) {

}

Squadron::Squadron(const Squadron &squadron) {

}

Squadron::~Squadron() {

}

void Squadron::setLeader(const Ship &ship) {
   addShip(ship); //in case it wasn't included
}

void Squadron::demoteLeader(const Ship &ship) {
   if( leader == ship) ship = nullptr;
}

Squadron& Squadron::addShip(Ship &ship) {
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
