// #include <iostream>
// using namespace std;
// void solution()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
        
//     }
// }

// int main() {
// 	// your code goes here
// 	solution();
// 	return 0;
// }

#include <iostream>
#include <string>

using namespace std;
void solution()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        getline(cin,a);
        
        for(int j=0;j<a.size()-3;j++)
        {
            if((a[j]=='e'||a[j]=='a'||a[j]=='i'||a[j]=='o'||a[j]=='u')&&(a[j+1]=='e'||a[j+1]=='a'||a[j+1]=='i'||a[j+1]=='o'||a[j+1]=='u')&&(a[j+2]=='e'||a[j+2]=='a'||a[j+2]=='i'||a[j+2]=='o'||a[j+2]=='u'))
            {
                cout<<"Happy"<<endl;
                break;
             
            }
            if((a[j]!='e'||a[j]!='a'||a[j]!='i'||a[j]!='o'||a[j]!='u')&&(a[j+1]!='e'||a[j+1]!='a'||a[j+1]!='i'||a[j+1]!='o'||a[j+1]!='u')&&(a[j+2]!='e'||a[j+2]!='a'||a[j+2]!='i'||a[j+2]!='o'||a[j+2]!='u'))
            {
                cout<<"Sad"<<endl;
                break;
            }
            
        }

    }
}

int main() {
	// your code goes here
	solution();
	return 0;
}