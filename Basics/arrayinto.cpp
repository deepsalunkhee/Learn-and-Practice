#include<iostream>
using namespace std;
#include<climits>
int main()
{
    int n;
    
    cout<<"entre n:";
    cin>>n;
    int array[n];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>array[i];
    }
     for(i=0;i<n;i++)
     {
    int MAXno;
     int MINno;
     MAXno=INT_MIN;
     MINno=INT_MAX;
     MAXno=max(MAXno,array[i]);
     MINno=min(MINno,array[i]);
     
     cout<<MAXno<<endl;
     cout<<MINno<<endl;

     }
     cout<<array[n];
     return 0;

}  
