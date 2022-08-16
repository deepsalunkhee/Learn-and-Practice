#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	
	for(int j=1;j<=n;j++)
	{
	    int x,y,z;
	    cin>>x>>y>>z;
	    cout<<x-y+z<<endl;
	}
	return 0;
}
