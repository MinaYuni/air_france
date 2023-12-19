#ifndef FLIGHTNBR_HPP
#define FLIGHTNBR_HPP

#include <cstring>

#include "OandD.hpp"

class FlightNbr {
 private:
  char* flight_number;
  OandD* OD;

 public:
  FlightNbr(char*, OandD*);

  void set_flight_number(char* flight_num);
  char* get_flight_number();

  void set_OD(OandD* od);
  OandD* get_OD();
};

#endif  // FLIGHTNBR_HPP
