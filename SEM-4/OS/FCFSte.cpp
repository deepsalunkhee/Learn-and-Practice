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
    int FBT;
	int TAT;
    char type;
};

vector<ProcessControlBlock> PCB;

	queue<ProcessControlBlock> running;
    vector<ProcessControlBlock> ans;
    vector<ProcessControlBlock> Active;
    vector<ProcessControlBlock>blocked;
int sortByarrival(ProcessControlBlock a, ProcessControlBlock b)
{
	if (a.AT < b.AT)
		return 1;
	else
		return 0;
}

int sortByburst(ProcessControlBlock a, ProcessControlBlock b)
{
	if (a.BT < b.BT)
		return 1;
	else
		return 0;
}

int main()
{

	

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
		cout << "Enter the Arrival Time " << i + 1 << "\t";
		cin >> dummy.AT;
		cout << endl;
		PCB.push_back(dummy);
	}

	//--------------------------------------------Logic for FCFS----------------------------------------//

    sort(PCB.begin(), PCB.end(), sortByarrival);
    for(int i=0;i<n;i++)
    {
        PCB[i].FBT=PCB[i].BT;
    }

    int envActiveFor1;
    int time1 = 0;
    int currentpcb1 = 0;
    int qfront1 = 0;
    float wating1 = 0;
    float TurnAround = 0;
    int index=0;
    int clock = 0, pcbindex = 0;
    cout << "For FCFS for how much time the environment must be active "
         << "\t";
    cin >> envActiveFor1;
    while (envActiveFor1--)
    {
        while (time1 >= PCB[currentpcb1].AT)
        {
            
            Active.push_back(PCB[currentpcb1]);

            currentpcb1 = currentpcb1 + 1;

            
        }

        

        if(running.empty())
        {   if(!blocked.empty())
            {
            running.push(blocked[0]);
            blocked.erase(blocked.begin()+0);
            }
            else
            {
                running.push(Active[0]);
                Active.erase(Active.begin()+0);
            }
            
        }
        if (running.front().FBT == 0)
        {
            ans.push_back(running.front());
            
            ans[index].waitingtime=time1-ans[index].BT-ans[index].AT;
            ans[index].CT=time1;
            ans[index].TAT=time1-ans[index].AT;
            cout<<time1<<endl;
            index=index+1;
			running.pop();
		
            
        }
        
        while(!Active.empty()&& (Active[0].type =='b') && Active[0].AT<=time1)
        {
            ProcessControlBlock temp =running.front();
            if(running.front().type=='p')
            {
                running.pop();
                blocked.push_back(temp);

            }
            
            running.push(Active[0]);
           
            Active.erase(Active.begin()+0);
            
        }
        running.front().FBT--;
        time1++;
        
        
    }

    cout << "\t\tFCFS" << endl;
    cout << "PID"
         << "\t"
         << "BT"
         << "\t"
         << "AT"
         << "\t"
         << "CT"
         << "\t"
         << "TAT"
         << "\t"
         << "WT" << endl;
   int avgTAT=0,avgWT=0;
   for(int i=0;i<n;i++)
	{
		
		 cout<<ans[i].pid<<" \t"<<ans[i].BT<<"  \t"<<ans[i].AT<<"  \t"<<ans[i].waitingtime<<"\t"<<ans[i].TAT<<endl;
         avgTAT=avgTAT+ans[i].TAT;
         avgWT=avgWT+ans[i].waitingtime;
		
	}

    cout << "Avg Waiting for FCFS:" << (float)(wating1 / n) << endl;
    cout << "Avg TAT for FCFS:    " << (float)(TurnAround / n) << endl;

	return 0;
}