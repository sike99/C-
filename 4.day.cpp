#include <iostream>
using namespace std;

int main() {
    int day;

    cout<< "Enter a number (1-7) where:\n";
    cout<< "1 = Sunday\n2 = Monday\n3 = Tuesday\n";
    cout<< "4 = Wednesday\n5 = Thursday\n6 = Friday\n7 = Saturday\n";
    cout<< "Your choice: ";
    cin >> day;

    if (day == 1) {
        cout<< "Sunday";
    }
    else if (day == 2) {
        cout<< "Monday";
    }
    else if (day == 3) {
        cout<< "Tuesday";
    }
    else if (day == 4) {
        cout<< "Wednesday";
    }
    else if (day == 5) {
        cout<< "Thursday";
    }
    else if (day == 6) {
        cout<< "Friday";
    }
    else if (day == 7) {
        cout<< "Saturday";
    }
    else {
        cout<< "Invalid number! Please enter 1-7 only.";
    }

    return 0;
}
