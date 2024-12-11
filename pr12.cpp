#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor to initialize deque
    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor to clean up memory
    ~Deque() {
        delete[] arr;
    }

    // Check if deque is full
    bool isFull() {
        return size == capacity;
    }

    // Check if deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Add element to the front
    void addFront(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot add element." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
        size++;
        cout << "Added " << value << " to the front." << endl;
    }

    // Add element to the rear
    void addRear(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot add element." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
        cout << "Added " << value << " to the rear." << endl;
    }

    // Delete element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete element." << endl;
            return;
        }
        cout << "Deleted " << arr[front] << " from the front." << endl;
        if (front == rear) {
            front = rear = -1; // Deque is now empty
        } else {
            front = (front + 1) % capacity;
        }
        size--;
    }

    // Delete element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete element." << endl;
            return;
        }
        cout << "Deleted " << arr[rear] << " from the rear." << endl;
        if (front == rear) {
            front = rear = -1; // Deque is now empty
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
    }

    // Display elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Deque elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the deque: ";
    cin >> capacity;

    Deque deque(capacity);
    int choice, value;

    do {
        cout << "\nDeque Operations:\n";
        cout << "1. Add to front\n";
        cout << "2. Add to rear\n";
        cout << "3. Delete from front\n";
        cout << "4. Delete from rear\n";
        cout << "5. Display deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add to the front: ";
                cin >> value;
                deque.addFront(value);
                break;
            case 2:
                cout << "Enter value to add to the rear: ";
                cin >> value;
                deque.addRear(value);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                deque.display();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}