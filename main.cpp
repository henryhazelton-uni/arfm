#include <iostream>
#include <fstream>

using namespace std;

struct
{
    string flight_id;
    int distance_nm;
    int fuel_burn_kg_per_nm;
    int taxi_out_fuel_kg;
    int taxi_in_fuel_kg;
    int fuel_loaded_kg;
    bool expected_status;
} flightData;

int main()
{
    /**
     * Define an fstream for each file
     */
    fstream aircraftFile("../simple_fuel_flights.csv");

    string line = "";

    while (getline(aircraftFile, line))
    {
        cout << line << endl;
    }

    return 0;
}
