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




vector<ProcessControlBlock>PCB;
vector<ProcessControlBlock>Arrived;
queue<ProcessControlBlock>running;
vector<ProcessControlBlock>ans;

int sortByarrival(ProcessControlBlock a , ProcessControlBlock b)
{
	if(a.AT < b.AT)
		return 1;
	else 
		return 0;
}

int sortByburst(ProcessControlBlock a , ProcessControlBlock b)
{
	if(a.BT < b.BT)
		return 1;
	else 
		return 0;
}

int sortByRemaining(ProcessControlBlock a , ProcessControlBlock b)
{
	if(a.FBT < b.FBT)
		return 1;
	else 
		return 0;
}
 
int main()
{

    int clock=0,pcbindex=0;
	
	int noOfProcess;
	cout<<"ENTER THE NO. PROCESS =>"<<"\t";
	cin>>noOfProcess;
	cout<<endl;
	int n=noOfProcess;
	
	for(int i=0;i<n;i++)
	{
		ProcessControlBlock dummy;
		cout<<"Enter the pid          "<<i+1<<"\t";
		cin>>dummy.pid;
		cout<<"Enter the Burst Time   "<<i+1<<"\t";
		cin>>dummy.BT;
		dummy.FBT=dummy.BT;
		cout<<"Enter the Arrival Time "<<i+1<<"\t";
		cin>>dummy.AT;
		cout<<endl;
		PCB.push_back(dummy);
	}



	

	//----------------------------------------Logic for SJF----------------------------------------------------------//

	sort(PCB.begin(),PCB.end(),sortByarrival);

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
            sort(Arrived.begin(),Arrived.end(),sortByburst);
            
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

	
	
	return 0;
	
   
}