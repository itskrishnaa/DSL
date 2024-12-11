#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int* orders;
    int front;
    int rear;
    int capacity;
    int size;

public:
    // Constructor to initialize the circular queue
    PizzaParlor(int maxOrders) {
        capacity = maxOrders;
        orders = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor to clean up memory
    ~PizzaParlor() {
        delete[] orders;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Add an order to the queue
    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Order queue is full. Cannot accept more orders." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        orders[rear] = orderID;
        size++;
        cout << "Order " << orderID << " placed successfully." << endl;
    }

    // Serve an order from the queue
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve." << endl;
            return;
        }
        cout << "Order " << orders[front] << " served successfully." << endl;
        if (front == rear) {
            front = rear = -1; // Queue is now empty
        } else {
            front = (front + 1) % capacity;
        }
        size--;
    }

    // Display all orders in the queue
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue." << endl;
            return;
        }
        cout << "Orders in the queue: ";
        for (int i = 0; i < size; i++) {
            cout << orders[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int maxOrders;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> maxOrders;

    PizzaParlor parlor(maxOrders);
    int choice, orderID;

    do {
        cout << "\nPizza Parlor System:\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> orderID;
                parlor.placeOrder(orderID);
                break;
            case 2:
                parlor.serveOrder();
                break;
            case 3:
                parlor.displayOrders();
                break;
            case 4:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}