#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;


/* CONVERSION FUNCTIONS */

/**
 * Convert char* to string.
 * @param char_pointer Char pointer
 * @return String
 */
string char_to_string(char* char_pointer) {
    string str = char_pointer;
    return str;
}

/**
 * Convert string to char*.
 * @param str String
 * @return Char*
 */
char* string_to_char(string str) {
    int length = str.length();
    char* list_char = new char[length + 1];
    strcpy(list_char, str.c_str());
    return list_char;
}


/* FUNCTIONS RELATED TO THE EXERCICE */

/**
 * Update the fare list for the object OandD corresponding to the given origin and destination if it already exists in the object vector.
 * @param data vector of OandD objects
 * @param ori the origin of the object OandD we want to find
 * @param dest the destination of the object OandD we want to find
 * @param fare the fare to be added to the corresponding object OandD
 * @return True if the fare has been added, else return false.
 */
bool update_OD(vector<OandD>& data, char* ori, char* dest, double fare) {
    for (auto& OD : data) {
        if (strcmp(OD.get_origin(), ori) == 0 && strcmp(OD.get_destination(), dest) == 0) {
            set<double> fare_list = OD.get_fare_list();
            fare_list.insert(fare);
            OD.set_fare_list(fare_list);

            return true;
        }
    }

    return false;
}

/**
 * Read the given CSV file and store the data in an OandD vector.
 * @param filename CSV file
 * @return OandD data
 */
vector<OandD> read_csv(string filename) {
    vector<OandD> OD_data; // OandD storage

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return OD_data;
    }

    // ignore header: read the 1st line without retrieving it to ignore it
    string header;
    getline(file, header);

    string line;
    while(getline(file, line)) {

        istringstream line_stream(line);
        string ori_str, dest_str, fare_str;

        if (getline(line_stream, ori_str, ';') &&
            getline(line_stream, dest_str, ';') &&
            getline(line_stream, fare_str, ';')) {

            istringstream fare_stream(fare_str);
            double fare;

            fare_stream >> fare;

            char* ori = string_to_char(ori_str);
            char* dest = string_to_char(dest_str);

            bool OD_updated = update_OD(OD_data, ori, dest, fare); // flag to check whether an OandD has been updated

            // if there has been no update, this means that the object OandD doesn't exist, so we create it and insert it in the vector
            if (!OD_updated) {
                set<double> fare_list;
                fare_list.insert(fare);
                OandD OD(ori, dest, fare_list);
                OD_data.push_back(OD);
            }
        }
    }

    file.close();

    return OD_data;
}

/**
 * Export OandD statistics to a file given in parameter in the format "Origin;Destination;MinimumFare;MaximumFare;AverageFare".
 * @param filename File where the statistics will be exported
 * @param OD_data OandD data
 */
void export_OnD(string& filename, vector<OandD> OD_data) {
    // clean file
    ofstream ofs;
    ofs.open(filename, ofstream::trunc);
    ofs.close();

    // export the statistics to the file
    for (auto OD : OD_data) {
        OD.export_stats(filename);
    }
}

/**
 * Export flight data with statistics for the corresponding OandD object to a file given in parameter in the format "FlightNumber;Origin;Destination;MinimumFare;MaximumFare;AverageFare".
 * @param filename File where the data will be exported
 * @param FN An FlightNbr object
 */
void export_flight_nbr(string& filename, FlightNbr FN) {
    ofstream output_file(filename);

    if (!output_file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    OandD* OD = FN.get_OD();

    output_file << "FlightNumber;Origin;Destination;MinimumFare;MaximumFare;AverageFare" << endl;
    output_file << FN.get_flight_number() << ";" << OD->get_origin() << ";" << OD->get_destination() << ";"
                << OD->get_min_fare() << ";" << OD->get_max_fare() << ";" << OD->get_avg_fare() << endl;

    output_file.close();
}


/* DISPLAY FUNCTIONS */

/**
 * Display the statistics (minimum, maximum and average fare) for an OandD object.
 * @param OD An object OandD
 */
void display_stats(OandD OD) {
    cout << "Minimum fare: " << OD.get_min_fare() << endl;
    cout << "Maximum fare: " << OD.get_max_fare() << endl;
    cout << "Average fare: " << OD.get_avg_fare() << endl;
}

/**
 * Displays data and statistics for all OandD objects in the vector.
 * @param OD_data OandD vector
 */
void display_data(vector<OandD> OD_data) {
    for (auto OD : OD_data) {
        cout << "===== " << OD.get_origin() << " --> " << OD.get_destination() << " =====\n";
        cout << "--- Fares ---\n";
        for (double tarif : OD.get_fare_list()) {
            cout << tarif << ", ";
        }
        cout << "\n\n--- Statistics ---\n";
        display_stats(OD);
        cout << endl;
    }
}

