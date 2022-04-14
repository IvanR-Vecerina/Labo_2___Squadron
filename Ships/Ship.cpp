/**
 * @author Ivan Vecerina
 * @date 17/03/2022
 *
 * @details definitions of "Ship.hpp"
 */

#include "Ship.hpp"
#include <cmath>
#include <iomanip>

// ============================== external ==============================
std::ostream& operator<< (std::ostream& os, const Ship& ship) {
   return ship.toStream(os);
}

// ============================== SHIP ==============================
Ship::Ship(const std::string& id, double weight, unsigned int max_speed):
   nickname_(),
   id_("[" + id + "]"),
   weight_(weight),
   max_speed_(max_speed)
{}

// definition for deleted method to prevent unknown reference compilation error
Ship::~Ship() = default;

std::ostream &Ship::toStream(std::ostream &os) const {
   if (!nickname_.empty()) {
      os << nickname_ << " ";
   }

   os << id_ << std::endl;
   os << "  weight : " << std::fixed << std::setprecision(2) << getWeight() << " tons" << std::endl;
   os << "  max speed : " << max_speed_ << " MGLT" << std::endl;

   return os;
}

double Ship::getWeight() const {
   return weight_;
}

void Ship::setNickname(const std::string& name) {
   nickname_ = name;
}

unsigned int Ship::getMaxSpeed() const {
   return max_speed_;
}

double Ship::getFuelConsumption(unsigned long distance, unsigned long speed) const {
   if (speed > max_speed_)
      throw std::invalid_argument("speed cannot exceed the ship_'s max speed.");

   double weight = getWeight();

   return std::cbrt(weight) / 2 * std::log10(weight * speed) * std::log10(distance + 1);
}

// ============================== CARGO SHIP (SHIP) ==============================
CargoShip::CargoShip(const std::string& id, double weight, unsigned int max_speed, double maxCargo, double cargo) :
   Ship(id, weight, max_speed),
   maxCargo_(maxCargo),
   cargo_(){
   setCargo(cargo);
}

// definition for deleted method to prevent unknown reference compilation error
CargoShip::~CargoShip() = default;

std::ostream &CargoShip::toStream(std::ostream &os) const {
   return Ship::toStream(os) << std::fixed << std::setprecision(1) << "  cargo : "
                             << cargo_ << " tons (max : " << maxCargo_ << ")" << std::endl;
}

double CargoShip::getWeight() const {
   return Ship::getWeight() + cargo_;
}

void CargoShip::setCargo(double cargo) {
   if (cargo > maxCargo_ || cargo < 0)
      throw std::invalid_argument("cargo_ has to be between 0 and " + std::to_string(maxCargo_));

   cargo_ = cargo;
}