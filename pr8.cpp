#include <iostream>
#include <vector>
using namespace std;

struct SeatNode {
    int seatNumber;
    bool isBooked;
    SeatNode* next;
    SeatNode* prev;

    SeatNode(int num) : seatNumber(num), isBooked(false), next(nullptr), prev(nullptr) {}
};

class Row {
public:
    SeatNode* head;

    Row() : head(nullptr) {
        initializeRow();
    }

    void initializeRow() {
        SeatNode* prevNode = nullptr;
        for (int i = 1; i <= 7; i++) {
            SeatNode* newNode = new SeatNode(i);
            if (!head) {
                head = newNode;
                head->next = head;
                head->prev = head;
                prevNode = head;
            } else {
                newNode->prev = prevNode;
                newNode->next = head;
                prevNode->next = newNode;
                head->prev = newNode;
                prevNode = newNode;
            }
        }
    }

    void displayAvailableSeats() {
        if (!head) return;
        SeatNode* temp = head;
        bool hasAvailable = false;
        do {
            if (!temp->isBooked) {
                cout << temp->seatNumber << " ";
                hasAvailable = true;
            }
            temp = temp->next;
        } while (temp != head);
        if (!hasAvailable) {
            cout << "No available seats.";
        }
        cout << endl;
    }

    bool bookSeat(int seatNumber) {
        if (!head) return false;
        SeatNode* temp = head;
        do {
            if (temp->seatNumber == seatNumber) {
                if (!temp->isBooked) {
                    temp->isBooked = true;
                    cout << "Seat " << seatNumber << " booked successfully.\n";
                    return true;
                } else {
                    cout << "Seat " << seatNumber << " is already booked.\n";
                    return false;
                }
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat " << seatNumber << " not found.\n";
        return false;
    }

    bool cancelBooking(int seatNumber) {
        if (!head) return false;
        SeatNode* temp = head;
        do {
            if (temp->seatNumber == seatNumber) {
                if (temp->isBooked) {
                    temp->isBooked = false;
                    cout << "Seat " << seatNumber << " booking cancelled successfully.\n";
                    return true;
                } else {
                    cout << "Seat " << seatNumber << " is not booked.\n";
                    return false;
                }
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat " << seatNumber << " not found.\n";
        return false;
    }
};

int main() {
    vector<Row> theater(10); // Array of 10 rows

    // Random initial bookings
    theater[0].bookSeat(3);
    theater[0].bookSeat(5);
    theater[1].bookSeat(1);
    theater[1].bookSeat(7);

    int choice;
    do {
        cout << "\nCinemax Theater Ticket Booking System\n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel a booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int row;
                cout << "Enter row number (1-10): ";
                cin >> row;
                if (row < 1 || row > 10) {
                    cout << "Invalid row number.\n";
                } else {
                    cout << "Available seats in row " << row << ": ";
                    theater[row - 1].displayAvailableSeats();
                }
                break;
            }
            case 2: {
                int row, seat;
                cout << "Enter row number (1-10): ";
                cin >> row;
                cout << "Enter seat number (1-7): ";
                cin >> seat;
                if (row < 1 || row > 10 || seat < 1 || seat > 7) {
                    cout << "Invalid row or seat number.\n";
                } else {
                    theater[row - 1].bookSeat(seat);
                }
                break;
            }
            case 3: {
                int row, seat;
                cout << "Enter row number (1-10): ";
                cin >> row;
                cout << "Enter seat number (1-7): ";
                cin >> seat;
                if (row < 1 || row > 10 || seat < 1 || seat > 7) {
                    cout << "Invalid row or seat number.\n";
                } else {
                    theater[row - 1].cancelBooking(seat);
                }
                break;
            }
            case 4:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
