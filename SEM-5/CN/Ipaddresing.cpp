#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void takeip(vector<int> &ip)
{
    cout << "enter ip without . :";
    int n;
    cout << "enter the number of group's':";
    cin >> n;
    cout << "start entering the input's......." << endl;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        ip.push_back(t);
    }
}
bool isvalid(vector<int> &ip)
{
    // size
    int sz = ip.size();
    if (sz != 4)
    {
        return false;
    }
    // every group should [0,255]
    for (int i = 0; i < 4; i++)
    {
        int value = ip[i];
        if (!(value >= 0 && value < 256))
        {
            return false;
        }
    }
    // hex and binary
    return true;
}
int findgroup(vector<int> &ip)
{
    if (ip[0] >= 0 && ip[0] <= 127)
    {
        cout << "Belong to group A" << endl;
        return 0;
    }
    else if (ip[0] >= 128 && ip[0] <= 191)
    {
        cout << "Belong to group B" << endl;
        return 1;
    }
    else if (ip[0] >= 192 && ip[0] <= 223)
    {
        cout << "Belong to group C" << endl;
        return 2;
    }
    else if (ip[0] >= 224 && ip[0] <= 239)
    {
        cout << "Belong to group D" << endl;
        return 3;
    }
    else if (ip[0] >= 240 && ip[0] <= 255)
    {
        cout << "Belong to group E" << endl;
        return 4;
    }

    return 0;
}
void firstip(vector<int> &ip, int gid, vector<vector<int>> &cm)
{
    vector<int> fip;
    cout << "first ip is:" << endl;
    for (int i = 0; i < 4; i++)
    {
        int temp = ip[i] & cm[gid][i];
        fip.push_back(temp);
        cout << fip[i] << ".";
    }
}
void lastip(vector<int> &ip, int gid, vector<vector<int>> &cm)
{
    vector<int> lip;
    cout << "last ip is:" << endl;
    for (int i = 0; i < 4; i++)
    {
        int ones;
        if (cm[gid][i] == 255)
            ones = 0;
        else
            ones = 255;
        int temp = ip[i] | ones;
        lip.push_back(temp);
        cout << lip[i] << ".";
    }
}
int main()
{
    vector<int> ip;
    takeip(ip);
    vector<vector<int>> cm = {{255, 0, 0, 0}, {255, 255, 0, 0}, {255, 255, 255, 0}};
    if (isvalid(ip))
    {
        cout << "ip is valid......" << endl;
        // finding to which group it belong's
        int gid = findgroup(ip);
        if ((gid == 3 || gid == 4))
        {
            cout << "this is reversed class......" << endl;
        }
        else
        {
            firstip(ip, gid, cm);
            lastip(ip, gid, cm);
        }
    }
    else
    {
        cout << "ip is not valid......" << endl;
    }

    return 0;
}