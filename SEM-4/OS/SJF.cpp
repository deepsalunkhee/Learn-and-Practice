#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;

struct ProcessControlBlock
{
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

bool compare_by_arrival_time(const ProcessControlBlock& a, const ProcessControlBlock& b)
{
    return a.arrival_time < b.arrival_time;
}

bool compare_by_burst_time(const ProcessControlBlock& a, const ProcessControlBlock& b)
{
    return a.burst_time < b.burst_time;
}

void sjf(vector<ProcessControlBlock>& processes)
{
    // Sort processes by arrival time
   sort(processes.begin(), processes.end(), compare_by_arrival_time);
    
    int n = processes.size();
    vector<bool> completed(n, false);
    int current_time = 0;
    int completed_processes = 0;
    vector<ProcessControlBlock> result;
    
    while (completed_processes < n) {
        int next_process_index = -1;
        int shortest_burst_time = INT_MAX;
        
        // Find the process with the shortest burst time among the arrived processes
        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].arrival_time <= current_time && processes[i].burst_time < shortest_burst_time) {
                next_process_index = i;
                shortest_burst_time = processes[i].burst_time;
            }
        }
        
        // If no process is found, wait until the next process arrives
        if (next_process_index == -1) {
            current_time = processes[0].arrival_time;
            continue;
        }
        
        // Update current time and completion time for the selected process
        current_time += processes[next_process_index].burst_time;
        processes[next_process_index].completion_time = current_time;
        processes[next_process_index].turnaround_time = processes[next_process_index].completion_time - processes[next_process_index].arrival_time;
        processes[next_process_index].waiting_time = processes[next_process_index].turnaround_time - processes[next_process_index].burst_time;
        
        // Mark the process as completed and add it to the result vector
        completed[next_process_index] = true;
        result.push_back(processes[next_process_index]);
        completed_processes++;
    }
    
    // Print the result
    cout << "PID\tBT\tAT\tCT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << result[i].pid << "\t" << result[i].burst_time << "\t" << result[i].arrival_time << "\t" << result[i].completion_time << "\t" << result[i].waiting_time << "\t" << result[i].turnaround_time << "\n";
    }
}

int main()
{
    // Get input from user
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    
    vector<ProcessControlBlock> processes(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Enter the burst time and arrival time for process " << i+1 << ": ";
        cin >> processes[i].burst_time >> processes[i].arrival_time;
        processes[i].pid = i+1;
    }
    
    // Run SJF algorithm
    sjf(processes);
    
    return 0;
}
