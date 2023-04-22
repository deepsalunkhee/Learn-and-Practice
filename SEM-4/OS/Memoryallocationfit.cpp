#include <iostream>
#include <vector>
using namespace std;

void Take1D(int n, vector<int> &array)
{
    for (int i = 0; i < n; i++)
    {
        int temp;

        cin >> temp;
        array.push_back(temp);
    }
}
void BestFit(int NoOfProcess, vector<int> incoming, int NoOfHoles, vector<int> Holes)
{
    vector<int> allocation(NoOfProcess, -1); // to store allocation info
    for (int i = 0; i < NoOfProcess; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < NoOfHoles; j++)
        {
            if (Holes[j] >= incoming[i]) // if hole is big enough
            {
                if (bestIdx == -1 || Holes[bestIdx] > Holes[j]) // if no hole is selected yet or if the current hole is smaller than the selected hole
                {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) // a hole is found
        {
            allocation[i] = bestIdx; // allocate process i to hole bestIdx
            Holes[bestIdx] -= incoming[i]; // reduce the size of the hole
        }
    }

    cout << "Process No.\tProcess Size\tBlock no." << endl;
    for (int i = 0; i < NoOfProcess; i++)
    {
        cout << i+1 << "\t\t" << incoming[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i]+1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}

void WorstFit(int NoOfProcess, vector<int> incoming, int NoOfHoles, vector<int> Holes)
{
    vector<int> allocation(NoOfProcess, -1); // to store allocation info

    for (int i = 0; i < NoOfProcess; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < NoOfHoles; j++)
        {
            if (Holes[j] >= incoming[i]) // if hole is big enough
            {
                if (worstIdx == -1 || Holes[worstIdx] < Holes[j]) // if no hole is selected yet or if the current hole is bigger than the selected hole
                {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) // a hole is found
        {
            allocation[i] = worstIdx; // allocate process i to hole worstIdx
            Holes[worstIdx] -= incoming[i]; // reduce the size of the hole
        }
    }

    cout << "Process No.\tProcess Size\tBlock no." << endl;
    for (int i = 0; i < NoOfProcess; i++)
    {
        cout << i+1 << "\t\t" << incoming[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i]+1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}

void NextFit(int NoOfProcess, vector<int> incoming, int NoOfHoles, vector<int> Holes)
{
    vector<int> allocation(NoOfProcess, -1); // to store allocation info

    int start = 0;
    for (int i = 0; i < NoOfProcess; i++)
    {
        int j;
        for (j = start; j < NoOfHoles; j++)
        {
            if (Holes[j] >= incoming[i]) // if hole is big enough
            {
                allocation[i] = j; // allocate process i to hole j
                Holes[j] -= incoming[i]; // reduce the size of the hole
                start = j; // update start for next iteration
                break;
            }
        }
        if (allocation[i] == -1) // no hole is found
        {
            // search from beginning
            for (j = 0; j < start; j++)
            {
                if (Holes[j] >= incoming[i]) // if hole is big enough
                {
                    allocation[i] = j; // allocate process i to hole j
                    Holes[j] -= incoming[i]; // reduce the size of the hole
                    start = j; // update start for next iteration
                    break;
                }
            }
        }
    }

    cout << "Process No.\tProcess Size\tBlock no." << endl;
    for (int i = 0; i < NoOfProcess; i++)
    {
        cout << i+1 << "\t\t" << incoming[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i]+1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}



void FirstFit(int NoOfProcess, vector<int> incoming, int NoOfHoles, vector<int> Holes)
{
    vector<int> allocation(NoOfProcess, -1); // initialize allocation vector to -1

    int completed = 0;
    int i = 0;
    int missed = 0;
    int j = 0;

    while (1)
    {
        if (Holes[i] >= incoming[j])
        {
            Holes[i] = Holes[i] - incoming[i];
            allocation[j] = i; // update allocation vector
            completed++;
            i = -1;
            j++;
        }
        else
        {
            missed++;
        }

        if (missed == NoOfHoles)
        {
            cout << "Not Possible" << endl;
            cout << "As process of size " << incoming[j] << " cannot be allocated by FirstFit" << endl;
            return;
        }

        if (completed == NoOfProcess)
        {
            cout << "Possible" << endl;

            // print allocation information
            for (int k = 0; k < NoOfProcess; k++) {
                cout << "Process " << k << " is allocated to hole " << allocation[k] << endl;
            }

            return;
        }

        i = (i + 1) % NoOfHoles;
    }
}


void FirstFit1(int NoOfProcess, vector<int> incoming, int NoOfHoles, vector<int> Holes)
{
    vector<int> allocation(NoOfProcess, -1); // to store allocation info

    int start = 0;
    for (int i = 0; i < NoOfProcess; i++)
    {
        int j;
        for (j = 0; j < NoOfHoles; j++)
        {
            if (Holes[j] >= incoming[i]) // if hole is big enough
            {
                allocation[i] = j; // allocate process i to hole j
                Holes[j] -= incoming[i]; // reduce the size of the hole
                start = j; // update start for next iteration
                break;
            }
        }
        
    }

    cout << "Process No.\tProcess Size\tBlock no." << endl;
    for (int i = 0; i < NoOfProcess; i++)
    {
        cout << i+1 << "\t\t" << incoming[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i]+1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}





int main()
{
    int choice;

    // declare variables to store input
    int NoOfProcess, NoOfHoles;
    vector<int> incoming, Holes;

    cout << "Enter the number of processes: ";
    cin >> NoOfProcess;
    Take1D(NoOfProcess, incoming);

    cout << "Enter the number of holes: ";
    cin >> NoOfHoles;
    Take1D(NoOfHoles, Holes);

    while (1)
    {
        cout << "Choose an algorithm:" << endl;
        cout << "1. First Fit" << endl;
        cout << "2. Best Fit" << endl;
        cout << "3. Worst Fit" << endl;
        cout << "4. Next Fit" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            FirstFit1(NoOfProcess, incoming, NoOfHoles, Holes);
            break;

        case 2:
            BestFit(NoOfProcess, incoming, NoOfHoles, Holes);
            break;

        case 3:
            WorstFit(NoOfProcess, incoming, NoOfHoles, Holes);
            break;

        case 4:
            NextFit(NoOfProcess, incoming, NoOfHoles, Holes);
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}
