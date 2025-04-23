#include <bits/stdc++.h>
using namespace std;

class Process {
public:
    int pid, at, bt, rt, ct, tat, wt;
    Process(int id = 0) {
        pid = id;
        at = bt = rt = ct = tat = wt = 0;
    }
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        processes[i] = Process(i + 1);
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].at >> processes[i].bt;
        processes[i].rt = processes[i].bt; // Set remaining time = burst time
    }

    int currentTime = 0, completed = 0;
    float totalTAT = 0, totalWT = 0;
    int prev = -1;

    while (completed < n) {
        int idx = -1;
        int minRT = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (processes[i].at <= currentTime && processes[i].rt > 0 && processes[i].rt < minRT) {
                minRT = processes[i].rt;
                idx = i;
            }
        }

        if (idx != -1) {
            processes[idx].rt--;

            if (processes[idx].rt == 0) {
                completed++;
                processes[idx].ct = currentTime + 1;
                processes[idx].tat = processes[idx].ct - processes[idx].at;
                processes[idx].wt = processes[idx].tat - processes[idx].bt;

                totalTAT += processes[idx].tat;
                totalWT += processes[idx].wt;
            }
        }

        currentTime++;
    }

    // Display output
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t" << p.at << "\t" << p.bt << "\t" << p.ct << "\t" << p.tat << "\t" << p.wt << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << totalTAT / n << endl;
    cout << "Average Waiting Time: " << totalWT / n << endl;

    return 0;
}