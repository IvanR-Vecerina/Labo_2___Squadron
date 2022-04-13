//
// Created by Ivan Vecerina on 17/03/2022.
//

#ifndef LABO_2___SQUADRON_SQUADRON_HPP
#define LABO_2___SQUADRON_SQUADRON_HPP


#include "../Ships/Ship.hpp"
#include <string>

class Squadron;

Squadron operator+(const Squadron &squadron, Ship &ship);
Squadron operator-(const Squadron &squadron, const Ship &ship);

std::ostream &operator<<(std::ostream &os, const Squadron &squadron);

class Squadron {
public:
   Squadron(const std::string &name);
   Squadron(const Squadron &squadron);
   ~Squadron();

   Squadron& setLeader(Ship &ship);
   Squadron& demoteLeader(const Ship &ship);

   std::ostream& toStream(std::ostream& os) const;

   Squadron &addShip(Ship &ship);
   Squadron &removeShip(const Ship &ship);

   Squadron add(Ship &ship) const;
   Squadron remove(const Ship &ship) const;

   Squadron &operator+=(Ship &ship);
   Squadron &operator-=(const Ship &ship);

   const Ship &at(size_t i) const;
   const Ship &operator[](size_t i) const;

   // DO Below if time for bonus
   // Ship &at(size_t i);
   // Ship &operator[](size_t i);

   /** Public Getters for convenience **/
   std::string getName() const;
   Ship & getLeader() const;
   unsigned long getMaxVelocity() const;
   double getTotalWeight() const;
   double getFuelConsumption(unsigned long distance) const;

private:

   // Struct because we do not encapsulate any behavior or invariants.
   /** Squadron member list element **/
   struct Member {
      Member(Member *pMember, Ship *pShip) : next(pMember), ship(pShip) {} // inline constructor for struct

      Member *next;
      Ship *ship;
   };

   /** Variables **/
   std::string name;
   Ship *leader;
   Member *first;

   /**
    *
    * @warning private const member function returning non-constant data
    *
    * @param i
    * @return
    */
   Member* findIth(size_t i) const;
   Member*& findPredecessor(const Ship &ship);
   // Member const&  findMember(const Ship& ship) const { return *const_cast<Squadron*>(this)->findPredecessor(ship); }
};


#endif //LABO_2___SQUADRON_SQUADRON_HPP
