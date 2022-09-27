#include<iostream>
using namespace std;
int main()
{
 int n;
 cout<<"entre n :";
 cin>>n;
 for(int i=0;i<=n;i++)
 {
   for(int j=05;j<=n;j++)
     {
       if( j<n-i)
      {
       cout<<" ";

      }

     
     
     else
     {
       cout<<"*";
     }
   }
   cout<<endl;

 }
 return 0;
  }