#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int x[100];//position of queen in col
int n;

int check(int k,int i)
{
for(int j=1;j<=k;j++)
{
if((x[j]==i)||(abs(x[j]-i))==abs(j-k))
return 0;
}
return 1;
}

void nqueen(int k)
{
for(int i=1;i<=n;i++)
{
if(check(k,i))
{
 x[k]=i;
 if(k==n)
 {
  cout<<"\n";
  //print answer
  for(int j=1;j<=n;j++)
  {
  cout<<x[j]<<" ";
}
 }{
nqueen(k+1);
 }
 
}
}

}
int main()
{

cout<<"enter the number of queen/order of matrix:";
cin>>n;

nqueen(1);

return 0;
}