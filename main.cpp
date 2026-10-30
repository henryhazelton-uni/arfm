#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream iFile;
    string line = "";
    iFile.open("aircraft.csv");

    getline(iFile, line);
    cout << line << endl;

    return 0;
}
