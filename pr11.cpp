#include <iostream>
#include <queue>
#include <string>
using namespace std;

class JobQueue {
private:
    queue<string> jobQueue;

public:
    // Function to add a job to the queue
    void addJob(const string& jobName) {
        jobQueue.push(jobName);
        cout << "Job '" << jobName << "' added to the queue." << endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (jobQueue.empty()) {
            cout << "No jobs in the queue to delete." << endl;
        } else {
            cout << "Job '" << jobQueue.front() << "' removed from the queue." << endl;
            jobQueue.pop();
        }
    }

    // Function to display all jobs in the queue
    void displayJobs() const {
        if (jobQueue.empty()) {
            cout << "No jobs in the queue." << endl;
        } else {
            cout << "Jobs in the queue: ";
            queue<string> tempQueue = jobQueue;
            while (!tempQueue.empty()) {
                cout << tempQueue.front() << " ";
                tempQueue.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    JobQueue jq;
    int choice;
    string jobName;

    do {
        cout << "\nJob Queue Management System\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume the newline character after entering choice

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                getline(cin, jobName);
                jq.addJob(jobName);
                break;
            case 2:
                jq.deleteJob();
                break;
            case 3:
                jq.displayJobs();
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