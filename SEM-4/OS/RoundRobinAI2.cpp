#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Process {
    int pid; // process ID
    int burst_time; // burst time
    int arrival_time; // arrival time
    int remaining_time; // remaining time
    int waiting_time; // waiting time
    int turnaround_time; // turnaround time
};

bool compareArrivalTime(Process p1, Process p2) {
    return p1.arrival_time < p2.arrival_time;
}

int main() {
    int n, quantum;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> quantum;
    vector<Process> processes(n);
    queue<Process> readyQueue;

    for(int i = 0; i < n; i++) {
        processes[i].pid = i+1;
        cout << "Enter burst time for process " << i+1 << ": ";
        cin >> processes[i].burst_time;
        cout << "Enter arrival time for process " << i+1 << ": ";
        cin >> processes[i].arrival_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = processes[0].arrival_time;

    while(!readyQueue.empty() || processes.size() > 0) {
        while(processes.size() > 0 && processes[0].arrival_time <= currentTime) {
            readyQueue.push(processes[0]);
            processes.erase(processes.begin());
        }

        if(readyQueue.empty()) {
            currentTime = processes[0].arrival_time;
        }
        else {
            Process currentProcess = readyQueue.front();
            readyQueue.pop();

            if(currentProcess.remaining_time <= quantum) {
                currentTime += currentProcess.remaining_time;
                currentProcess.turnaround_time = currentTime - currentProcess.arrival_time;
                currentProcess.waiting_time = currentProcess.turnaround_time - currentProcess.burst_time;
                avg_waiting_time += currentProcess.waiting_time;
                avg_turnaround_time += currentProcess.turnaround_time;
            }
            else {
                currentTime += quantum;
                currentProcess.remaining_time -= quantum;
                while(processes.size() > 0 && processes[0].arrival_time <= currentTime) {
                    readyQueue.push(processes[0]);
                    processes.erase(processes.begin());
                }
                readyQueue.push(currentProcess);
            }
        }
    }

    cout << "PID\tBT\tAT\tWT\tTAT\n";
    for(int i=0; i<n; i++) {
        cout << processes[i].pid << "\t" << processes[i].burst_time << "\t" << processes[i].arrival_time << "\t" << processes[i].waiting_time << "\t" << processes[i].turnaround_time << endl;
    }

    cout << "Average waiting time: " << avg_waiting_time / n << endl;
    cout << "Average turnaround time: " << avg_turnaround_time / n << endl;

    return 0;
}
