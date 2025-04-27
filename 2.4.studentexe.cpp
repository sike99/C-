#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Exception {};

class StudentManager {
private:
    struct Student {
        int roll;
        string name;
        int marks;
    };

    string filename;

    void validateMarks(int marks) {
        if (marks < 0 || marks > 100) {
            throw Exception();
        }
    }

public:
    StudentManager(const string& fname) : filename(fname) {}

    void readRecords() {
        ifstream file(filename);
        if (!file) {
            cout << "File not found. Creating new file.\n";
            return;
        }

        Student s;
        cout << "\nCurrent Records:\n";
        while (file >> s.roll >> s.name >> s.marks) {
            cout << "Roll: " << s.roll << ", Name: " << s.name
                 << ", Marks: " << s.marks << endl;
        }
        file.close();
    }

    void addRecord() {
        ofstream file(filename, ios::app);
        Student s;

        cout << "\nEnter new student details:\n";
        cout << "Roll Number: ";
        cin >> s.roll;
        cout << "Name: ";
        cin >> s.name;
        cout << "Marks: ";
        cin >> s.marks;

        try {
            validateMarks(s.marks);
            file << s.roll << " " << s.name << " " << s.marks << endl;
            cout << "Record added successfully.\n";
        } catch (Exception) {
            cout << "Error: Marks must be between 0-100.\n";
        }
        file.close();
    }
};

int main() {
    StudentManager manager("students.txt");
    int choice;

    do {
        cout << "\n1. View Records\n2. Add Record\n3. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                manager.readRecords();
                break;
            case 2:
                manager.addRecord();
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
