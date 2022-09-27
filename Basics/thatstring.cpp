#include <iostream>
#include <cstdio>
#include "string"
using namespace std;

int main() {
    // Complete the code.
    int n,m;
    cin>>n>>m;
    
    string num[9]={"one","two","three","four","five","six","seven","eight","nine"};
    
    
    
    for(int i=n;i<=m;i++)
    {
        if(i<=9)
       {
        cout<<num[i-1]<<endl;
       }
    
         else if(i<=m&&i%2==0&&i>9)
       {
        cout<<"even"<<endl;
        }
        else if(i<=m&&i%2==1&&i>9)
        {
         cout<<"odd"<<endl;
        }
        else{
            break;
        }
        
    }
    
     return 0;
}
