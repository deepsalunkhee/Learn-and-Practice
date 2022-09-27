#include<iostream>
using namespace std;
int pow(int n,int p)
{
    if (p==1)
    {
        return n;
    }
    int prevpow=pow(n,p-1);
    return n*prevpow;
}
int main()
{  int n,p;
cin>>n>>p;
cout<<pow(n,p)<<endl;
return 0;
   


}

