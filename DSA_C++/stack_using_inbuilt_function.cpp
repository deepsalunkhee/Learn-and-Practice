#include <iostream>
#include <stack>

using namespace std;

void showstack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << '\n';
}

int main()
{
    stack<int> s;
    cout << "enter the element in the  stack";

    int n;
    cin >> n;
    s.push(n);
    int k;
    cin >> k;
    s.push(k);

    showstack(s);

    return 0;
}