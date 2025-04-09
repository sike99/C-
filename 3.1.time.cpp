#include <iostream>
using namespace std;

class InvalidTimeException {};

class Time {
private:
    int hours;
    int minutes;

    void validateTime() {
        if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
            throw InvalidTimeException();
        }
    }

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
        try {
            validateTime();
        } catch (InvalidTimeException) {
            cout << "In-case of invalid time,Time will be set to 00:00\n"<<endl;;
            hours = 0;
            minutes = 0;
        }
    }

    Time operator+(const Time& t) {
        int totalMinutes = minutes + t.minutes;
        int extraHours = totalMinutes / 60;
        int newMinutes = totalMinutes % 60;
        int newHours = (hours + t.hours + extraHours) % 24;

        return Time(newHours, newMinutes);
    }

    int operator>(const Time& t) {
        if (hours > t.hours) return 1;
        if (hours == t.hours && minutes > t.minutes) return 1;
        return 0;
    }

    void display() {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes;
    }
};

int main() {
    try {
        Time t1(10, 30);
        Time t2(5, 45);
        Time t3(25, 70);

        cout << "Time 1: "; t1.display(); cout << endl;
        cout << "Time 2: "; t2.display(); cout << endl;
        cout << "Time 3: "; t3.display(); cout << endl<<endl;

        Time sum = t1 + t2;
        cout << "Sum: "; sum.display(); cout << endl;

        if (t1 > t2) {
            cout << "Time 1 is later than Time 2\n";
        } else {
            cout << "Time 2 is later than Time 1\n";
        }

    } catch (InvalidTimeException) {
        cout << "Invalid time!\n";
    }

    return 0;
}
