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

std::string Squadron::getName() const {
   return name;
}

Ship & Squadron::getLeader() const {
   return *leader;
}

Squadron& Squadron::setLeader(Ship& ship) {
   addShip(ship); //in case it wasn't included
   leader = &ship;

   return *this;
}

Squadron& Squadron::demoteLeader(const Ship &ship) {
   if( leader == &ship)
       leader = nullptr;

   return *this;
}

Squadron& Squadron::addShip(Ship& ship) {
   Member*& prev = findPredecessor(ship);

   if( prev == nullptr ) // if not null, ship is already in the list
      prev = new Member( nullptr, &ship );

   return *this;
}

Squadron& Squadron::removeShip(const Ship& ship) {

   Member*& prev = findPredecessor(ship);
   Member* next = prev->next;

   delete prev;

   prev = next;

   return *this;
}

Squadron Squadron::add(Ship& ship) const {
    return Squadron(*this).addShip(ship);
}

Squadron Squadron::remove(const Ship &ship) const {
    return Squadron(*this).removeShip(ship);
}

Squadron &Squadron::operator+=(Ship& ship) {
    return addShip(ship);
}

Squadron &Squadron::operator-=(const Ship& ship) {
    return removeShip(ship);
}

Squadron operator+ (const Squadron& squadron, Ship& ship) {
    return squadron.add(ship);
}

Squadron operator- (const Squadron& squadron, const Ship& ship) {
    return squadron.remove(ship);
}

const Ship& Squadron::at(size_t i) const {
   Member* ith = findIth(i);

   if (ith == nullptr)
      throw std::out_of_range("Member is out of bounds.");

   return *ith->ship;
}

const Ship &Squadron::operator[](size_t i) const {
   return at(i);
}

std::ostream &operator<<(std::ostream &os, const Squadron &squadron) {
   return squadron.toStream(os);
}

std::ostream &Squadron::toStream(std::ostream &os) const {
   os << "Squadron: " << name << std::endl;
   os << "   max speed: " << getMaxVelocity() << " MGLT" << std::endl;
   os << "   total weight: " << getTotalWeight() << " tons" << std::endl;
   os << std::endl;

   os << "-- Leader: " << std::endl;

   if ( leader != nullptr ) {
      os << *leader << std::endl;
      os << std::endl;
   }

   os << "-- Members: " << std::endl;

   for (Member* tmp = first; tmp != nullptr; tmp = tmp->next) {
      if (tmp->ship != leader) {
         os << *tmp->ship << std::endl;
         os << std::endl;
      }
   }

   return os;
}

unsigned long Squadron::getMaxVelocity() const {
   unsigned long min = 0;

   for (Member* tmp = first; tmp != nullptr; tmp = tmp->next)
      min = tmp->ship->getMaxVelocity() < min || min == 0 ? tmp->ship->getMaxVelocity() : min;

   return min;
}

double Squadron::getTotalWeight() const {
   double weight = 0;

   for (Member* tmp = first; tmp != nullptr; tmp = tmp->next)
      weight += tmp->ship->getWeight();

   return weight;
}

double Squadron::getFuelConsumption(unsigned long distance) const {
   unsigned long maxVel = getMaxVelocity();
   double consumption = 0;

   for (Member* tmp = first; tmp != nullptr; tmp = tmp->next)
      consumption += tmp->ship->getFuelConsumption(distance, maxVel);

   return consumption;
}

Squadron::Member*& Squadron::findPredecessor(const Ship& ship)  {
    for ( Member** scan = &first ;  ; scan = &((*scan)->next) )
        if ( *scan == nullptr or (*scan)->ship == &ship )
            return *scan;
}

Squadron::Member* Squadron::findIth(size_t i) const {
    Member* scan = first;
    while( i-- && scan != nullptr )
         scan = scan->next;
    return scan;
}





