#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void Take1D(int n, vector<int>& array)
{
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        array.push_back(temp);
    }
}

void SCAN(int DiskSize, int NoOfrequest, vector<int> request)
{
    int current_pos = 0;
    int distance = 0;

    cout << "Order of service: ";


    sort(request.begin(), request.end());


    auto it = lower_bound(request.begin(), request.end(), current_pos);
    int index = it - request.begin();


    for (int i = index; i < request.size(); i++)
    {
        distance += abs(request[i] - current_pos);
        current_pos = request[i];
        cout << current_pos << " ";
    }


    for (int i = index - 1; i >= 0; i--)
    {
        distance += abs(request[i] - current_pos);
        current_pos = request[i];
        cout << current_pos << " ";
    }

    cout << endl << "Total distance: " << distance << endl;
}

void CSCAN(int DiskSize, int NoOfrequest, vector<int> request)
{
    int current_pos = 0;
    int distance = 0;

    cout << "Order of service: ";


    sort(request.begin(), request.end());


    auto it = lower_bound(request.begin(), request.end(), current_pos);
    int index = it - request.begin();


    for (int i = index; i < request.size(); i++)
    {
        distance += abs(request[i] - current_pos);
        current_pos = request[i];
        cout << current_pos << " ";
    }

    distance += DiskSize - current_pos;
    current_pos = 0;
    cout << current_pos << " ";


    for (int i = 0; i < index; i++)
    {
        distance += abs(request[i] - current_pos);
        current_pos = request[i];
        cout << current_pos << " ";
    }

    cout << endl << "Total distance: " << distance << endl;
}


void SSTF(int DiskSize, int NoOfrequest, vector<int> request)
{
    int current_pos = 0;
    int distance = 0;

    cout << "Order of service: ";

    while (!request.empty())
    {
        int closest_pos = -1;
        int closest_distance = INT32_MAX;

        for (int i = 0; i < request.size(); i++)
        {
            int d = abs(request[i] - current_pos);

            if (d < closest_distance)
            {
                closest_pos = i;
                closest_distance = d;
            }
        }

        distance += closest_distance;
        current_pos = request[closest_pos];
        cout << current_pos << " ";
        request.erase(request.begin() + closest_pos);
    }

    cout << endl << "Total distance: " << distance << endl;
}



void FCFSDS(int DiskSize, int NoOfrequest, vector<int> request)
{
    int current_pos = 0;
    int distance = 0;

    cout << "Order of service: ";
    for (int i = 0; i < NoOfrequest; i++)
    {
        if (request[i] < 0 || request[i] > DiskSize - 1)
        {
            cout << "Error: Request " << request[i] << " is out of range!" << endl;
            continue;
        }

        distance += abs(request[i] - current_pos);
        current_pos = request[i];
        cout << current_pos << " ";
    }

    cout << endl << "Total distance: " << distance << endl;
}

int main()
{
    vector<int> request;
    int DiskSize;
    int NoOfrequest;

    cout << "Enter the disk size: ";
    cin >> DiskSize;

    cout << "Enter the number of incoming requests: ";
    cin >> NoOfrequest;

    cout << "Enter the requests: ";
    Take1D(NoOfrequest, request);

    int choice;
    do
    {
        cout << endl << "Choose a disk scheduling algorithm: " << endl;
        cout << "1. First Come First Serve Disk Scheduling" << endl;
        cout << "2. Shortest Seek Time First Disk Scheduling" << endl;
        cout << "3. SCAN Disk Scheduling" << endl;
        cout << "4. C-SCAN Disk Scheduling" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                FCFSDS(DiskSize, NoOfrequest, request);
                break;
            case 2:
                SSTF(DiskSize, NoOfrequest, request);
                break;
            case 3:
                SCAN(DiskSize, NoOfrequest, request);
                break;
            case 4:
                CSCAN(DiskSize, NoOfrequest, request);
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}


