#include <iostream>
// code chef first contest
using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	
	for(int j=1;j<=n;j++)
	{
	    int a,b,c,d;
	    cin>>a>>b>>c>>d;
	    
	    if (a>b)
	    {
	        if(c>d)
	        {
	            cout<<a+c<<endl;
	        }
	        
	        else
	        {
	            cout<<a+d<<endl;
	        }
	    }
	    else
	    {
	       if(c>d)
	        {
	            cout<<b+c<<endl;
	        }
	        
	        else
	        {
	            cout<<b+d<<endl;
	        } 
	    }
	}
	return 0;
}
