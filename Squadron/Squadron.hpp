/**
 * @author Ivan Vecerina
 * @date 17/03/2022
 *
 * @details Declaration of Squadron and ShipRef classes
 */

#ifndef LABO_2_SQUADRON_SQUADRON_HPP
#define LABO_2_SQUADRON_SQUADRON_HPP

#include "../Ships/Ship.hpp"
#include <string>

class Squadron;
class ShipRef; // trick for operator[]

/**
 * Operator "<<" overload to enable printing of squadron using the right toStream() method.
 *
 * @param os        output-stream
 * @param squadron  squad to display
 *
 * @return output-stream containing squad display data
 */
std::ostream& operator<<(std::ostream& os, const Squadron& squadron);

/**
 * Operator "+" overload to enable the addition of a ship to the squad.
 *
 * @param squadron squad
 * @param ship     ship to add
 *
 * @return new squad instance with the added ship.
 */
Squadron operator+(const Squadron& squadron, Ship& ship);

/**
 * Operator "-" overload to enable the removal of a ship from the squad.
 *
 * @param squadron squad
 * @param ship     ship to remove
 *
 * @return new squad instance with the ship removed.
 */
Squadron operator-(const Squadron& squadron, const Ship& ship);

/**
 * @brief Squadron class managing a simple linked list of Ships
 */
class Squadron {
public:
   /**
    * @brief Squadron constructor
    *
    * @param name squad name
    */
   explicit Squadron(const std::string& name);

   /**
    * @brief Squadron copy constructor
    *
    * @param squadron squad to copy
    */
   Squadron(const Squadron& squadron);

   /**
    * @brief Squadron destructor
    */
   ~Squadron();

   /**
    * @brief Operator "=" overload allowing assignment between Squadrons.
    *
    * @param squadron whose values we are assigning to ours
    *
    * @return the inplace copy of the squadron
    */
   Squadron& operator=(const Squadron& squadron);

   /**
    * @brief setter for leader
    *
    * @param ship leader's ship
    *
    * @return this
    */
   Squadron& setLeader(Ship& ship);

   /**
    * @brief leader remover
    *
    * @return this
    */
   Squadron& demoteLeader();

   /**
    * @brief squadron displaying method that has access to the squad's members
    *
    * @param os output-stream
    *
    * @return output-stream with squadron display data in it
    */
   std::ostream& toStream(std::ostream& os) const;

   /**
    * @brief method allowing the inplace addition of a ship to the squad
    *
    * @param ship ship to add
    *
    * @return this
    */
   Squadron& addShip(Ship& ship);

   /**
    * @brief method allowing the inplace removal of a ship from the squad
    *
    * @param ship ship to remove
    *
    * @return this
    */
   Squadron& removeShip(const Ship& ship);

   /**
    * @brief method allowing the addition of a ship to the squad
    *
    * @param ship ship to add
    *
    * @return new squad instance with the added ship.
    */
   Squadron add(Ship& ship) const;

   /**
    * @brief method allowing the inplace removal of a ship from the squad
    *
    * @param ship ship to remove
    *
    * @return new squad instance with the ship removed.
    */
   Squadron remove(const Ship& ship) const;

   /**
    * @brief operator "+=" overload allowing the inplace addition of a ship to the squad
    *
    * @param ship ship to add
    *
    * @return this
    */
   Squadron& operator+=(Ship& ship);

   /**
    * @brief operator "-=" overload allowing the inplace removal of a ship from the squad
    *
    * @param ship ship to remove
    *
    * @return this
    */
   Squadron& operator-=(const Ship& ship);

   /**
    * @brief "at" method to get the ith member of the squad by constant reference (for display)
    *
    * @param i ith member
    *
    * @return the ith member of the squad by constant reference
    */
   const Ship& at(size_t i) const;

   /**
    * @brief "[]" operator overload to get the ith member of the squad by constant reference (for display)
    *
    * @param i ith member
    *
    * @return the ith member of the squad by constant reference
    */
   const Ship& operator[](size_t i) const;

   /**
    * @brief "at" method to get a ShipRef on the ith member of the squad (for modifications)
    *
    * @param i ith member
    *
    * @return the ShipRef on the ith member of the squad
    */
   ShipRef at(size_t i);

   /**
    * @brief "[]" operator overload to get a ShipRef on the ith member of the squad (for modifications)
    *
    * @param i ith member
    *
    * @return the ShipRef on the ith member of the squad
    */
   ShipRef operator[](size_t i);

   /**
    * @brief getter for max speed
    *
    * @return Max Squad speed
    */
   unsigned long getMaxSpeed() const;

   /**
    * @brief getter for squad's total weight
    *
    * @return Total Squad weight
    */
   double getTotalWeight() const;

   /**
    * @brief getter for squad's consumption for the given distance
    *
    * @param distance distance to travel
    *
    * @return Squad consumption at Max Squad speed over distance
    */
   double getFuelConsumption(unsigned long distance) const;

private:
   // Struct because we do not encapsulate any behavior or invariants.
   /** Squadron member list element (node) **/
   struct Member {
      Member(Member *pMember, Ship *pShip) : next_(pMember), ship_(pShip) {} // inline constructor for struct

      Member* next_;
      Ship* ship_;
   };

   /** Member Variables **/
   std::string name_;
   Ship* leader_;
   Member* first_;

   /**
    * @brief getter for Ith member of the squad
    *
    * @warning private const member function returning non-constant data
    * @throws  out_of_range exception if given index doesn't exist
    *
    * @param i the ith member we want
    *
    * @return pointer on the desired member
    */
   Member* findIth(size_t i) const;

   /**
    * @brief check existence of ship within squad and get a reference to it
    *
    * @param ship ship to look for
    *
    * @return a reference to the pointer on the Member/node of the ship
    */
   Member*& findPredecessor(const Ship& ship);
};

/**
 * @brief ShipRef class allowing us to use the "[]" operator of Squadron with "=" operator without affecting the Ship. And to modify the ship using the public ship methods.
 */
class ShipRef {
public:
   /**
    * @brief constructor for ShipRef
    *
    * @param ref "reference" on ship
    */
   explicit ShipRef(Ship** ref);

   /**
    * @brief "=" operator overload usable with the "[]" operator of Squadron that only affects the instance of squadron.
    *
    * @param ship ship that is being assigned
    *
    * @return the ShipRef
    */
   ShipRef& operator= (Ship& ship);

   /**
    * @brief "->" operator overload enabling the use of ship methods on the return of a squad[i].
    *
    * @return a pointer to the ship.
    */
   Ship* operator ->();

   /**
    * @brief overload of the cast operator (implicit) allowing the use of squad[i] as a Ship on external functions.
    *
    * @return reference on the Ship
    */
   operator Ship&() const;
private:
   /** Member variable **/
   Ship** m;
};

#endif //LABO_2_SQUADRON_SQUADRON_HPP
