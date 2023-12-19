cmake_minimum_required(VERSION 3.27)
project(air_france_test_dev_aide_decision)

set(CMAKE_CXX_STANDARD 14)

add_executable(air_france_test_dev_aide_decision
        src/main.cpp
        src/lib/OandD.hpp
        src/lib/FlightNbr.hpp
        src/lib/utils.hpp
        src/lib/main.hpp)
