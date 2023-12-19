#ifndef OANDD_HPP
#define OANDD_HPP

#include <iostream>
#include <set>
#include <fstream>
#include <cstring>

using namespace std;

class OandD {
 private:
  char* origin;
  char* destination;
  set<double> fare_list;

 public:
  OandD(char*, char*, set<double>);

  void set_origin(char*);
  char* get_origin();

  void set_destination(char*);
  char* get_destination();

  void set_fare_list(set<double> fares);
  set<double> get_fare_list();

  double get_min_fare();
  double get_max_fare();
  double get_avg_fare();

  void export_stats(const string& filename);
};

#endif  // OANDD_HPP
