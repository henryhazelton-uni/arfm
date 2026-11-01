#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct FlightData
{
    string flight_id;
    int distance_nm;
    double fuel_burn_kg_per_nm;
    int taxi_out_fuel_kg;
    int taxi_in_fuel_kg;
    double fuel_loaded_kg;
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
     * Counter to keep track of row number in the csv file
     */
    int rowNumber = 0;

    /**
     * Extract data from the csv file to use later for arithmetic
     * Loop thorugh each line in the csv file
     */
    while (getline(aircraftFile, line))
    {
        cout << line << endl;

        if (rowNumber == 0)
        {
            rowNumber++;
            continue;
        }

        int columnNumber = 0;

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
             * For each data field in the csv, keep track of column number and populate the struct with the data
             */
            switch (columnNumber)
            {
            case 0:
                flightData.flight_id = dataField;
                break;
            case 1:
                flightData.distance_nm = stoi(dataField);
                break;
            case 2:
                flightData.fuel_burn_kg_per_nm = stod(dataField);
                break;
            case 3:
                flightData.taxi_out_fuel_kg = stoi(dataField);
                break;
            case 4:
                flightData.taxi_in_fuel_kg = stoi(dataField);
                break;
            case 5:
                flightData.fuel_loaded_kg = stod(dataField);
                break;
            case 6:
                flightData.expected_status = dataField;
                break;
            }
            columnNumber++;
        }

        flights.push_back(flightData);
        rowNumber++;
    }

    cout << "Number of flights: " << flights.size() << endl;

    return 0;
}
