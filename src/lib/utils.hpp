#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>

#include "OandD.hpp"
#include "FlightNbr.hpp"

using namespace std;

/* CONVERSION FUNCTIONS */
string char_to_string(char* char_pointer);
char* string_to_char(string str);

/* FUNCTIONS RELATED TO THE EXERCISE */
bool update_OD(vector<OandD>& data, char* ori, char* dest, double fare);
vector<OandD> read_csv(string filename);
void export_OnD(string& filename, vector<OandD> OD_data);
void export_flight_nbr(string& filename, FlightNbr FN);

/* DISPLAY FUNCTIONS */
void display_stats(OandD OD);
void display_data(vector<OandD> OD_data);

#endif  // UTILS_HPP
