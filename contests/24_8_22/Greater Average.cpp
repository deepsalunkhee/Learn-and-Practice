#include <iostream>
using namespace std;

void solution()
{
    int t;
    cin >> t;
    while (t--)
    {
        float a, b, c;
        cin >> a >> b >> c;
        if (float(a + b) / 2 > c)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main()
{
    // your code goes here
    solution();
    return 0;
}