#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cout<<"Enter max weight and no weights"<<endl;
    cin >> m >> n;

    vector<int> p(n); // price array
    vector<int> w(n); // weight array

    for (int i = 0; i < n; i++) {
        cout<<"Enter profit and weight for "<<i+1<<endl;
        cin >> p[i] >> w[i];
    }

    vector<pair<double, int>> pw(n);
    for (int i = 0; i < n; i++) {
        pw[i] = make_pair((double)p[i] / w[i], i); // pw ratio of that object
    }

    sort(pw.begin(), pw.end(), greater<pair<double, int>>()); // sort in descending order

    double profit = 0;
    int k = 0;
    while (m > 0 && k < n) {
        int idx = pw[k].second;
        if (w[idx] <= m) {
            m -= w[idx];
            profit += p[idx];
            cout << "Object " << idx + 1 << " added with weight " << w[idx] << " and profit " << p[idx] << endl;
        }
        else {
            profit += (pw[k].first * m); // add fractional part of pw ratio
            cout << "Object " << idx + 1 << " added with weight " << m << " and profit " << pw[k].first * m << endl;
            m = 0;
        }
        k++;
    }

    cout << "Total profit: " << profit << endl;

    return 0;
}
