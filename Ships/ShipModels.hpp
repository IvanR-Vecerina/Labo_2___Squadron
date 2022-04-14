/**
 * @author Ivan Vecerina
 * @date 17/03/2022
 *
 * @details Declaration of Ship models classes
 */

#ifndef LABO_2_SQUADRON_SHIPMODELS_HPP
#define LABO_2_SQUADRON_SHIPMODELS_HPP

#include "Ship.hpp"

/**
 * TIEHunter class inheriting of Ship.
 */
class TIEHunter : public Ship {
public:
   /** Constructor and destructor **/
   TIEHunter();
   ~TIEHunter() override;

private:
   /** Static model serial number counter **/
   static unsigned int no;

   /** Model specs **/
   const static char* MODEL;
   const static double WEIGHT;
   const static unsigned long MAX_SPEED;
};

/**
 * TIEInterceptor class inheriting of Ship.
 */
class TIEInterceptor : public Ship {
public:
   /** Constructor and destructor **/
   TIEInterceptor();
   ~TIEInterceptor() override;

private:
   /** Static model serial number counter **/
   static unsigned int no;

   /** Model specs **/
   const static char* MODEL;
   const static double WEIGHT;
   const static unsigned long MAX_SPEED;
};

/**
 * Shuttle class inheriting of CargoShip.
 */
class Shuttle : public CargoShip {
public:
   /** Constructor and destructor **/
   explicit Shuttle(double cargo = 0.0); // default cargo to 0.0
   ~Shuttle() override;

private:
   /** Static model serial number counter **/
   static unsigned int no;

   /** Model specs **/
   const static char* MODEL;
   const static double WEIGHT;
   const static unsigned long MAX_SPEED;
   const static double MAX_CARGO;
};

/**
 * Dreadnought class inheriting of CargoShip.
 */
class Dreadnought : public CargoShip {
public:
   /** Constructor and destructor **/
   explicit Dreadnought(double cargo = 0.0); // default cargo to 0.0
   ~Dreadnought() override;

private:
   /** Static model serial number counter **/
   static unsigned int no;

   /** Model specs **/
   const static char* MODEL;
   const static double WEIGHT;
   const static unsigned long MAX_SPEED;
   const static double MAX_CARGO;
};

#endif //LABO_2_SQUADRON_SHIPMODELS_HPP
