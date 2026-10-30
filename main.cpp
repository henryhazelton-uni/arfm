#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /**
     * Define a fstream for each file
     */
    fstream aircraftFile("aircraft.csv");
    fstream flightFile("flights.csv");
    fstream fuelFile("fuel_log.csv");

    string line = "";

    getline(aircraftFile, line);
    cout << line << endl;

    return 0;
}
