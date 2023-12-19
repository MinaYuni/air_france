#include <cstring>

#include "OandD.cpp"

using namespace std;


/// Class with the flight number for an object OandD
class FlightNbr {
 private:
    char* flight_number;
    OandD* OD;

 public:
  FlightNbr(char*, OandD*);

  void set_flight_number(char *flight_num);
  char *get_flight_number();

  void set_OD(OandD *od);
  OandD *get_OD();
};


/* CONSTRUCTOR */

/**
 * Constructor of the object FlightNbr.
 * @param flight_num Flight Number
 * @param OD Object OandD
 */
FlightNbr::FlightNbr(char* flight_num, OandD* OD) : flight_number(nullptr), OD(nullptr) {
    set_flight_number(flight_num);
    set_OD(OD);
}


/* SETTERS AND GETTERS */

/**
 * Setter for the attribute flight_number.
 * @param flight_num Flight Number
 */
void FlightNbr::set_flight_number(char* flight_num) {
    delete[] flight_number;
    flight_number = new char[strlen(flight_num) + 1];
    strcpy(flight_number, flight_num);
}

/**
 * Getter for the attribute flight_number.
 * @return Attribute flight_number
 */
char* FlightNbr::get_flight_number() {
    return flight_number;
}

/**
 * Setter for the attribute OD.
 * @param od Object OandD
 */
void FlightNbr::set_OD(OandD* od) {
    delete OD;
    OD = od;
}

/**
 * Getter for the attribute OD.
 * @return Attribute OD
 */
OandD* FlightNbr::get_OD() {
    return OD;
}
