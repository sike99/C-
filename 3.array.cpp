#include <iostream>
using namespace std;

class ArraySorter {
private:
    int numbers[10]; // Fixed size of 10 elements

    void Sort() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9-i; j++) {
                if (numbers[j] > numbers[j+1])
                    {
                    int temp = numbers[j];
                    numbers[j] = numbers[j+1];
                    numbers[j+1] = temp;
                }
            }
        }
    }

public:
    void getinput() {
        cout << "Enter 10 numbers:\n";
        for (int i = 0; i < 10; i++) {
            cin >> numbers[i];
        }
    }

    void sortandDisplay() {
        Sort();

        cout << "Sorted numbers:\n";
        for (int i = 0; i < 10; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArraySorter s;
    s.getinput();
    s.sortandDisplay();

    return 0;
}
