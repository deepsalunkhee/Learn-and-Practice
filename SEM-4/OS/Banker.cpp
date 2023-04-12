#include <iostream>
#include <vector>
using namespace std;

int NoOfProcess, NoOfResources;
vector<vector<int>> Allocation;
vector<vector<int>> MaxNeed;
vector<vector<int>> Need;
vector<int> MaxInstances;


vector<int> CurrentlyAvailable;
vector<int> AvailvleAfterGiving;

void SimpleFill(vector<vector<int>> &matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        vector<int> temp(0);

        for (int j = 0; j < columns; j++)
        {
            int temp1;
            cin >> temp1;
            temp.push_back(temp1);
        }
        matrix.push_back(temp);
    }
}

void CalNeed(vector<vector<int>> &matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        vector<int> temp(0);

        for (int j = 0; j < columns; j++)
        {
            int temp1;
            temp1 = MaxNeed[i][j] - Allocation[i][j];
            temp.push_back(temp1);
        }
        matrix.push_back(temp);
    }
}

void maxFill(vector<int> &matrix, int columns)
{
    for (int i = 0; i < columns; i++)
    {
        int temp;
        cin >> temp;
        matrix.push_back(temp);
    }
}

void print2D(vector<vector<int>> &matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void print1D(vector<int> &matrix, int columns)
{
    for (int j = 0; j < columns; j++)
    {
        
        cout << matrix[j] << "\t";
    }
    cout<<endl;
}

void CalCA()
{
    for (int j = 0; j < NoOfResources; j++)
    {
        int temp = 0;
        for (int i = 0; i < NoOfProcess; i++)
        {
            temp += Allocation[i][j];
        }
        CurrentlyAvailable.push_back(MaxInstances[j] - temp);
    }
}



void Banker()
{
    // Step 1: Calculate the currently available resources
    CalCA();

    // Step 2: Initialize the visited and answer vectors
    vector<bool> visited(NoOfProcess, false);
    vector<int> ans;

    // Step 3: Repeat until all processes have been visited
    while (ans.size() != NoOfProcess)
    {
        // Step 4: Find a process that has not been visited and whose needs can be satisfied
        int i;
        for (i = 0; i < NoOfProcess; i++)
        {
            if (!visited[i])
            {
                bool check = true;
                for (int j = 0; j < NoOfResources; j++)
                {
                    if (Need[i][j] > CurrentlyAvailable[j])
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    break;
                }
            }
        }

        // Step 5: If no such process is found, the system is in an unsafe state
        if (i == (NoOfProcess))
        {
            cout << "The system is in an unsafe state." << endl;
            return;
        }

        // Step 6: Mark the process as visited and add it to the answer vector
        visited[i] = true;
        ans.push_back(i);

        // Step 7: Update the currently available resources
        for (int j = 0; j < NoOfResources; j++)
        {
            CurrentlyAvailable[j] += Allocation[i][j];
        }
    }

    // Step 8: If all processes have been visited, the system is in a safe state
    cout << "The system is in a safe state." << endl;
    cout << "Safe sequence: ";
    for (int i = 0; i < NoOfProcess; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}


int main()
{

    cout << "Enter No of process" << endl;
    cin >> NoOfProcess;
    cout << "Enter No of Resources " << endl;
    cin >> NoOfResources;

    cout << "Enter the max No. of instence for each resources" << endl;
    maxFill(MaxInstances, NoOfResources);
    cout << "Enter resource allocation for each of the process" << endl;
    SimpleFill(Allocation, NoOfProcess, NoOfResources);
    cout << "Enter  max resource needed for each of the process" << endl;
    SimpleFill(MaxNeed, NoOfProcess, NoOfResources);
    CalNeed(Need, NoOfProcess, NoOfResources);
    cout << "Allocation Matrix" << endl;
    print2D(Allocation, NoOfProcess, NoOfResources);
    cout << "Max need Matrix" << endl;
    print2D(MaxNeed, NoOfProcess, NoOfResources);
    cout << "Max avilable Instances" << endl;
    print1D(MaxInstances, NoOfResources);
    Banker();

    return 0;
}
