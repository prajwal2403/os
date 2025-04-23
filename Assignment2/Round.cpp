#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Round {
public:
    int id;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    int remaining_bt;

    void input(int id, int at, int bt) {
        this->id = id;
        this->at = at;
        this->bt = bt;
        this->remaining_bt = bt;
        this->ct = 0;
        this->wt = 0;
        this->tat = 0;
    }

    void display() {
        cout << "P" << id << "                " << at << "              " << bt << "              " 
             << ct << "              " << wt << "              " << tat << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of Processes: ";
    cin >> n;

    vector<Round> Process(n);

    for (int i = 0; i < n; i++) {
        int at, bt;
        cout << "Enter the Arrival Time and Burst Time of Process P" << i << " respectively: ";
        cin >> at >> bt;
        Process[i].input(i, at, bt);
    }

    int timeQuantum;
    cout << "Enter the Time Quantum: ";
    cin >> timeQuantum;

    sort(Process.begin(), Process.end(), [](Round P1, Round P2) { return P1.at < P2.at; });

    queue<int> readyQ;
    vector<bool> inQueue(n, false);
    int currentTime = 0, completed = 0;

    while (completed < n) {
        // Add processes that have arrived to ready queue
        for (int i = 0; i < n; i++) {
            if (Process[i].at <= currentTime && Process[i].remaining_bt > 0 && !inQueue[i]) {
                readyQ.push(i);
                inQueue[i] = true;
            }
        }

        if (!readyQ.empty()) {
            int idx = readyQ.front();
            readyQ.pop();

            int execTime = min(timeQuantum, Process[idx].remaining_bt);
            currentTime += execTime;
            Process[idx].remaining_bt -= execTime;

            // Add new arrivals while executing current process
            for (int i = 0; i < n; i++) {
                if (Process[i].at <= currentTime && Process[i].remaining_bt > 0 && !inQueue[i]) {
                    readyQ.push(i);
                    inQueue[i] = true;
                }
            }

            if (Process[idx].remaining_bt == 0) {
                Process[idx].ct = currentTime;
                Process[idx].tat = Process[idx].ct - Process[idx].at;
                Process[idx].wt = Process[idx].tat - Process[idx].bt;
                completed++;
            } else {
                readyQ.push(idx); // Put it back to end
            }

        } else {
            currentTime++; // No process available, idle CPU
        }
    }

    // Display results
    cout << "Process ID        AT              BT              CT              WT              TAT" << endl;
    for (auto& P : Process) {
        P.display();
    }

    return 0;
}
