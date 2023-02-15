#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct ProcessControlBlock
{
    int pid;
    int BT;
    int AT;
    int CT;
    int waitingtime;
    int TAT;
    int FBT;
};

vector<ProcessControlBlock> PCB;
vector<ProcessControlBlock> Arrived;
queue<ProcessControlBlock> running;
vector<ProcessControlBlock> ans;

int sortByarrival(ProcessControlBlock a, ProcessControlBlock b)
{
    if (a.AT < b.AT)
        return 1;
    else
        return 0;
}

int sortByRemaining(ProcessControlBlock a, ProcessControlBlock b)
{
    if (a.FBT < b.FBT)
        return 1;
    else
        return 0;
}

int main()
{
    int clock = 0, pcbindex = 0;

    int noOfProcess;
    cout << "ENTER THE NO. PROCESS =>"
         << "\t";
    cin >> noOfProcess;
    cout << endl;
    int n = noOfProcess;

    for (int i = 0; i < n; i++)
    {
        ProcessControlBlock dummy;
        cout << "Enter the pid          " << i + 1 << "\t";
        cin >> dummy.pid;
        cout << "Enter the Burst Time   " << i + 1 << "\t";
        cin >> dummy.BT;
        dummy.FBT = dummy.BT;
        cout << "Enter the Arrival Time " << i + 1 << "\t";
        cin >> dummy.AT;
        cout << endl;
        PCB.push_back(dummy);
        cout << PCB[i].AT << endl;
    }

    //----------------------------------------Logic for Round Robin----------------------------------------------------------//

    sort(PCB.begin(), PCB.end(), sortByarrival);

    int envruntime = 30;
    int inpcb = 0;
    int time = 0;
    int currBT = 0;
    int index = 0;
    int timequantum = 0;
    float avgTAT = 0;
    float avgWT = 0;
    int temp;
    cout << "Enter the Time quantum: ";
    cin >> timequantum;
    cout << "For how much time the env must be active: ";
    cin >> envruntime;

    while (envruntime)
    {
        while (time == PCB[inpcb].AT && inpcb < n)
        {
            Arrived.push_back(PCB[inpcb]);
            inpcb++;
        }

        if (running.empty() && !Arrived.empty())
        {
            running.push(Arrived[0]);
            Arrived.erase(Arrived.begin() + 0);
        }

        if (!running.empty())
        {
            running.front().FBT--;
            time++;

            if (running.front().FBT == 0)
            {
                ans.push_back(running.front());
                ans[index].CT = time;
                ans[index].TAT = time - ans[index].AT;
                ans[index].waitingtime = ans[index].TAT - ans[index].BT;
                index++;

                running.pop();
                if (!Arrived.empty())
                {
                    running.push(Arrived[0]);
                    Arrived.erase(Arrived.begin() + 0);
                }
            }
            else if (time % timequantum == 0)
            {
                ProcessControlBlock temp = running.front();
                running.pop();
                running.push(temp);
            }
        }

        envruntime--;
    }

    cout << "\t\tRound Robin" << endl;
    cout<<"\t\tSRTN"<<endl;
    cout<<"PID"<<"\t"<<"BT"<<"\t"<<"AT"<<"\t"<<"WT"<<"\t"<<"TAT"<<"\t"<<"CT"<<endl;
	
	for(int i=0;i<n;i++)
	{
		
		 cout<<ans[i].pid<<" \t"<<ans[i].BT<<"  \t"<<ans[i].AT<<"  \t"<<ans[i].waitingtime<<"\t"<<ans[i].TAT<<"\t"<<ans[i].CT<<endl;
         avgTAT=avgTAT+ans[i].TAT;
         avgWT=avgWT+ans[i].waitingtime;
		
	}
	cout << "Avg Waiting for FCFS:" << (avgWT/ n) << endl;
	cout << "Avg TAT for FCFS:    " << (avgTAT/ n) << endl;

	
	
	return 0;
	
   
}
