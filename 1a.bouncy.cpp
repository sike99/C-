#include <iostream>
using namespace std;

class BouncyChecker {
private:
    int number;
    int isBouncy;

    void checkIncreasing() {
        int n = number;
        int prev = n % 10;
        n /= 10;
        while (n > 0) {
            int current = n % 10;
            if (current > prev) return;
            prev = current;
            n /= 10;
        }
        isBouncy = 0;
    }

    void checkDecreasing() {
        int n = number;
        int prev = n % 10;
        n /= 10;
        while (n > 0) {
            int current = n % 10;
            if (current < prev) return;
            prev = current;
            n /= 10;
        }
        isBouncy = 0;
    }

public:
    void setNumber(int num) {
        number = num;
        isBouncy = 1;
    }

    void checkBouncy() {
        if (number < 10) {
            isBouncy = 0;
            return;
        }
        checkIncreasing();
        checkDecreasing();
    }

    void displayResult() {
        if (isBouncy == 1) {
            cout << number << " is a bouncy number." << endl;
        } else {
            cout << number << " is not a bouncy number." << endl;
        }
    }
};

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    BouncyChecker c;
    c.setNumber(num);
    c.checkBouncy();
    c.displayResult();

    return 0;
}
