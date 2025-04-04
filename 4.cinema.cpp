 #include <iostream>

using namespace std;

class Cinema {
private:
    char seats[5][5];

public:
    Cinema() {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                seats[i][j] = 'O';
    }

    void displaySeats() {
        cout << "\n Seats \n";
        cout << "   1 2 3 4 5\n";
        for (int i = 0; i <5; i++) {
            cout << i+1<<" ";
            for (int j = 0; j < 5; j++) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bookSeat() {
        int row, col;

        while (true) {
            displaySeats();

            cout << "\nEnter row number (1-5): ";
            cin >> row;
            cout << "Enter column number (1-5): ";
            cin >> col;

            if (row < 1 || row > 5 || col < 1 || col > 5) {
                cout << "  Invalid  !  \n";
                continue;
            }

            row -= 1;
            col -= 1;

            if (seats[row][col] == 'X') {
                cout << "  Seat already booked! Please choose another seat.\n";
            } else {
                seats[row][col] = 'X';
                break;
            }
        }
    }
};

int main() {
    Cinema cinema;
    cinema.bookSeat();
    cinema.displaySeats();
    cout << "\nThank You!! for your booking \n";
    return 0;
}
