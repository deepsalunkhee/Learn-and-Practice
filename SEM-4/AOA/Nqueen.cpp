//Nqueen problem
#include <math.h>
#include <iostream>
using namespace std;

int x[100]; 
int n;
int count;

int check(int k, int i)
{
    for (int j = 1; j <= k -1; j++)
    {
        if ((x[j] == i) || (abs(x[j] - i)) == abs(j - k))
            return 0;
    }
    return 1;
}

void nqueen(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (check(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                count++;
                cout << "Solution " << count << ": ";
               
                for (int j = 1; j <= n; j++)
                {
                    cout << x[j] << " ";
                }
                cout << "\n";
            }
            else
            {
                nqueen(k + 1);
            }
        }
    }
}

int main()
{
    cout << "Enter the number of queens/order of matrix:";
    cin >> n;
    count = 0;

    nqueen(1);

    if (count == 0)
    {
        cout << "No solutions found.\n";
    }
    else
    {
        cout << "Found " << count << " solutions.\n";
    }

    return 0;
}
