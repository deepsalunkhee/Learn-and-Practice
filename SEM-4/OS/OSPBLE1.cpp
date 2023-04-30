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
    char type;
};

 vector<ProcessControlBlock> PCB;
 int n;

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

int sortByRemaining(ProcessControlBlock a, ProcessControlBlock b)
{
    if (a.FBT < b.FBT)
        return 1;
    else
        return 0;
}

void FCFS(vector<ProcessControlBlock> PCB, int n)
{
   vector<ProcessControlBlock> Arrived;
    queue<ProcessControlBlock> running;
    vector<ProcessControlBlock> ans;
    vector<ProcessControlBlock> Active;
    vector<ProcessControlBlock>blocked;
     sort(PCB.begin(),PCB.end(),sortByarrival);
    for(int i=0;i<n;i++)
    {
        PCB[i].FBT=PCB[i].BT;
    }
    int envruntime=30;
    int inpcb=0;
    int time=0;
    int currBT=0;
    int index=0;
    float avgTAT=0;
    float avgWT=0;
    cout<<"For how much time the env must be active";
   cin>>envruntime;

    while(envruntime--)
    {
    
    	
    	 while(time==PCB[inpcb].AT)
        {
            Arrived.push_back(PCB[inpcb]);
            inpcb++;
           
            
        }
        if(!blocked.empty())
        {
            running.push(blocked[0]);
           cout<< blocked[0].pid<<endl;;
            blocked.erase(blocked.begin()+0);
        }
        if(running.empty() && !Arrived.empty())
        {
            // cout<<Arrived.size()<<endl;
        	running.push(Arrived[0]);
           cout<< Arrived[0].pid<<endl;;
            Arrived.erase(Arrived.begin()+0);
		}
		// if(running.front().FBT>Arrived[0].FBT)
		// {
		// 	running.pop();
		// 	running.push(Arrived[0]);
			
		// }
		if(running.front().FBT==0)
		{
		ans.push_back(running.front());
            
            ans[index].waitingtime=time-ans[index].BT-ans[index].AT;
            ans[index].CT=time;
            ans[index].TAT=time-ans[index].AT;
            // cout<<time<<endl;
            index=index+1;
			running.pop();
			
            // cout<<Arrived.size()<<endl;
			time--;
		}
        while(!Arrived.empty() && Arrived[0].type=='b'&& Arrived[0].AT<=time)
        {
            blocked.push_back(running.front());
            running.pop();
            running.front()=Arrived[0];
             Arrived.erase(Arrived.begin()+0);
             cout<<running.front().pid<<endl;
        }



        // cout<<time<<endl;
        time++;
        running.front().FBT--;
       
    
    }
	
     cout<<"\t\tSJF"<<endl;
    cout<<"PID"<<"\t"<<"BT"<<"\t"<<"AT"<<"\t"<<"WT"<<"\t"<<"TAT"<<endl;
	
	for(int i=0;i<n;i++)
	{
		
		 cout<<ans[i].pid<<" \t"<<ans[i].BT<<"  \t"<<ans[i].AT<<"  \t"<<ans[i].waitingtime<<"\t"<<ans[i].TAT<<endl;
         avgTAT=avgTAT+ans[i].TAT;
         avgWT=avgWT+ans[i].waitingtime;
		
	}
	cout << "Avg Waiting for FCFS:" << (avgWT/ n) << endl;
	cout << "Avg TAT for FCFS:    " << (avgTAT/ n) << endl;
}

int main()
{
    vector<ProcessControlBlock> PCB;
    int n;

    int noOfProcess;
    cout << "ENTER THE NO. PROCESS =>"
         << "\t";
    cin >> noOfProcess;
    cout << endl;
     n = noOfProcess;
    // vector<ProcessControlBlock> PCB;

    for (int i = 0; i < n; i++)
    {
        ProcessControlBlock dummy;
        cout << "Enter the pid          " << i + 1 << "\t";
        cin >> dummy.pid;
        cout << "Enter the Burst Time   " << i + 1 << "\t";
        cin >> dummy.BT;
        cout << "Enter the Arrival Time " << i + 1 << "\t";
        cin >> dummy.AT;
        cout << "Enter the type" << i + 1 << "\t";
        cin>>dummy.type;
        cout << endl;
        PCB.push_back(dummy);
    }
    while (1)
    {
        cout << "Select the shedulilng algorithm" << endl;
        cout << "1:FCFS" << endl;
        cout << "2:SJF" << endl;
        cout << "3:SRTN" << endl;
        cout << "4:RR" << endl;
        cout << "5:Exit" << endl;
        cout << "Your Choice" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            FCFS(PCB,n);
            break;
        case 2:
            SJF(PCB,n);
            break;
        case 3:
            SRTN(PCB,n);
            break;
        case 4:
            RR(PCB,n);
            break;
        case 5:
            return 0;

        default:
            cout << "Invalid input" << endl;
        }
    }

}