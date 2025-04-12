#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class PeopleManager {
private:
    vector<string> names;
    map<string, int> nameAgeMap;

public:
    void addPerson(string name, int age) {
        names.push_back(name);
        nameAgeMap[name] = age;
    }

    void displayAboveAge(int age) {
        cout << "People above " << age << ":\n";
        for(auto& pair : nameAgeMap) {
            if(pair.second > age) {
                cout << pair.first << " (" << pair.second << ")\n";
            }
        }
    }

    void displaySorted() {
        sort(names.begin(), names.end());
        cout << "Names sorted alphabetically:\n";
        for(auto& name : names) {
            cout << name << "\n";
        }
    }
};

int main() {
    PeopleManager manager;
    manager.addPerson("Hero", 20);
    manager.addPerson("Shirish", 30);
    manager.addPerson("Hang", 22);

    manager.displayAboveAge(22);
    manager.displaySorted();

    return 0;
}
