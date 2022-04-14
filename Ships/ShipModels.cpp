/**
 * @author Ivan Vecerina
 * @date 17/03/2022
 *
 * @details definitions of "ShipModels.hpp"
 */

#include "ShipModels.hpp"

// ============================== TIE HUNTER (SHIP) ==============================
unsigned int TIEHunter::no = 0;
const char* TIEHunter::MODEL = "TIE/LN";
const double TIEHunter::WEIGHT = 6.00;
const unsigned long TIEHunter::MAX_SPEED = 100;

TIEHunter::TIEHunter() :
   Ship(
      std::string(MODEL) + " #" + std::to_string(++no),
      WEIGHT,
      MAX_SPEED
   ) {
}

TIEHunter::~TIEHunter() = default;

// ============================== TIE INTERCEPTOR (SHIP) ==============================
unsigned int TIEInterceptor::no = 0;
const char* TIEInterceptor::MODEL = "TIE/IN";
const double TIEInterceptor::WEIGHT = 5.00;
const unsigned long TIEInterceptor::MAX_SPEED = 110;

TIEInterceptor::TIEInterceptor() :
   Ship(std::string(MODEL) + " #" + std::to_string(++no),
        WEIGHT,
        MAX_SPEED
   ) {
}

TIEInterceptor::~TIEInterceptor() = default;

// ============================== SHUTTLE (CARGO SHIP) ==============================
unsigned int Shuttle::no = 0;
const char* Shuttle::MODEL = "Lambda-class shuttle";
const double Shuttle::WEIGHT = 360.00;
const unsigned long Shuttle::MAX_SPEED = 54;
const double Shuttle::MAX_CARGO = 80.00;

Shuttle::Shuttle(double cargo) :
   CargoShip(std::string(MODEL) + " #" + std::to_string(++no),
             WEIGHT,
             MAX_SPEED,
             MAX_CARGO, cargo
   ) {
}

Shuttle::~Shuttle() = default;

// ============================== DREADNOUGHT (CARGO SHIP) ==============================
unsigned int Dreadnought::no = 0;
const char* Dreadnought::MODEL = "Super-class Star Destroyer";
const double Dreadnought::WEIGHT = 9000000000.00;
const unsigned long Dreadnought::MAX_SPEED = 40;
const double Dreadnought::MAX_CARGO = 250000.00;

Dreadnought::Dreadnought(double cargo) :
   CargoShip(std::string(MODEL) + " #" + std::to_string(++no),
             WEIGHT,
             MAX_SPEED,
             MAX_CARGO, cargo
   ) {
}

Dreadnought::~Dreadnought() = default;