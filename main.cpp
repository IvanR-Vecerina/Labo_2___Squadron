#include <cstdlib>
#include <iostream>
#include "Ships/ShipModels.hpp"
#include "Squadron/Squadron.hpp"

void demo();
void tests();

// false -> demo, true -> tests
const bool TEST_MODE = false;

/**
 * @author Ivan Vecerina
 * @date 17.03.2022
 *
 * @return exit_result
 */
int main() {

   if (TEST_MODE) {
      tests();
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

void tests(){

}