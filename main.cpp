#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct FlightData
{
    string flight_id;
    int distance_nm;
    float fuel_burn_kg_per_nm;
    int taxi_out_fuel_kg;
    int taxi_in_fuel_kg;
    float fuel_loaded_kg;
    string expected_status;
};

int main()
{
    /**
     * Define an fstream the csv file
     */
    fstream aircraftFile("simple_fuel_flights.csv");

    /**
     * Create a string variable to store each line of the csv file
     */
    string line = "";

    /**
     * Vector to store each data struct as its created
     */
    vector<FlightData> flights;

    /**
     * Extract data from the csv file to use later for arithmetic
     * Loop thorugh each line in the csv file
     */
    while (getline(aircraftFile, line))
    {
        cout << line << endl;
        /**
         * Create a FlightData struct to store the data in the next loop
         */
        FlightData flightData;

        /**
         * Create a string stream of each row in the csv file
         */
        stringstream row(line);

        /**
         * Create a string variable to store each data field of the csv file
         * Used to populate the struct
         */
        string dataField;

        /**
         * Loop thorugh each data field on a row in the csv file
         * Using the comma as a separator to distinguish each field
         */
        while (getline(row, dataField, ','))
        {
            /**
             * For each data field in the csv, populate the data struct
             */
            // Will need to now do some conversions as each thing is coming out as a string steam
            // But will need to convert to appropriate data type and then store using flightData.variableName = dataField(converted)
        }
    }

    return 0;
}
