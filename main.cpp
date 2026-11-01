#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <istream>

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

        /**
         * Safety check to skip the first row of the csv file since it contains column headers
         */
        if (rowNumber == 0)
        {
            rowNumber++;
            continue;
        }

        /**
         * Counter to keep track of column number in the csv file
         */
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
             * Also handles the conversion of string data to int and double data types for the struct
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
                dataField.erase(0, dataField.find_first_not_of(" \t")); // Trim leading whitespace
                flightData.expected_status = dataField;
                break;
            }
            columnNumber++;
        }

        flights.push_back(flightData);
        rowNumber++;
    }

    cout << "Number of flights: " << flights.size() << endl;

    /**
     * Section to now calculate the fuel burn for each flight and compare it to the expected status
     * This uses the defined operational criteria specified in the report
     *
     * Defined Operational Criteria:
     * Total Fuel Needed = fuel for trip + 5% emergency fuel
     * Fuel for Trip = taxi out fuel + flight fuel + taxi in fuel
     * Flight Fuel = distance flown * fuel burn per nm
     *
     * Success Criteria:
     * If the fuel loaded is greater than or equal to the total fuel needed
     * then the flight is considered to have enough fuel and the status is "sufficient"
     *
     * If the fuel loaded is less than the total fuel needed
     * then the flight is considered to not have enough fuel and the status is "insufficient"
     */

    for (const auto &flight : flights)
    {
        double flightFuel = flight.distance_nm * flight.fuel_burn_kg_per_nm;
        double totalFuelNeeded = flight.taxi_out_fuel_kg + flightFuel + flight.taxi_in_fuel_kg;
        totalFuelNeeded *= 1.05; // Add 5% emergency fuel

        string calculatedStatus = (flight.fuel_loaded_kg >= totalFuelNeeded) ? "sufficient" : "insufficient";

        cout << "Flight ID: " << flight.flight_id << endl;
        cout << "Calculated Status: " << calculatedStatus << endl;
        cout << "Expected Status: " << flight.expected_status << endl;
        cout << (calculatedStatus == flight.expected_status ? "Status matches expected." : "Status does not match expected.") << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}
