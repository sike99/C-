#include <iostream>
using namespace std;

class ArrayStack {
private:
    int arr[10];
    int top;
    int size;

public:
    ArrayStack() : top(-1), size(0) {}

    void push(int val) {
        if(size >= 10) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++top] = val;
        size++;
    }

    int pop() {
        if(size <= 0) {
            cout << "Stack underflow!\n";
            return -1;
        }
        size--;
        return arr[top--];
    }

    int findMiddle() {
        if(size <= 0) return -1;
        return arr[size/2];
    }

    void reverseBottomHalf() {
        int half = size/2;
        for(int i=0; i<half/2; i++) {
            swap(arr[i], arr[half-1-i]);
        }
    }

    void display() {
        cout << "Stack: ";
        for(int i=0; i<size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.display();
    cout << "Middle: " << stack.findMiddle() << endl;

    stack.reverseBottomHalf();
    stack.display();

    return 0;
};
