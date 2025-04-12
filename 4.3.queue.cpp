#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int arr[10];
    int front, rear, size;

public:
    ArrayQueue() : front(0), rear(-1), size(0) {}

    void enqueue(int val) {
        if(size >= 10) {
            cout << "Queue overflow!\n";
            return;
        }
        rear = (rear+1)%10;
        arr[rear] = val;
        size++;
    }

    int dequeue() {
        if(size <= 0) {
            cout << "Queue underflow!\n";
            return -1;
        }
        int val = arr[front];
        front = (front+1)%10;
        size--;
        return val;
    }

    void reverseFirstK(int k) {
        if(k > size) {
            cout << "NO!K exceeds queue size!\n";
            return;
        }
        for(int i=0; i<k/2; i++) {
            int pos1 = (front+i)%10;
            int pos2 = (front+k-1-i)%10;
            swap(arr[pos1], arr[pos2]);
        }
    }

    void interleaveHalves() {
        if(size % 2 != 0) {
            cout << "Queue size must be EVEN for interleaving!!\n";
            return;
        }
        int half = size/2;
        for(int i=0; i<half; i++) {
            int pos1 = (front+i)%10;
            int pos2 = (front+half+i)%10;
            if(i%2 == 1) {
                swap(arr[pos1], arr[pos2]);
            }
        }
    }

    void display() {
        cout << "Queue: ";
        for(int i=0; i<size; i++) {
            int pos = (front+i)%10;
            cout << arr[pos] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue q;

    for(int i=1; i<=6; i++) q.enqueue(i*10);

    cout << "Original Queue:\n";
    q.display();

    q.reverseFirstK(3);
    cout << "\nAfter reversing first 3 elements:\n";
    q.display();

    q.interleaveHalves();
    cout << "\nAfter interleaving half of them:\n";
    q.display();

    cout << "\nDequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    return 0;
}
