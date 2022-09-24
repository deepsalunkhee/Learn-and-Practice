#include <iostream>
using namespace std;

void solution()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a-b>b)
        cout<<b<<endl;
        else
        cout<<a-b<<endl;
        
    }
}

int main() {
	// your code goes here
	solution();
	return 0;
}