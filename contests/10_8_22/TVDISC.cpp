#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	
	for(int j=1;j<=n;j++)
	{
	    int a,b,c,d;
	    cin>>a>>b>>c>>d;
	    if((a-c)<(b-d))
	    {
	        cout<<"First"<<endl;
	    }
	    else if((a-c)>(b-d))
	    {
	         cout<<"Second"<<endl;
	    }
	    else
	    {
	        cout<<"Any"<<endl;
	    }
	}
	return 0;
}
