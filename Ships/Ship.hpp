/**
 * @author Ivan Vecerina
 * @date 17/03/2022
 *
 * @details Declaration of Ship and CargoShip abstract classes
 */

#ifndef LABO_2_SQUADRON_SHIP_HPP
#define LABO_2_SQUADRON_SHIP_HPP

#include <ostream>

class Ship;

/**
 * @brief Operator "<<" overload to enable printing of any ship using the right toStream() method.
 *
 * @param os    output-stream
 * @param ship  ship_ to print out
 *
 * @return output-stream containing the ship_'s display data
 */
std::ostream& operator<< (std::ostream& os, const Ship& ship);

/**
 * @brief Abstract Ship class defining the basic "interface" for ships.
 */
class Ship
{
public:
   /**
    * @brief Abstract destructor (= 0)
    */
   virtual ~Ship() = 0;

   /**
    * @brief Polymorphic method that puts ship_ display data into a stream.
    *
    * @param os output-stream
    *
    * @return output-stream containing the ship_'s display data
    */
   virtual std::ostream& toStream(std::ostream& os) const;

   /**
    * @brief Polymorphic method returning the ship_'s total weight
    *
    * @return ship_'s total weight
    */
   virtual double getWeight() const;

   /**
    * @brief Ship nickname setter
    *
    * @param name nickname to give
    */
   void setNickname(const std::string& name);

   /**
    * @brief Getter for ship_'s max speed
    *
    * @return Ships' max speed
    */
   unsigned int getMaxSpeed() const;

   /**
    * @brief Calculates the fuel consumption for the distance at a given speed
    *
    * @param distance distance to travel
    * @param speed    speed at which we want to travel
    *
    * @throws invalid_argument exception if requested speed exceeds the max
    *
    * @return Ship's fuel consumption for the distance at the given speed
    */
   double getFuelConsumption(unsigned long distance, unsigned long speed) const;

   /** Deleted copy constructor and assignment operator for all ships **/
   Ship& operator=(const Ship&) = delete;
   Ship(const Ship&) = delete;


private:
   /** Ship's nickname **/
   std::string nickname_;

   /** Ship's identifier **/
   const std::string id_;
   /** Ship's bare weight **/
   const double weight_;
   /** Ship's maximum speed **/
   const unsigned int max_speed_;


protected:
   /**
    * @brief default ship_ constructor, protected so only available to children
    *
    * @param id         Ship identifier (Model + number)
    * @param weight     Ship weight
    * @param max_speed  Ship max speed
    */
   Ship(const std::string& id, double weight, unsigned int max_speed);
};


/**
 * @brief Abstract specialized (child of) Ship class defining the specialized "interface" for ships with cargo.
 */
class CargoShip : public Ship {
public:
   /**
    * @brief Abstract destructor (= 0)
    */
   ~CargoShip() override = 0;

   /**
    * @brief Polymorphic method that puts cargo_ ship_ display data into a stream.
    *
    * @param os output-stream
    *
    * @return output-stream containing the ship_'s display data
    */
   std::ostream& toStream(std::ostream& os) const override;

   /**
    *
    * @return
    */
   double getWeight() const override;

   /**
    *
    * @param cargo
    *
    * @throws invalid_argument exception if set cargo exceeds the max
    */
   void setCargo(double cargo);

private:
   /** ship_'s current cargo load **/
   double cargo_;
   /** ship_'s maximum cargo load **/
   const double maxCargo_;

protected:
   /**
    * @brief default cargo ship_ constructor, protected so only available to children
    *
    * @param id         Ship identifier (Model + number)
    * @param weight     Ship weight
    * @param max_speed  Ship max speed
    * @param maxCargo   Ship max cargo
    * @param cargo      Ship current cargo
    */
   CargoShip(const std::string& id, double weight, unsigned int max_speed, double maxCargo, double cargo = 0.0);
};

#endif //LABO_2_SQUADRON_SHIP_HPP