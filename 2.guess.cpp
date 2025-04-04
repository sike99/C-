#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class NumberGuessingGame {
private:
    int a;
    int maxNumber;

public:
    void setDifficulty(int choice) {
        if (choice == 1) {
            maxNumber = 8;
        }
        else if (choice == 2) {
            maxNumber = 30;
        }
        else {
            maxNumber = 50;
        }

        srand(time(0));
        a = rand() % maxNumber + 1;
    }

    void play() {
        int guess;

        cout<< "Guess a number between 1 and " << maxNumber << ": ";
        cin>> guess;

        if (guess == a) {
            cout<< "WOW! You guessed it right!" <<endl;
        }
        else {
            cout<< "EYEEHH WRONG! The number was " << a <<endl;
        }
    }
};

int main() {
    NumberGuessingGame g;
    int choice;

    cout<< "Select difficulty:" << endl;
    cout<< "1. Easy (1-8)" << endl;
    cout<< "2. Medium (1-30)" << endl;
    cout<< "3. Hard (1-50)" << endl;
    cout<< "Enter your choice (1-3): ";
    cin >> choice;

    g.setDifficulty(choice);
    g.play();

    return 0;
}
