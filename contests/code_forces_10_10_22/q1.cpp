#include <iostream>
#include <stdlib.h>
using namespace std;
void solution()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> b[j];
        }

        int an1 = 0, an0 = 0, bn1 = 0, bn0 = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == 1)
                an1++;
            if (a[j] == 0)
                an0++;
            if (b[j] == 1)
                bn1++;
            if (b[j] == 0)
                bn0++;
        }

        int status = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[j] == b[j])
                status++;
        }

        if (status == n)
            cout << 0 << endl;
        else if (an1 == bn1 && an0 == bn0)
            cout << 1 << endl;
        else
            cout << n - status - abs(an1 - bn0) << endl;
    }
}

int main()
{
    solution();
    return 0;
}