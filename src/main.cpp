#include <iostream>
#include <vector>

#include "FlightNbr.cpp"
#include "utils.cpp"

using namespace std;


int main() {
    string data_file = R"(D:\Users\minha\Documents\air_france-test_dev_aide_decision\input\OrigineDestinationTarif.csv)";
    string output_OD = R"(D:\Users\minha\Documents\air_france-test_dev_aide_decision\output\OutputFile_OD.csv)";
    string output_FN = R"(D:\Users\minha\Documents\air_france-test_dev_aide_decision\output\OutputFile_FN.csv)";

    // - Question 4 -
    vector<OandD> OD_data = read_csv(data_file);
    display_data(OD_data);

    // - Question 6 -
    export_OnD(output_OD, OD_data);

    // - Question 8 -
    char* num_vol = string_to_char("FN001");
    FlightNbr FN(num_vol, &OD_data[0]);
    export_flight_nbr(output_FN, FN);

    return 0;
}

