#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Books {
private:
    string bookTitles[10];
    string filename;


    int findBookInFile(string title) {
        ifstream file(filename);
        string currentTitle;

        while(file >> currentTitle) {
            if(currentTitle == title) {
                return 1;
            }
        }
        return 0;
    }

public:

    void inputTitles() {
        cout << "Enter the name of 10 books:\n";
        for(int i = 0; i < 10; i++) {
            cout << "Book " << (i+1) << ": ";
            cin >> bookTitles[i];
        }
    }

    void saveToFile() {
        cout << "Enter filename to save: ";
        cin >> filename;

        ofstream file(filename);
        for(int i = 0; i < 10; i++) {
            file << bookTitles[i] << "\n";
        }
        cout << "Books saved to " << filename << "!\n";
    }

    void searchBook() {
        string searchTitle;
        cout << "Enter book title to search: ";
        cin >> searchTitle;

        if(findBookInFile(searchTitle)) {
            cout << "Book found!\n";
        } else {
            cout << "Book not found.\n";
        }
    }
};

int main() {
    Books m;

    m.inputTitles();
    m.saveToFile();
    m.searchBook();

    return 0;
}
