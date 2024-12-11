#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int prn;
    Node* next;

    Node(string n, int p) : name(n), prn(p), next(nullptr) {}
};

class PinnacleClub {
private:
    Node* head;
    Node* tail;

public:
    PinnacleClub() : head(nullptr), tail(nullptr) {}

    // Add member
    void addMember(string name, int prn, bool isPresident = false, bool isSecretary = false) {
        Node* newNode = new Node(name, prn);

        if (isPresident) {
            newNode->next = head;
            head = newNode;
            if (!tail) tail = head;
            cout << "President added successfully.\n";
        } else if (isSecretary) {
            if (!tail) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            cout << "Secretary added successfully.\n";
        } else {
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            cout << "Member added successfully.\n";
        }
    }

    // Delete member
    void deleteMember(int prn) {
        if (!head) {
            cout << "Club is empty.\n";
            return;
        }

        if (head->prn == prn) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (!head) tail = nullptr;
            cout << "President deleted successfully.\n";
            return;
        }

        Node* current = head;
        while (current->next && current->next->prn != prn) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            if (temp == tail) tail = current;
            delete temp;
            cout << "Member deleted successfully.\n";
        } else {
            cout << "Member not found.\n";
        }
    }

    // Compute total members
    int totalMembers() const {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Display members
    void displayMembers() const {
        if (!head) {
            cout << "Club is empty.\n";
            return;
        }

        Node* current = head;
        while (current) {
            cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
            current = current->next;
        }
    }

    // Concatenate two lists
    void concatenate(PinnacleClub& other) {
        if (!head) {
            head = other.head;
            tail = other.tail;
        } else if (other.head) {
            tail->next = other.head;
            tail = other.tail;
        }
        other.head = other.tail = nullptr;
        cout << "Lists concatenated successfully.\n";
    }
};

int main() {
    PinnacleClub divisionA, divisionB;

    // Add members to division A
    divisionA.addMember("Alice", 101, true); // President
    divisionA.addMember("Bob", 102);
    divisionA.addMember("Charlie", 103, false, true); // Secretary

    // Add members to division B
    divisionB.addMember("David", 201, true); // President
    divisionB.addMember("Eve", 202);
    divisionB.addMember("Frank", 203, false, true); // Secretary

    cout << "\nDivision A Members:\n";
    divisionA.displayMembers();

    cout << "\nDivision B Members:\n";
    divisionB.displayMembers();

    // Concatenate lists
    divisionA.concatenate(divisionB);

    cout << "\nMembers after concatenation:\n";
    divisionA.displayMembers();

    cout << "\nTotal members in Division A: " << divisionA.totalMembers() << endl;

    // Delete a member
    divisionA.deleteMember(102);
    cout << "\nMembers after deletion:\n";
    divisionA.displayMembers();

    return 0;
}
