#include <iostream>
using namespace std;

class Circle {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}

    float getArea() {
        return 3.14 * radius * radius;
    }

    friend void compareTwoCircles(Circle c1, Circle c2);
};

void compareTwoCircles(Circle c1, Circle c2) {
    float area1 = c1.getArea();
    float area2 = c2.getArea();

    if(area1 > area2) {
        cout << "First circle has larger area (" << area1 << " vs " << area2 << ")\n";
    }
    else if(area2 > area1) {
        cout << "Second circle has larger area (" << area2 << " vs " << area1 << ")\n";
    }
    else {
        cout << "Both circles have equal area (" << area1 << ")\n";
    }
}

class MaxFinder {
public:
    static int findMax(int a, int b) {
        return (a > b) ? a : b;
    }

    static float findMax(float a, float b) {
        return (a > b) ? a : b;
    }

    static int findMax(int a, int b, int c) {
        return findMax(findMax(a, b), c);
    }

    static float findMax(int a, float b) {
        return (a > b) ? a : b;
    }
};

int main() {
    cout << "--- Circle Comparison ---\n";
    Circle circle1(5);
    Circle circle2(7.5);
    compareTwoCircles(circle1, circle2);

    cout << "\n--- MaxFinder Results ---\n";
    cout << "Max between 5 and 10: " << MaxFinder::findMax(5, 10) << endl;
    cout << "Max between 3.5 and 2.8: " << MaxFinder::findMax(3.5, 2.8) << endl;
    cout << "Max among 8, 12, 5: " << MaxFinder::findMax(8, 12, 5) << endl;
    cout << "Max between 7 and 9.2: " << MaxFinder::findMax(7, 9.2) << endl;
    return 0;
}

