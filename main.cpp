#include <cstdlib>
#include <iostream>
#include "Ships/ShipModels.hpp"
#include "Squadron/Squadron.hpp"

void demo();
void allTests();
void basicTests();
void errorTests();
void bonusTests();

// false -> demo, true -> allTests
const bool TEST_MODE = true;

/**
 * @author Ivan Vecerina
 * @date 17.03.2022
 *
 * @return exit_result
 */
int main() {

   if (TEST_MODE) {
      allTests();
   } else {
      demo();
   }

   return EXIT_SUCCESS;
}

void demo() {
   TIEHunter blackLeader;
   blackLeader.setNickname("Black leader_");
   TIEHunter blackTwo;
   Shuttle shuttle(23.4);

   Squadron squad("Black Squadron");
   squad += blackLeader;
   squad += blackTwo;
   squad += shuttle;

   squad.setLeader(blackLeader);
   std::cout << squad << std::endl;
}

void allTests() {
   basicTests();
   errorTests();
   bonusTests();
}

void basicTests() {
   std::cout << "===== Start basic testing ====="  << std::endl;

   Shuttle d1;
   Dreadnought d2(3434);
   Shuttle d3(34);
   Dreadnought d4;

   d1.setNickname("Dark Star");

   TIEInterceptor  th1;
   TIEHunter  th2;
   TIEInterceptor  th3;
   TIEHunter  th4;

   th1.setNickname("Yoda");

   Squadron siths("Empire forever");
   siths.addShip(d1);
   siths += d2;
   siths = siths + d3;
   siths = siths.add(d4);
   siths.setLeader(d1);

   Squadron firstJedi("For the republic!");
   Squadron jedi(siths);

   std::cout << siths << siths.getFuelConsumption(1000) << std::endl << std::endl;
   std::cout << jedi << jedi.getFuelConsumption(1000) << std::endl << std::endl;

   jedi.demoteLeader();
   jedi -= d1;
   jedi.removeShip(d2);
   jedi = jedi - d3;
   jedi = jedi.remove(d4);

   std::cout << siths << siths.getFuelConsumption(1000) << std::endl << std::endl;
   std::cout << jedi << jedi.getFuelConsumption(1000) << std::endl << std::endl;

   jedi = firstJedi + th1 + th2 + th3 + th4;
   jedi.setLeader(th1);

   std::cout << siths << siths.getFuelConsumption(1000) << std::endl << std::endl;
   std::cout << jedi << jedi.getFuelConsumption(1000) << std::endl << std::endl;

   std::cout << "===== Basic testing done ====="  << std::endl;
}

void errorTests() {
   std::cout << "===== Start error testing ====="  << std::endl;

   Squadron squad("Black Squadron");
   TIEInterceptor one;

   try {
      std::cout << squad[0] << std::endl;
   } catch(std::out_of_range){
      std::cout << "ok squad[0] is error in empty list" << std::endl;
   }

   squad += one;

   try {
      std::cout << squad[100] << std::endl;
   } catch(std::out_of_range){
      std::cout << "ok squad[100] is error in list with less elements" << std::endl;
   }

   try {
      Shuttle shuttle(100);
   } catch(std::invalid_argument){
      std::cout << "ok error when cargo > max" << std::endl;
   }

   try {
      Shuttle shuttle(-100);
   } catch(std::invalid_argument){
      std::cout << "ok error when cargo < 0" << std::endl;
   }

   Shuttle shuttle(3);

   try {
      shuttle.getFuelConsumption(100,100);
   } catch(std::invalid_argument){
      std::cout << "ok error when speed > max" << std::endl;
   }

   const Squadron s("const");
   // s += shuttle;

   std::cout << "===== Error testing done ====="  << std::endl;
}


void bonusTests() {
   std::cout << "===== Start bonus testing ====="  << std::endl;

   Squadron original("Original");

   Dreadnought dreadnought(100);
   Shuttle shuttle(10);
   TIEHunter hunter;
   TIEInterceptor interceptor;

   original = original + dreadnought + shuttle + hunter;
   original.setLeader(dreadnought);

   Squadron copy(original);

   std::cout << original[2] << std::endl;
   std::cout << copy[2] << std::endl;

   copy[2] = interceptor;

   std::cout << original << std::endl;
   std::cout << copy << std::endl;

   original[0]->setNickname("DOOM");

   std::cout << original << std::endl;
   std::cout << copy << std::endl;

   std::cout << original.getFuelConsumption(100000) << std::endl;
   std::cout << copy.getFuelConsumption(100000) << std::endl;

   dreadnought.setCargo(50000);

   std::cout << original.getFuelConsumption(100000) << std::endl;
   std::cout << copy.getFuelConsumption(100000) << std::endl;

   Squadron squadron("nope");

   try {
      squadron[0] = dreadnought;
   } catch (std::out_of_range) {
      std::cout << "Error in bonus is ok" << std::endl;
   }

   std::cout << "===== Bonus testing done ====="  << std::endl;
}