#include <iostream>
using namespace std;

int main() 
{
    int n,T,X,Y,Z;
    cin>>T;
	for(n=1;n<=T;n++)
	{
	    cin>>X>>Y>>Z;
	    if(X+2*Z>=Y)
	    {
	        cout<<"Yes"<<endl;
	    }
	    else
	    {
	        cout<<"No"<<endl;
	    }
	}
	return 0;
}