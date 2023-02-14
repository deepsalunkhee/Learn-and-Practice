#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct ProcessControlBlock
{
    int pid;
    int BT;
    int AT;
    int CT;
    int waitingtime;
    int TAT;
    int remainingtime;
    int FBT;
};

// Comparator functions for sorting the processes based on arrival time, burst time, and remaining time
bool sortByArrival(const ProcessControlBlock& a, const ProcessControlBlock& b)
{
    return a.AT < b.AT;
}

bool sortByBurst(const ProcessControlBlock& a, const ProcessControlBlock& b)
{
    return a.BT < b.BT;
}

bool sortByRemaining(const ProcessControlBlock& a, const ProcessControlBlock& b)
{
    return a.FBT < b.FBT;
}

int main()
{
    // Initialize variables
    int clock = 0;
    int index = 0;
    int noOfProcess;
    cout << "Enter the number of processes: ";
    cin >> noOfProcess;
    cout << endl;

    // Create a vector to store the process control blocks
    vector<ProcessControlBlock> PCB(noOfProcess);

    // Read the process details from the user
    for (int i = 0; i < noOfProcess; i++)
    {
        cout << "Enter the process ID for process " << i+1 << ": ";
        cin >> PCB[i].pid;
        cout << "Enter the burst time for process " << i+1 << ": ";
        cin >> PCB[i].BT;
        PCB[i].FBT = PCB[i].BT;
        cout << "Enter the arrival time for process " << i+1 << ": ";
        cin >> PCB[i].AT;
        cout << endl;
    }

    // Sort the processes based on their arrival time
    sort(PCB.begin(), PCB.end(), sortByArrival);

    // Create a vector to store the finished processes
    vector<ProcessControlBlock> ans;

    // Create a queue to store the running process
    queue<ProcessControlBlock> running;

    // Create a vector to store the arrived processes
    vector<ProcessControlBlock> arrived;

    int envruntime;
    cout << "Enter the duration for which the environment should run: ";
    cin >> envruntime;

    // Main loop to simulate the SRTN scheduling algorithm
    while (clock < envruntime || !arrived.empty() || !running.empty())
    {
        // Add the arrived processes to the queue
        while (!PCB.empty() && PCB.back().AT <= clock)
        {
            arrived.push_back(PCB.back());
            PCB.pop_back();
        }

        // Sort the arrived processes based on their remaining time
        sort(arrived.begin(), arrived.end(), sortByRemaining);

        // Add the process with the smallest remaining time to the running queue
        if (running.empty() && !arrived.empty())
        {
            running.push(arrived.front());
            // arrived.erase(arrived.begin());
        }

        // if(!running.empty()&&running.front().FBT>arrived[0].FBT && !arrived.empty())
		// {
		// 	running.pop();
		// 	running.push(arrived[0]);
			
		// }

        // Update the running process and check if it has finished
        if (!running.empty())
        {   running.front().FBT--;
            arrived.front().FBT--;
            
            if(running.front().FBT>arrived[0].FBT)
            {
                running.pop();
		    	running.push(arrived[0]);
            }
            
            if (running.front().FBT == 0)
            {
                ans.push_back(running.front());
                ans.back().CT = clock;
                cout<<clock<<endl;
                ans.back().TAT = ans.back().CT - ans.back().AT;
                ans.back().waitingtime = ans.back().TAT - ans.back().BT;
                running.pop();
                arrived.erase(arrived.begin());
                clock--;
            }
        }

        clock++;
        
        // running.front().FBT--;
        //     arrived.front().FBT--;
    }

    // Sort the
    sort(ans.begin(),ans.end(),sortByArrival);

        cout << "\tSRTN" << endl;
    cout << "PID\tBT\tAT\tWT" << endl;

    for(int i = 0; i < noOfProcess; i++)
    {
        cout << ans[i].pid << "\t" << ans[i].BT << "\t" << ans[i].AT << "\t" << ans[i].waitingtime <<"\t"<< ans[i].CT<<endl;
    }

    return 0;
}
