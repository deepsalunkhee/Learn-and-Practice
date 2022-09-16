#include<iostream>
using namespace std;
void solution()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=4;
        char a[4];
        while(n--)
        {
            cin>>a[4-n];
        }
       if(a[0]!=a[1]!=a[2]!=a[3])
       {
        cout<<3<<endl;
       }
       else if(a[0]!=a[1]!=a[2])
       {
        cout<<2<<endl;
       }
       else if(a[0]!=a[1]||a[0]!=a[2])
       {
        cout<<1<<endl;
       }
       else
       {
        cout<<0<<endl;
       }

    }

}
int main()
{
    solution();
    return 0;
}