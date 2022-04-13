//
// Created by Ivan Vecerina on 17/03/2022.
//

#include "ShipModels.hpp"

unsigned int TIEHunter::no = 0;
const std::string TIEHunter::model = "TIE/LN";
const double TIEHunter::m_weight = 6.00;
const unsigned long TIEHunter::m_maxVelocity = 100;

unsigned int TIEInterceptor::no = 0;
const std::string TIEInterceptor::model = "TIE/IN";
const double TIEInterceptor::m_weight = 5.00;
const unsigned long TIEInterceptor::m_maxVelocity = 110;

unsigned int Shuttle::no = 0;
const std::string Shuttle::model = "Lambda-class shuttle";
const double Shuttle::m_weight = 360.00;
const unsigned long Shuttle::m_maxVelocity = 54;
const double Shuttle::m_maxCargo = 80.00;

unsigned int Dreadnought::no = 0;
const std::string Dreadnought::model = "Super-class Star Destroyer";
const double Dreadnought::m_weight = 9000000000.00;
const unsigned long Dreadnought::m_maxVelocity = 40;
const double Dreadnought::m_maxCargo = 250000.00;

TIEHunter::TIEHunter() :
   Ship(model + " #" + std::to_string(++no), m_weight, m_maxVelocity) {}

TIEInterceptor::TIEInterceptor() :
   Ship(model + " #" + std::to_string(++no), m_weight, m_maxVelocity) {}

CargoShip::CargoShip(std::string id, double weight, unsigned int max_velocity, double maxCargo, double cargo) :
Ship(id, weight, max_velocity), maxCargo(maxCargo) {
   setCargo(cargo);
}

void CargoShip::setCargo(double cargo) {
   if (cargo > maxCargo || cargo < 0)
      throw std::invalid_argument("cargo has to be between 0 and " + std::to_string(maxCargo));

   this->cargo = cargo;
}

double CargoShip::getWeight() const {
   return Ship::getWeight() + cargo;
}

std::ostream &CargoShip::toStream(std::ostream &os) const {
   return Ship::toStream(os) << "  cargo : " << cargo << " tons (max : " << maxCargo << ")" << std::endl;
}

Shuttle::Shuttle(double cargo) :
   CargoShip(model + " #" + std::to_string(++no), m_weight, m_maxVelocity, m_maxCargo, cargo){
}



Dreadnought::Dreadnought(double cargo) :
   CargoShip(model + " #" + std::to_string(++no), m_weight, m_maxVelocity, m_maxCargo, cargo){
}