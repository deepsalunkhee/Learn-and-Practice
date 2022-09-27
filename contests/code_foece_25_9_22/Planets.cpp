#include<iostream>
using namespace std;

void solution()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;

        int p[n];

        for (int  i = 0; i < n; i++)
        {
            cin>>p[i];
        }
        int sum=0;

        for(int j=0;j<n;j++)
        {
            int count=0;
            for(int i=0;i<n;i++)
            {
                if((p[j]==p[i])&&(i!=j))
                count++;
            }
            cout<<c;
            if(count>=c)
            {
                sum=sum+count*c;
            }
            else{
                sum=sum+count;
            }

        }

        cout<<sum<<endl;
        
    }

}
int main()
{
   solution();
   return 0; 
}