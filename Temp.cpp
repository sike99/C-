#include <iostream>
using namespace std;

class Temperatureconverter{

    double temperature;
    int choice;

public:
    void Choice() {
        cout<< "Choose conversion:"<<endl<<endl;
        cout<< "1. Celsius to Fahrenheit\n";
        cout<< "2. Fahrenheit to Celsius"<<endl<<endl;
        cout<< "Enter choice (1 or 2): ";
        cin>> choice;
    }
    void getInput() {
        cout<< "Enter temperature value: ";
        cin>> temperature;
    }

    void convertanddisplay() {
        if (choice == 1) {
            double fahrenheit = (temperature * 9.0/5.0) + 32;
            cout<< temperature << "C = " << fahrenheit << "F" << endl;
        } else {
            double celsius = (temperature - 32) * 5.0/9.0;
            cout<< temperature << "F = " << celsius << "C" << endl;
        }
    }
};

int main() {
    Temperatureconverter tc;
    tc.Choice();
    tc.getInput();
    tc.convertanddisplay();
    return 0;
}
