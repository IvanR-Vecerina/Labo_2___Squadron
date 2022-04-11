//
// Created by Ivan Vecerina on 17/03/2022.
//

#ifndef LABO_2___SQUADRON_SHIPMODELS_HPP
#define LABO_2___SQUADRON_SHIPMODELS_HPP


#include "Ship.hpp"

class TIEHunter : public Ship {
public:
    TIEHunter();

private:
    static unsigned int no;

};
class TIEInterceptor : public Ship {
public:
    TIEInterceptor();

private:
    static unsigned int no;


};

class CargoShip : public Ship {
public:
    virtual ~CargoShip();

    void setCargo(double cargo);

private:
    double cargo;

protected:
    CargoShip();
    CargoShip(double cargo);
};


class Shuttle : public CargoShip {
public:
    Shuttle(double cargo);

private:
    static unsigned int no;


};
class Dreadnought : public CargoShip {
public:
    Dreadnought(double cargo);

private:
    static unsigned int no;


};


#endif //LABO_2___SQUADRON_SHIPMODELS_HPP
