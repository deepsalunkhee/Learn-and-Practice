// #include <iostream>
// #include <list>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include<stack>
// using namespace std;

// struct ProcessControlBlock
// {
//     int pid;
//     int BT;
//     int AT;
//     int CT;
//     int waitingtime;
//     int TAT;

//     int FBT;
//     char type;
// };

//  vector<ProcessControlBlock> PCB(3);
//  int n;

// int sortByarrival(ProcessControlBlock a, ProcessControlBlock b)
// {
//     if (a.AT < b.AT)
//         return 1;
//     else
//         return 0;
// }

// int sortByburst(ProcessControlBlock a, ProcessControlBlock b)
// {
//     if (a.BT < b.BT)
//         return 1;
//     else
//         return 0;
// }

// int sortByRemaining(ProcessControlBlock a, ProcessControlBlock b)
// {
//     if (a.FBT < b.FBT)
//         return 1;
//     else
//         return 0;
// }

// void FCFS()
// {
    
//     queue<ProcessControlBlock> running;
//     vector<ProcessControlBlock> ans;
//     vector<ProcessControlBlock> Active;
//     vector<ProcessControlBlock>blocked;
//     sort(PCB.begin(), PCB.end(), sortByarrival);
//     for(int i=0;i<n;i++)
//     {
//         PCB[i].FBT=PCB[i].BT;
//     }

//     int envActiveFor1=10;
//     int time1 = 0;
//     int currentpcb1 = 0;
//     int qfront1 = 0;
//     float wating1 = 0;
//     float TurnAround = 0;
//     int index=0;
//     int clock = 0, pcbindex = 0;
//     // cout << "For FCFS for how much time the environment must be active "
//     //      << "\t";
//     // cin >> envActiveFor1;
//     while (envActiveFor1--)
//     {
//         while (time1 >= PCB[currentpcb1].AT)
//         {
            
//             Active.push_back(PCB[currentpcb1]);

//             currentpcb1 = currentpcb1 + 1;

            
//         }

        

//         if(running.empty())
//         {   if(!blocked.empty())
//             {
//             running.push(blocked[0]);
//             blocked.erase(blocked.begin()+0);
            
//             }
//             else
//             {
//                 running.push(Active[0]);
//                 Active.erase(Active.begin()+0);
           
//             }
            
//         }
//         if (running.front().FBT == 0)
//         {
//             ans.push_back(running.front());
            
//             ans[index].waitingtime=time1-ans[index].BT-ans[index].AT;
//             ans[index].CT=time1;
//             ans[index].TAT=time1-ans[index].AT;
//             // cout<<time1<<endl;
//             index=index+1;
// 			running.pop();
		
            
//         }
        
//         // while( !Active.empty() && (Active[0].type =='b') && Active[0].AT==time1&& running.front().type=='p')
//         // {
           
           
                
            
           
//         //     running.pop();
//         //     blocked.push_back(running.front());
            
            
            
//         //     running.push(Active[0]);
            
//         //     Active.erase(Active.begin()+0);
//         //     // cout<<"chu"<<endl;
            
            
//         // }

//         if(running.front().type=='p')
//         {
//             while(Active[0].type=='b')
//             {
//                 running.push(Active[0]);
//                 Active.erase(Active.begin()+0);
//             }
//             blocked.push_back(running.front());
//             running.pop();
//         }
        
//        cout<<"pid "<< running.front().pid<<endl;
//        cout<<time1<<endl;

//         time1++;
//         running.front().FBT--;
        
//     }

//     cout << "\t\tFCFS" << endl;
//     cout << "PID"
//          << "\t"
//          << "BT"
//          << "\t"
//          << "AT"
//          << "\t"
//          << "CT"
//          << "\t"
//          << "TAT"
//          << "\t"
//          << "WT" << endl;
//    int avgTAT=0,avgWT=0;
//    for(int i=0;i<n;i++)
// 	{
		
// 		 cout<<ans[i].pid<<" \t"<<ans[i].BT<<"  \t"<<ans[i].AT<<"  \t"<<ans[i].waitingtime<<"\t"<<ans[i].TAT<<endl;
//          avgTAT=avgTAT+ans[i].TAT;
//          avgWT=avgWT+ans[i].waitingtime;
		
// 	}

//     cout << "Avg Waiting for FCFS:" << (float)(wating1 / n) << endl;
//     cout << "Avg TAT for FCFS:    " << (float)(TurnAround / n) << endl;
// }

// void SJF()
// {
//     vector<ProcessControlBlock> Arrived;
//     queue<ProcessControlBlock> running;
//     vector<ProcessControlBlock> ans;
//     vector<ProcessControlBlock> Active;
//      sort(PCB.begin(),PCB.end(),sortByarrival);
//     for(int i=0;i<n;i++)
//     {
//         PCB[i].FBT=PCB[i].BT;
//     }
//     int envruntime=30;
//     int inpcb=0;
//     int time=0;
//     int currBT=0;
//     int index=0;
//     float avgTAT=0;
//     float avgWT=0;
//     cout<<"For how much time the env must be active";
// //    cin>>envruntime;

//     while(envruntime--)
//     {
    
    	
//     	 while(time==PCB[inpcb].AT)
//         {
//             Arrived.push_back(PCB[inpcb]);
//             inpcb++;
//             sort(Arrived.begin(),Arrived.end(),sortByburst);
            
//         }
//         if(running.empty() && !Arrived.empty())
//         {
//             // cout<<Arrived.size()<<endl;
//         	running.push(Arrived[0]);
//            cout<< Arrived[0].pid<<endl;;
//             Arrived.erase(Arrived.begin()+0);
// 		}
// 		// if(running.front().FBT>Arrived[0].FBT)
// 		// {
// 		// 	running.pop();
// 		// 	running.push(Arrived[0]);
			
// 		// }
// 		if(running.front().FBT==0)
// 		{
// 		ans.push_back(running.front());
            
//             ans[index].waitingtime=time-ans[index].BT-ans[index].AT;
//             ans[index].CT=time;
//             ans[index].TAT=time-ans[index].AT;
//             // cout<<time<<endl;
//             index=index+1;
// 			running.pop();
			
//             // cout<<Arrived.size()<<endl;
// 			time--;
// 		}



//         // cout<<time<<endl;
//         time++;
//         running.front().FBT--;
       
    
//     }
	
//      cout<<"\t\tSJF"<<endl;
//     cout<<"PID"<<"\t"<<"BT"<<"\t"<<"AT"<<"\t"<<"WT"<<"\t"<<"TAT"<<endl;
	
// 	for(int i=0;i<n;i++)
// 	{
		
// 		 cout<<ans[i].pid<<" \t"<<ans[i].BT<<"  \t"<<ans[i].AT<<"  \t"<<ans[i].waitingtime<<"\t"<<ans[i].TAT<<endl;
//          avgTAT=avgTAT+ans[i].TAT;
//          avgWT=avgWT+ans[i].waitingtime;
		
// 	}
// 	cout << "Avg Waiting for FCFS:" << (avgWT/ n) << endl;
// 	cout << "Avg TAT for FCFS:    " << (avgTAT/ n) << endl;
// }

// void SRTN()
// {

//     vector<ProcessControlBlock> Arrived;
//     queue<ProcessControlBlock> running;
//     vector<ProcessControlBlock> ans;
//     vector<ProcessControlBlock> Active;
//     sort(PCB.begin(),PCB.end(),sortByarrival);
//     for(int i=0;i<n;i++)
//     {
//         PCB[i].FBT=PCB[i].BT;
//     }
//     int envruntime=30;
//     int inpcb=0;
//     int time=0;
//     int currBT=0;
//     int index=0;
//     float avgTAT=0;
//     float avgWT=0;
//     cout<<"For how much time the env must be active";
// //    cin>>envruntime;

//     while(envruntime--)
//     {
    
    	
//     	 while(time==PCB[inpcb].AT)
//         {
//             Arrived.push_back(PCB[inpcb]);
//             inpcb++;
//             sort(Arrived.begin(),Arrived.end(),sortByRemaining);
            
//         }
//         if(running.empty())
//         {
//             cout<<Arrived.size()<<endl;
//         	running.push(Arrived[0]);
// 		}
// 		if(running.front().FBT>Arrived[0].FBT)
// 		{
// 			running.pop();
// 			running.push(Arrived[0]);
			
// 		}
// 		if(running.front().FBT==0)
// 		{
// 		ans.push_back(running.front());
            
//             ans[index].waitingtime=time-ans[index].BT-ans[index].AT;
//             ans[index].CT=time;
//             ans[index].TAT=time-ans[index].AT;
//             cout<<time<<endl;
//             index=index+1;
// 			running.pop();
// 			Arrived.erase(Arrived.begin()+0);
//             cout<<Arrived.size()<<endl;
// 			// time--;
// 		}
        


//         cout<<time<<endl;
//         time++;
//         running.front().FBT--;
//         Arrived[0].FBT--;
    
//     }
	
//      cout<<"\t\tSRTN"<<endl;
//     cout<<"PID"<<"\t"<<"BT"<<"\t"<<"AT"<<"\t"<<"WT"<<"\t"<<"TAT"<<endl;
	
// 	for(int i=0;i<n;i++)
// 	{
		
// 		 cout<<ans[i].pid<<" \t"<<ans[i].BT<<"  \t"<<ans[i].AT<<"  \t"<<ans[i].waitingtime<<"\t"<<ans[i].TAT<<endl;
//          avgTAT=avgTAT+ans[i].TAT;
//          avgWT=avgWT+ans[i].waitingtime;
		
// 	}
// 	cout << "Avg Waiting for FCFS:" << (avgWT/ n) << endl;
// 	cout << "Avg TAT for FCFS:    " << (avgTAT/ n) << endl;


	
// }

// void RR()
// {

//      vector<ProcessControlBlock> Arrived;
//     queue<ProcessControlBlock> running;
//     vector<ProcessControlBlock> ans;
//     vector<ProcessControlBlock> Active;
//      sort(PCB.begin(), PCB.end(), sortByarrival);
//   for(int i=0;i<n;i++)
//     {
//         PCB[i].FBT=PCB[i].BT;
//     }
//     int envruntime = 30;
//     int inpcb = 0;
//     int time = 0;
//     int currBT = 0;
//     int index = 0;
//     int timequantum = 0;
//     float avgTAT = 0;
//     float avgWT = 0;
//     int temp;
//     cout << "Enter the Time quantum: ";
//     // cin >> timequantum;
//     cout << "For how much time the env must be active: ";
//     // cin >> envruntime;

//     while (envruntime)
//     {
//         while (time == PCB[inpcb].AT && inpcb < n)
//         {
//             Arrived.push_back(PCB[inpcb]);
//             inpcb++;
//         }

//         if (running.empty() && !Arrived.empty())
//         {
//             running.push(Arrived[0]);
//             Arrived.erase(Arrived.begin() + 0);
//         }

//         if (!running.empty())
//         {
//             running.front().FBT--;
//             time++;

//             if (running.front().FBT == 0)
//             {
//                 ans.push_back(running.front());
//                 ans[index].CT = time;
//                 ans[index].TAT = time - ans[index].AT;
//                 ans[index].waitingtime = ans[index].TAT - ans[index].BT;
//                 index++;
//                 // cout << time << "c" << endl;

//                 // for (int i = 0; i < Arrived.size(); i++)
//                 // {

//                 //     cout << Arrived[i].pid << endl;
//                 // }

//                 running.pop();
//                 if (!Arrived.empty())
//                 {
//                     running.push(Arrived[0]);
//                     Arrived.erase(Arrived.begin() + 0);
//                     // cout<<running.front().FBT<<endl;
//                 }
//                 //  time++;
//             }
//             else if (time % timequantum == 0)
//             {
//                 while (time == PCB[inpcb].AT && inpcb < n)
//                 {
//                     Arrived.push_back(PCB[inpcb]);

//                     inpcb++;
//                 }
//                 ProcessControlBlock temp = running.front();
//                 running.pop();
//                 Arrived.push_back(temp);
//                 // cout << time << "p" << endl;
//                 // time--;
//             }
//         }

//         envruntime--;
//     }

//     // sort(ans.begin(),ans.end(),sortByarrival);

//     cout << "\t\tRound Robin" << endl;
//     cout << "PID"
//          << "\t"
//          << "BT"
//          << "\t"
//          << "AT"
//          << "\t"
//          << "WT"
//          << "\t"
//          << "TAT"
//          << "\t"
//          << "CT" << endl;

//     for (int i = 0; i < n; i++)
//     {

//         cout << ans[i].pid << " \t" << ans[i].BT << "  \t" << ans[i].AT << "  \t" << ans[i].waitingtime << "\t" << ans[i].TAT << "\t" << ans[i].CT << endl;
//         avgTAT = avgTAT + ans[i].TAT;
//         avgWT = avgWT + ans[i].waitingtime;
//     }
//     cout << "Avg Waiting for FCFS:" << (avgWT / n) << endl;
//     cout << "Avg TAT for FCFS:    " << (avgTAT / n) << endl;
// }

// int main()
// {

//     int noOfProcess;
//     cout << "ENTER THE NO. PROCESS =>"
//          << "\t";
//     // cin >> noOfProcess;
//     cout << endl;
//      n = noOfProcess;
//     // vector<ProcessControlBlock> PCB;

//     // for (int i = 0; i < n; i++)
//     // {
//     //     ProcessControlBlock dummy;
//     //     cout << "Enter the pid          " << i + 1 << "\t";
//     //     cin >> dummy.pid;
//     //     cout << "Enter the Burst Time   " << i + 1 << "\t";
//     //     cin >> dummy.BT;
//     //     cout << "Enter the Arrival Time " << i + 1 << "\t";
//     //     cin >> dummy.AT;
//     //     cout << "Enter the type " << i + 1 << "\t";
//     //     cin>>dummy.type;
//     //     cout << endl;
//     //     PCB.push_back(dummy);
//     // }
//       PCB[0].pid=1;
//       PCB[0].BT=3;
//       PCB[0].AT=0;
//       PCB[0].type='p';
//       PCB[1].pid=2;
//       PCB[1].BT=2;
//       PCB[1].AT=1;
//       PCB[1].type='b';
//       PCB[2].pid=3;
//       PCB[2].BT=2;
//       PCB[2].AT=1;
//       PCB[2].type='b';
//       n=3;
//     while (1)
//     {
//         cout << "Select the shedulilng algorithm" << endl;
//         cout << "1:FCFS" << endl;
//         cout << "2:SJF" << endl;
//         cout << "3:SRTN" << endl;
//         cout << "4:RR" << endl;
//         cout << "5:Exit" << endl;
//         cout << "Your Choice" << endl;
//         int choice;
//         // cin >> choice;
//         choice=1;
//         switch (choice)
//         {
//         case 1:
//             FCFS();
//              return 0;
//             break;
//         case 2:
//             SJF();
//             break;
//         case 3:
//             SRTN();
//             break;
//         case 4:
//             RR();
//             break;
//         case 5:
//             return 0;

//         default:
//             cout << "Invalid input" << endl;
//              return 0;
//         }
//     }

// }

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

void FCFS()
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

void SJF()
{
    vector<ProcessControlBlock> Arrived;
    queue<ProcessControlBlock> running;
    vector<ProcessControlBlock> ans;
    vector<ProcessControlBlock> Active;
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
}

void SRTN()
{

    vector<ProcessControlBlock> Arrived;
    queue<ProcessControlBlock> running;
    vector<ProcessControlBlock> ans;
    vector<ProcessControlBlock> Active;
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
            sort(Arrived.begin(),Arrived.end(),sortByRemaining);
            
        }
        if(running.empty())
        {
            cout<<Arrived.size()<<endl;
        	running.push(Arrived[0]);
		}
		if(running.front().FBT>Arrived[0].FBT)
		{
			running.pop();
			running.push(Arrived[0]);
			
		}
		if(running.front().FBT==0)
		{
		ans.push_back(running.front());
            
            ans[index].waitingtime=time-ans[index].BT-ans[index].AT;
            ans[index].CT=time;
            ans[index].TAT=time-ans[index].AT;
            cout<<time<<endl;
            index=index+1;
			running.pop();
			Arrived.erase(Arrived.begin()+0);
            cout<<Arrived.size()<<endl;
			// time--;
		}
        


        cout<<time<<endl;
        time++;
        running.front().FBT--;
        Arrived[0].FBT--;
    
    }
	
     cout<<"\t\tSRTN"<<endl;
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

void RR()
{

     vector<ProcessControlBlock> Arrived;
    queue<ProcessControlBlock> running;
    vector<ProcessControlBlock> ans;
    vector<ProcessControlBlock> Active;
     sort(PCB.begin(), PCB.end(), sortByarrival);
  for(int i=0;i<n;i++)
    {
        PCB[i].FBT=PCB[i].BT;
    }
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
                // cout << time << "c" << endl;

                // for (int i = 0; i < Arrived.size(); i++)
                // {

                //     cout << Arrived[i].pid << endl;
                // }

                running.pop();
                if (!Arrived.empty())
                {
                    running.push(Arrived[0]);
                    Arrived.erase(Arrived.begin() + 0);
                    // cout<<running.front().FBT<<endl;
                }
                //  time++;
            }
            else if (time % timequantum == 0)
            {
                while (time == PCB[inpcb].AT && inpcb < n)
                {
                    Arrived.push_back(PCB[inpcb]);

                    inpcb++;
                }
                ProcessControlBlock temp = running.front();
                running.pop();
                Arrived.push_back(temp);
                // cout << time << "p" << endl;
                // time--;
            }
        }

        envruntime--;
    }

    // sort(ans.begin(),ans.end(),sortByarrival);

    cout << "\t\tRound Robin" << endl;
    cout << "PID"
         << "\t"
         << "BT"
         << "\t"
         << "AT"
         << "\t"
         << "WT"
         << "\t"
         << "TAT"
         << "\t"
         << "CT" << endl;

    for (int i = 0; i < n; i++)
    {

        cout << ans[i].pid << " \t" << ans[i].BT << "  \t" << ans[i].AT << "  \t" << ans[i].waitingtime << "\t" << ans[i].TAT << "\t" << ans[i].CT << endl;
        avgTAT = avgTAT + ans[i].TAT;
        avgWT = avgWT + ans[i].waitingtime;
    }
    cout << "Avg Waiting for FCFS:" << (avgWT / n) << endl;
    cout << "Avg TAT for FCFS:    " << (avgTAT / n) << endl;
}

int main()
{

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
            FCFS();
            break;
        case 2:
            SJF();
            break;
        case 3:
            SRTN();
            break;
        case 4:
            RR();
            break;
        case 5:
            return 0;

        default:
            cout << "Invalid input" << endl;
        }
    }

}