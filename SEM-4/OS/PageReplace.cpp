#include <iostream>
#include <vector>
using namespace std;

void Take1D(vector<int> &IncomingPages)
{
    int NoOfPages;
    cout << "Enter the number of incoming pages" << endl;
    cin >> NoOfPages;
    IncomingPages.resize(NoOfPages);
    for (int i = 0; i < NoOfPages; i++)
    {
        cin >> IncomingPages[i];
    }
}

void LRU(vector<int> IncomingPages, vector<int> Frame, int NoOfPages, int NoOfFrames)
{
    int NextFrameIndex = 0;
    Frame.resize(NoOfFrames, -1); // initialize all frame entries to -1
    vector<int> LastUsedTime(NoOfFrames, -1); // initialize all last used times to -1

    cout << "Incoming Pages: ";
    for (int i = 0; i < NoOfPages; i++)
    {
        cout << IncomingPages[i] << " ";

        // check if the incoming page is already in the frame
        bool Found = false;
        int MinLastUsedTime = INT32_MAX;
        int MinLastUsedTimeIndex = -1;
        for (int j = 0; j < NoOfFrames; j++)
        {
            if (Frame[j] == IncomingPages[i])
            {
                Found = true;
                LastUsedTime[j] = i; // update the last used time of the page
                break;
            }
            else if (LastUsedTime[j] < MinLastUsedTime)
            {
                MinLastUsedTime = LastUsedTime[j];
                MinLastUsedTimeIndex = j;
            }
        }

        // if not found, replace the least recently used page in the frame with the incoming page
        if (!Found)
        {
            Frame[MinLastUsedTimeIndex] = IncomingPages[i];
            LastUsedTime[MinLastUsedTimeIndex] = i; // update the last used time of the page
        }

        
        cout << "Frames: ";
        for (int j = 0; j < NoOfFrames; j++)
        {
            if (Frame[j] == -1)
            {
                cout << "X "; // indicate an empty frame with 'X'
            }
            else
            {
                cout << Frame[j] << " ";
            }
        }
        cout << endl;
    }
}


void FIFO(vector<int> IncomingPages, vector<int> Frame, int NoOfPages, int NoOfFrames)
{

    int NextFrameIndex = 0;
    Frame.resize(NoOfFrames, -1); 

    cout << "Incoming Pages: ";
    for (int i = 0; i < NoOfPages; i++)
    {
        cout << IncomingPages[i] << " ";

        // check if the incoming page is already in the frame
        bool Found = false;
        for (int j = 0; j < NoOfFrames; j++)
        {
            if (Frame[j] == IncomingPages[i])
            {
                Found = true;
                break;
            }
        }

        // if not found, replace the oldest page in the frame with the incoming page
        if (!Found)
        {
            Frame[NextFrameIndex] = IncomingPages[i];
            NextFrameIndex = (NextFrameIndex + 1) % NoOfFrames; // update the index of the next frame to replace
            
        }

        // print the content of the frames at every instance
        cout << "Frames: ";
        for (int j = 0; j < NoOfFrames; j++)
        {
            if (Frame[j] == -1)
            {
                cout << "X "; 
            }
            else
            {
                cout << Frame[j] << " ";
            }
        }
        cout << endl;
    }

}

int main()
{
    int NoOfPages;
    int NoOfFrames;
    vector<int> IncomingPages;
    vector<int> Frame;
    Take1D(IncomingPages);
    cout << "Enter the number of frames" << endl;
    cin >> NoOfFrames;
    NoOfPages = IncomingPages.size();

    int option;
    cout << "Select a page replacement algorithm:" << endl;
    cout << "1. First In First Out (FIFO)" << endl;
    cout << "2. Least Recently Used (LRU)" << endl;
    cin >> option;

    switch (option) {
        case 1:
            cout << "Using FIFO page replacement algorithm" << endl;
            FIFO(IncomingPages, Frame, NoOfPages, NoOfFrames);
            break;
        case 2:
            cout << "Using LRU page replacement algorithm" << endl;
            LRU(IncomingPages, Frame, NoOfPages, NoOfFrames);
            break;
        default:
            cout << "Invalid option selected. Please try again." << endl;
    }

    return 0;
}

