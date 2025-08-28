#include<bits/stdc++.h>
using namespace std;

void srtn(vector<int> arrivalTime, vector<int> cpuTime) {
    int n = arrivalTime.size();
    vector<int> waitingTime(n);
    vector<int> turnaroundTime(n);

    vector<int> remainingTime(cpuTime.begin(), cpuTime.end());

    int currentTime = 0;
    int completed = 0;
    int shortest;
    double awt = 0;
    double att = 0;

    while (completed != n) {
        shortest = -1;
        int shortestTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && remainingTime[i] < shortestTime && remainingTime[i] > 0) {
                shortestTime = remainingTime[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            currentTime++;
            continue;
        }

        remainingTime[shortest]--;
        if (remainingTime[shortest] == 0) {
            completed++;
            int endTime = currentTime + 1;
            turnaroundTime[shortest] = endTime - arrivalTime[shortest];
            waitingTime[shortest] = turnaroundTime[shortest] - cpuTime[shortest];
        }
        currentTime++;
    }

    // Displaying results

    for (int i = 0; i < n; i++) {
        cout <<"Process "<< i + 1 <<" : "<<"Waiting Time :"<< waitingTime[i] <<"\t"<<"Turnaround Time : "<< turnaroundTime[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        awt += waitingTime[i];
    }
    cout<<"Average Waiting Time : "<<fixed<<setprecision(2)<<(awt/n)<<endl;

    for (int i = 0; i < n; i++) {
        att += turnaroundTime[i];
    }
    cout<<"Average Turnaround Time : "<<fixed<<setprecision(2)<<(att/n)<<endl;
}

int main() {
    int n;
    cout << "Enter the number of process: ";
    cin >> n;

    vector<int> arrivalTime(n);
    vector<int> cpuTime(n);

    cout << "Enter the CPU times"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> cpuTime[i];
    }

    cout << "Enter the arrival times"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arrivalTime[i];
    }

    cout<<endl;
    srtn(arrivalTime, cpuTime);

    return 0;
}
