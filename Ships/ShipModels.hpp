//
// Created by Ivan Vecerina on 17/03/2022.
//

#ifndef LABO_2___SQUADRON_SHIPMODELS_HPP
#define LABO_2___SQUADRON_SHIPMODELS_HPP


#include "Ship.hpp"
#include <string>

class TIEHunter : public Ship {
public:
    TIEHunter();

private:
    static unsigned int no;
    const static std::string model;
    const static double m_weight;
    const static unsigned long m_maxVelocity;
};
class TIEInterceptor : public Ship {
public:
    TIEInterceptor();

private:
    static unsigned int no;
    const static std::string model;
    const static double m_weight;
    const static unsigned long m_maxVelocity;
};

class CargoShip : public Ship {
public:
    ~CargoShip() override = default;

    std::ostream& toStream(std::ostream& os) const override;
    double getWeight() const override;
    void setCargo(double cargo);

private:
    double cargo;
    const double maxCargo;
protected:
    CargoShip(std::string id, unsigned int weight, unsigned int max_velocity, double maxCargo, double cargo = 0.0);
};


class Shuttle : public CargoShip {
public:
    Shuttle(double cargo = 0);

private:
    static unsigned int no;
    const static std::string model;
    const static double m_weight;
    const static unsigned long m_maxVelocity;
    const static double m_maxCargo;
};
class Dreadnought : public CargoShip {
public:
    Dreadnought(double cargo = 0);

private:
    static unsigned int no;
    const static std::string model;
    const static double m_weight;
    const static unsigned long m_maxVelocity;
    const static double m_maxCargo;
};


#endif //LABO_2___SQUADRON_SHIPMODELS_HPP
