#include<iostream>
using namespace std;

void calculateNeed(int need[][10], int max[][10], int allocate[][10], int P, int R) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocate[i][j];
        }
    }
}

bool bankers(int max[][10], int allocate[][10], int P, int R, int available[]) {
    int need[10][10];
    calculateNeed(need, max, allocate, P, R);

    bool finish[10] = {0};
    int safe[10];
    int work[10];
    int count = 0;

    for (int i = 0; i < R; i++) {
        work[i] = available[i];
    }

    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < R; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == R) {
                    for (int k = 0; k < R; k++) {
                        work[k] += allocate[i][k];
                    }
                    finish[i] = 1;
                    safe[count++] = i;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "System is not in a safe state" << endl;
            return false;
        }
    }

    cout << "System is in a safe state. Safe sequence is: ";
    for (int i = 0; i < P; i++) {
        cout << "P" << safe[i];
        if (i != P - 1) cout << " -> ";
    }
    cout << endl;
    return true;
}

int main() {
    int P;
    cout << "Enter the number of processes: ";
    cin >> P;

    int R;
    cout << "Enter the number of resources: ";
    cin >> R;

    int allocated[10][10];
    int max[10][10];

    cout << "Enter the allocated matrix: " << endl;
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            cin >> allocated[i][j];
        }
    }

    cout << "Enter the max matrix: " << endl;
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            cin >> max[i][j];
        }
    }

    int available[R];
    cout << "Enter the available resources: ";
    for (int i = 0; i < R; i++) {
        cin >> available[i];
    }

    bankers(max, allocated, P, R, available);

    return 0;
}