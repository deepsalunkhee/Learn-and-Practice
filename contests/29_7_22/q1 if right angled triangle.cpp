#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {

	// Your code here
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;

    if(a>b)
    {
        if(a>c)
        {
            if(a*a==b*b+c*c)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
        else if(a*a+b*b==c*c)
        {
            cout<<"Yes"<<endl;
        }
         else
            {
                cout<<"No"<<endl;
            }
    }
    else if(b>c)
    {
         if(c*c+a*a==b*b)
            {
                cout<<"Yes"<<endl;
            }
             else
            {
                cout<<"No"<<endl;
            }
       
    }
    else if(a*a+b*b==c*c)
        {
            cout<<"Yes"<<endl;
        }
         else
            {
                cout<<"No"<<endl;
            }
    return 0;
}