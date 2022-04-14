/**
 * @author Ivan Vecerina
 * @date 17/03/2022
 *
 * @details definitions of "Squadron.hpp"
 */

#include <iomanip>
#include "Squadron.hpp"

// ============================== external ==============================
std::ostream& operator<<(std::ostream &os, const Squadron &squadron) {
   return squadron.toStream(os);
}

Squadron operator+ (const Squadron& squadron, Ship& ship) {
   return squadron.add(ship);
}

Squadron operator- (const Squadron& squadron, const Ship& ship) {
   return squadron.remove(ship);
}

// ============================== SQUADRON ==============================
Squadron::Squadron(const std::string& name) :
   name_(name),
   leader_(nullptr),
   first_(nullptr)
{
}

Squadron::Squadron(const Squadron &squadron) :
   name_(squadron.name_),
   leader_(squadron.leader_),
   first_(nullptr) {

   for (Member* tmp = squadron.first_; tmp != nullptr; tmp = tmp->next_)
      addShip(*tmp->ship_);
}

Squadron::~Squadron() {
   while (first_ != nullptr)
      removeShip(*first_->ship_);
}

Squadron& Squadron::operator=(const Squadron &squadron) {
   Squadron temp(squadron);

   // Works because we are exchanging pointers
   std::swap(name_,temp.name_);
   std::swap(leader_,temp.leader_);
   std::swap(first_,temp.first_);

   return *this;
}

Squadron& Squadron::setLeader(Ship& ship) {
   addShip(ship); //in case it wasn't included
   leader_ = &ship;

   return *this;
}

Squadron& Squadron::demoteLeader() {
   leader_ = nullptr;

   return *this;
}

std::ostream& Squadron::toStream(std::ostream &os) const {
   // Squad info
   os << "Squadron: " << name_ << std::endl;
   os << "  max speed: " << getMaxSpeed() << " MGLT" << std::endl;
   os << "  total weight: " << std::fixed << std::setprecision(2) << getTotalWeight() << " tons" << std::endl;
   os << std::endl;

   // Leader
   os << "-- Leader: " << std::endl;

   if (leader_ != nullptr ) {
      os << *leader_ << std::endl;
   }

   // Members
   os << "-- Members: " << std::endl;

   for (Member* tmp = first_; tmp != nullptr; tmp = tmp->next_) {
      if (tmp->ship_ != leader_) {
         os << *tmp->ship_ << std::endl;
      }
   }

   return os;
}

Squadron& Squadron::addShip(Ship& ship) {
   Member*& prev = findPredecessor(ship);

   if( prev == nullptr ) // if not null, ship_ is already in the list
      prev = new Member( nullptr, &ship );

   return *this;
}

Squadron& Squadron::removeShip(const Ship& ship) {
   if (&ship == leader_)
      demoteLeader();

   Member*& prev = findPredecessor(ship);
   Member* next = prev->next_;

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

Squadron& Squadron::operator+=(Ship& ship) {
   return addShip(ship);
}

Squadron& Squadron::operator-=(const Ship& ship) {
   return removeShip(ship);
}

const Ship& Squadron::at(size_t i) const {
   return *findIth(i)->ship_;
}

const Ship& Squadron::operator[](size_t i) const {
   return at(i);
}

ShipRef Squadron::at(size_t i) {
   return ShipRef( &findIth(i)->ship_ ); ;
}

ShipRef Squadron::operator[](size_t i)  {
   return at(i);
}

unsigned long Squadron::getMaxSpeed() const {
   unsigned long min = 0;

   for (Member* tmp = first_; tmp != nullptr; tmp = tmp->next_)
      min = tmp->ship_->getMaxSpeed() < min || min == 0 ? tmp->ship_->getMaxSpeed() : min;

   return min;
}

double Squadron::getTotalWeight() const {
   double weight = 0;

   for (Member* tmp = first_; tmp != nullptr; tmp = tmp->next_)
      weight += tmp->ship_->getWeight();

   return weight;
}

double Squadron::getFuelConsumption(unsigned long distance) const {
   unsigned long maxVel = getMaxSpeed();
   double consumption = 0;

   for (Member* tmp = first_; tmp != nullptr; tmp = tmp->next_)
      consumption += tmp->ship_->getFuelConsumption(distance, maxVel);

   return consumption;
}

Squadron::Member* Squadron::findIth(size_t i) const {
   Member* scan = first_;

   while( i-- && scan != nullptr )
      scan = scan->next_;

   if (scan == nullptr)
      throw std::out_of_range("Member is out of bounds.");

   return scan;
}

Squadron::Member*& Squadron::findPredecessor(const Ship& ship)  {
   for (Member** scan = &first_ ;  ; scan = &((*scan)->next_) )
      if ( *scan == nullptr or (*scan)->ship_ == &ship )
         return *scan;
}


// ============================== SHIP REF ==============================
ShipRef::ShipRef(Ship **ref) : m(ref)  {
}

ShipRef &ShipRef::operator=(Ship &ship) {
   *m = &ship;

   return *this;
}

Ship *ShipRef::operator->() {
   return *m;
}

ShipRef::operator Ship&() const {
   return **m;
}
