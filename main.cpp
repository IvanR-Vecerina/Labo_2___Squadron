#include <cstdlib>
#include <iostream>
#include "Ships/ShipModels.hpp"
#include "Squadron/Squadron.hpp"

using namespace std;


int main() {

    TIEHunter blackLeader;
    blackLeader.setNickname("Black Leader");
    TIEHunter blackTwo;
    Shuttle shuttle(23.4);

    Squadron squad("Black Squadron");
    squad += blackLeader;
    squad += blackTwo;
    squad += shuttle;

    squad.setLeader(blackLeader);

    cout << squad << endl;

    return EXIT_SUCCESS;
}