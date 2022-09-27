#include<iostream>
using namespace std;
//craeting a function for lenear search
int searcharr(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
        
    }   return -1;
} 
int main()
{
    int n;
    cout<<"Entre n:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int key;
    cout<<"entre key:"<<endl;
    cin>>key;

    cout<<searcharr(arr,n,key);

    return 0;


}
