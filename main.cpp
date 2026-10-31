#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /**
     * Define an fstream for each file
     */
    fstream aircraftFile("simple_fuel_flights.csv");

    string line = "";

    getline(aircraftFile, line);
    cout << line << endl;

    return 0;
}
