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
	int waitingtime;
	
};




vector<ProcessControlBlock>PCB;
queue<ProcessControlBlock>Active;
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
 
int main()
{

    int clock=0,pcbindex=0;
	int time=0;
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
		cout<<"Enter the Arrival Time "<<i+1<<"\t";
		cin>>dummy.AT;
		cout<<endl;
		PCB.push_back(dummy);
	}



	//--------------------------------------------Logic for FCFS----------------------------------------//
	

    sort(PCB.begin(),PCB.end(),sortByarrival);
    
   

	while(1)
	{
		while(Active.empty())
		{
			if(PCB[pcbindex].AT==clock)
			{
				Active.push(PCB[pcbindex]);
				
				break;
			}
			clock++;
		}

        
		
		if(Active.front().BT==0)
		{
			PCB[pcbindex].waitingtime=clock-PCB[pcbindex].BT-PCB[pcbindex].AT;
			pcbindex=pcbindex+1;
			Active.pop();
			if(PCB[pcbindex].AT<=clock )
			{
				
				Active.push(PCB[pcbindex]);
			}
		}
		
		clock++;
		Active.front().BT--;

		
		if(Active.empty())
		break;
	}
    
    cout<<"\t\tFCFS"<<endl;
    cout<<"PID"<<"\t"<<"BT"<<"\t"<<"AT"<<"\t"<<"WT"<<endl;
	
	for(int i=0;i<n;i++)
	{
		
		 cout<<PCB[i].pid<<" \t"<<PCB[i].BT<<"  \t"<<PCB[i].AT<<"  \t"<<PCB[i].waitingtime<<endl;
		
	}

	//----------------------------------------Logic for SJF----------------------------------------------------------//

	sort(PCB.begin(),PCB.end(),sortByburst);


	 cout<<"\t\tFCFS"<<endl;
    cout<<"PID"<<"\t"<<"BT"<<"\t"<<"AT"<<"\t"<<"WT"<<endl;
	
	for(int i=0;i<n;i++)
	{
		
		 cout<<PCB[i].pid<<" \t"<<PCB[i].BT<<"  \t"<<PCB[i].AT<<"  \t"<<PCB[i].waitingtime<<endl;
		
	}
	

	
	
	
	
	
   
}

