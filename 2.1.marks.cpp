#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks[3];

    int checkMarks() {
        for(int i = 0; i < 3; i++) {
            if(marks[i] < 0 || marks[i] > 100) {
                return 0;
            }
        }
        return 1;
    }

public:
    void getDetails() {
        cout<< "enter student name: ";
        cin>>name;

        cout<< "enter marks for 3 subjects: ";
        cin>> marks[0] >> marks[1] >> marks[2];
    }

    void showResults() {
        if(checkMarks() == 0) {
            cout<< "Error! marks should be between 0-100" << endl;
            return;
        }

        int total = marks[0] + marks[1] + marks[2];
        float average = total / 3;
        char grade;

        if(average >= 90) grade = 'A';
        else if(average >= 80) grade = 'B';
        else if(average >= 70) grade = 'C';
        else if(average >= 60) grade = 'D';
        else grade = 'F';

        cout<< "\n----- Results -----" << endl;
        cout<< "Name: " << name << endl;
        cout<< "Total: " << total << endl;
        cout<< "Average: " << average << endl;
        cout<< "Grade: " << grade << endl;
    }
};

int main() {
    Student s;
    s.getDetails();
    s.showResults();
    return 0;
};
