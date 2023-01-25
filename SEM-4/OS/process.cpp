#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

struct ProcessControlBlock
{
	int pid=0;
	int BT=0;
	int AT=0;
};


vector<ProcessControlBlock>PCB;
queue<ProcessControlBlock>Active;

 
int main()
{
	int time=0;
	int noOfProcess;
	cout<<"Enter the number of the process"<<endl;
	cin>>noOfProcess;
	int n=noOfProcess;
	
	for(int i=0;i<n;i++)
	{
		ProcessControlBlock dummy;
		cout<<"Enter the pid of process of"<<i+1<<endl;
		cin>>dummy.pid;
		cout<<"Enter the busrt time of "<<i+1<<endl;
		cin>>dummy.BT;
		cout<<"Enter the arrival time of "<<i+1<<endl;
		cin>>dummy.AT;
		PCB.push_back(dummy);
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<PCB[i].pid<<endl;
		cout<<PCB[i].BT<<endl;
		cout<<PCB[i].AT<<endl;
	}
	
	while(n>0)
	{
		
	}
	
	
	
	
	
   
}

