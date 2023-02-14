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
    int FBT; // FBT = First Burst Time
};

vector<ProcessControlBlock> PCB;
vector<ProcessControlBlock> Arrived;
queue<ProcessControlBlock> running;
vector<ProcessControlBlock> ans;

bool sortByarrival(ProcessControlBlock a, ProcessControlBlock b) {
    return a.AT < b.AT;
}

bool sortByburst(ProcessControlBlock a, ProcessControlBlock b) {
    return a.BT < b.BT;
}

bool sortByRemaining(ProcessControlBlock a, ProcessControlBlock b) {
    return a.FBT < b.FBT;
}

int main()
{
    int clock = 0, pcbindex = 0;

    int noOfProcess;
    cout << "Enter the number of processes: ";
    cin >> noOfProcess;
    cout << endl;

    for(int i = 0; i < noOfProcess; i++)
    {
        ProcessControlBlock pcb;
        cout << "Enter the pid: ";
        cin >> pcb.pid;
        cout << "Enter the burst time: ";
        cin >> pcb.BT;
        pcb.FBT = pcb.BT;
        cout << "Enter the arrival time: ";
        cin >> pcb.AT;
        cout << endl;
        PCB.push_back(pcb);
    }

    sort(PCB.begin(), PCB.end(), sortByarrival);

    int envruntime = 30;
    int time = 0;
    int index = 0;

    cout << "Enter the duration of the environment: ";
    cin >> envruntime;
    cout << endl;

    while(envruntime--)
    {
        if(time == PCB[pcbindex].AT)
        {
            Arrived.push_back(PCB[pcbindex]);
            pcbindex++;
            sort(Arrived.begin(), Arrived.end(), sortByRemaining);
        }

        if(running.empty() && !Arrived.empty())
        {
            running.push(Arrived[0]);
        }

        if(!running.empty() && !Arrived.empty() && running.front().FBT > Arrived[0].FBT)
        {
            running.push(Arrived[0]);
            Arrived.erase(Arrived.begin());
            sort(Arrived.begin(), Arrived.end(), sortByRemaining);
        }

        if(!running.empty())
        {
            running.front().FBT--;

            if(running.front().FBT == 0)
            {
                ans.push_back(running.front());
                ans[index].waitingtime = time - ans[index].BT - ans[index].AT;
                ans[index].CT = time;
                ans[index].TAT = time - ans[index].AT;
                index++;

                running.pop();

                if(!Arrived.empty())
                {
                    running.push(Arrived[0]);
                    Arrived.erase(Arrived.begin());
                    sort(Arrived.begin(), Arrived.end(), sortByRemaining);
                }
            }
        }

        time++;
    }

    cout << "\tSRTN" << endl;
    cout << "PID\tBT\tAT\tWT" << endl;

    for(int i = 0; i < noOfProcess; i++)
    {
        cout << ans[i].pid << "\t" << ans[i].BT << "\t" << ans[i].AT << "\t" << ans[i].waitingtime << endl;
    }

    return 0;
}
