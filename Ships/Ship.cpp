//
// Created by Ivan Vecerina on 17/03/2022.
//

#include "Ship.hpp"
#include <cmath>

Ship::Ship(std::string id, unsigned int weight, unsigned int max_velocity):
id("[" + id + "]"), weight(weight), max_velocity(max_velocity) {}

void Ship::setNickname(const std::string& name) {
   this->nickname = name;
}

double Ship::getWeight() const {
   return weight;
}

unsigned int Ship::getMaxVelocity() const {
   return max_velocity;
}

double Ship::getFuelConsumption(unsigned long distance, unsigned long velocity) const {
   return cbrt(getWeight()) / 2 * log10(getWeight() * velocity) * log10(distance + 1);
}

std::ostream &Ship::toStream(std::ostream &os) const {
   if (!nickname.empty()) {
      os << nickname << " ";
   }

   os << id << std::endl;
   os << "  weight : " << getWeight() << " tons" << std::endl;
   os << "  max speed : " << max_velocity << " MGLT" << std::endl;

   return os;
}

std::ostream& operator<< (std::ostream& os, const Ship& ship) {
   return ship.toStream(os);
}


