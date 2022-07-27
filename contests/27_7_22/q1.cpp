#include <iostream>

// code chef first contest
using namespace std;

int main()
{
	// your code goes here
	int n;
	cin>>n;
	
	
	for (int i=1;i<=n;i++)
	{
	int t;
	cin>>t;
	
	if(t>20)
	{
	    cout<<"HOT"<<endl;
	}
	else
	{
	    cout<<"COLD"<<endl;
	}
	}
	return 0;
}