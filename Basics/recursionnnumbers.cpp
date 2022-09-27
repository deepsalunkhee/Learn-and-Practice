#include<iostream>
using namespace std;
int Nnumbers(int n)
{
    if(n==0)
    {
      return 0;
    }

    cout<<n<<endl;
   Nnumbers(n-1);
}
 
 int main()
 {
     int n;
     cin>>n;
     cout<<Nnumbers(n)<<endl;
     return 0;
 }