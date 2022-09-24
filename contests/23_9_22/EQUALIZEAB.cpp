#include <iostream>
#include<math.h>
using namespace std;

void solution()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c==0)
        cout<<"NO"<<endl;
        else if(a==b)
        cout<<"YES"<<endl;
        else if(abs(a-b)%2==1)
        cout<<"NO"<<endl;
        else if(abs(a-b)<=c)
        cout<<"NO"<<endl;
        else if(((a-b)/2)%(c)==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        
        
    }
}

int main() {
	// your code goes here
	solution();
	return 0;
}