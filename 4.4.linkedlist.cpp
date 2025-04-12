#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

    Node* getTail() {
        if (!head) return nullptr;
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        return current;
    }

public:
    LinkedList() : head(nullptr), size(0) {}

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertAtEnd(int val) {
        if (!head) {
            insertAtStart(val);
            return;
        }
        getTail()->next = new Node(val);
        size++;
    }

    void insertAtPosition(int val, int pos) {
        if (pos <= 0) {
            insertAtStart(val);
        } else if (pos >= size) {
            insertAtEnd(val);
        } else {
            Node* current = head;
            for (int i = 1; i < pos; i++) {
                current = current->next;
            }
            Node* newNode = new Node(val);
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }

    void detectAndRemoveLoop() {
        if (!head || !head->next) return;

        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (slow != fast) return;

        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = nullptr;
    }

    Node* getNthFromEnd(int n) {
        if (n <= 0 || n > size) return nullptr;

        Node *first = head, *second = head;
        for (int i = 0; i < n; i++) {
            first = first->next;
        }

        while (first) {
            first = first->next;
            second = second->next;
        }
        return second;
    }

    void reverseGroups(int k) {
        head = reverseGroup(head, k);
    }

    Node* reverseGroup(Node* start, int k) {
        Node *current = start, *prev = nullptr, *next = nullptr;
        int count = 0;

        while (current && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next) {
            start->next = reverseGroup(next, k);
        }

        return prev;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->value;
            if (current->next) cout << " -> ";
            current = current->next;
        }
        cout << " -> NULL" << endl;
    }

    void createTestLoop(int pos) {
        if (pos < 0 || pos >= size) return;

        Node* tail = getTail();
        Node* loopNode = head;
        for (int i = 0; i < pos; i++) {
            loopNode = loopNode->next;
        }
        tail->next = loopNode;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtStart(0);
    list.insertAtPosition(10, 2);

    cout << "Original List: ";
    list.display();

    Node* secondFromEnd = list.getNthFromEnd(2);
    if (secondFromEnd) {
        cout << "2nd from end: " << secondFromEnd->value << endl;
    }

    list.reverseGroups(2);
    cout << "After group reversal (k=2): ";
    list.display();

    list.createTestLoop(1);
    list.detectAndRemoveLoop();
    cout << "After loop removal: ";
    list.display();

    return 0;
}
