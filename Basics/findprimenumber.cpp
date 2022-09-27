
#include<iostream>
using namespace std;

int main()
{
    //Code to find the prime number between a and b
    int a,b;
    cout<<"entre a\n";
    cin>>a;
    cout<<"entre b\n";
    cin>>b;
    for(int num=a;num<b; num++)
    {    int i;
        for(i=2;i<num;i++)
        {
            if(num%i==0)
            {
                break;
            }
        }
        if(i==num)
        {
            cout<<num<<endl;
        }
    }
    return 0;
}

