cmake_minimum_required(VERSION 3.21)
project(Labo_2___Squadron)

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo_2___Squadron main.cpp Ships/Ship.cpp Ships/Ship.hpp Squadron/Squadron.cpp Squadron/Squadron.hpp Ships/ShipModels.cpp Ships/ShipModels.hpp Squadron/SquadronMember.cpp Squadron/SquadronMember.hpp)
