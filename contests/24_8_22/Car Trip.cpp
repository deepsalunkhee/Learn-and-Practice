#include <iostream>
using namespace std;
void solutin()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;

        if (k <= 300)
        {
            cout << 3000 << endl;
        }
        else
        {
            cout << k * 10 << endl;
        }
    }
}
int main()
{
    // your code goes here

    solutin();
    return 0;
}
