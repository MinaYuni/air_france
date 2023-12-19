#include <iostream>
#include <set>
#include <fstream>
#include <cstring>

using namespace std;


/// Class with a list of fares for an origin and destination
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

  void export_stats(const string &filename);
};


/* CONSTRUCTOR */

/**
 * Constructor of the object OandD.
 * @param ori Home airport name
 * @param dest Destination airport name
 * @param fares List of fares
 */
OandD::OandD(char* ori, char* dest, set<double> fares) : origin(nullptr), destination(nullptr) {
    set_origin(ori);
    set_destination(dest);
    set_fare_list(fares);
}


/* SETTERS AND GETTERS */

/**
 * Setter for the attribute origin.
 * @param ori Home airport name
 */
void OandD::set_origin(char* ori) {
    delete[] origin;
    origin = new char[strlen(ori) + 1];
    strcpy(origin, ori);
}

/**
 * Getter for the attribute origin.
 * @return Attribute origin
 */
char* OandD::get_origin() {
    return origin;
}

/**
 * Setter for the attribute destination.
 * @param dest Destination airport name
 */
void OandD::set_destination(char* dest) {
    delete[] destination;
    destination = new char[strlen(dest) + 1];
    strcpy(destination, dest);
}

/**
 * Getter for the attribute destination.
 * @return Attribute destination
 */
char* OandD::get_destination() {
    return destination;
}

/**
 * Setter for the attribute fare_list.
 * @param fares List of fares
 */
void OandD::set_fare_list(set<double> fares) {
    fare_list = fares;
}

/**
 * Getter for the attribute fare_list.
 * @return Attribute fare_list
 */
set<double> OandD::get_fare_list() {
    return fare_list;
}


/* METHODS */

/**
 * Find the minimum fare from the fare list.
 * @return Minimum fare
 */
double OandD::get_min_fare() {
    if (fare_list.empty()) {
        cout << "Fare list is empty." << endl;
        return 0;
    }
    else {
        return *fare_list.begin();
    }
}

/**
 * Find the maximum fare from the fare list.
 * @return Maximum fare
 */
double OandD::get_max_fare() {
    if (fare_list.empty()) {
        cout << "Fare list is empty." << endl;
        return 0;
    }
    else {
        return *fare_list.rbegin();
    }
}

/**
 * Calculates the average of the fare list.
 * @return Average fare
 */
double OandD::get_avg_fare() {
    if (fare_list.empty()) {
        cout << "Fare list is empty." << endl;
        return 0;
    }
    else {
        double sum = 0;
        for (auto itr : fare_list) {
            sum += itr;
        }
        return sum / fare_list.size();
    }
}

/**
 * Export the statistics (minimum, maximum and average fare) to the file given in parameter in the format "Origin;Destination;MinimumFare;MaximumFare;AverageFare".
 * @param filename The name of the file to which you want to export the data
 */
void OandD::export_stats(const string& filename) {
    ofstream output_file(filename, ios::app);  // open in add mode

    if (!output_file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    // add the header if the file is empty
    output_file.seekp(0, ios::end);  // move to the end of the file
    if (output_file.tellp() == 0) { // if the cursor is in the 0 position, this means that the file is empty
        output_file << "Origin;Destination;MinimumFare;MaximumFare;AverageFare" << endl;
    }

    output_file << origin << ";" << destination << ";" << get_min_fare() << ";" << get_max_fare() << ";" << get_avg_fare() << endl;

    output_file.close();
}


