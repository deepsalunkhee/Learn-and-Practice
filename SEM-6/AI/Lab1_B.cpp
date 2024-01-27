#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Define a custom hash function for pairs of integers
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

// Function to check if the current state is the goal state
bool isGoalState(int g_4, int g_3) {
    return g_4 == 2; // Goal state: 4g jug has 2g water, 3g jug is empty
}


// Function to solve the water jug problem
void solveWaterJugProblem() {
    // Map to store the next states for each current state
    unordered_map<pair<int, int>, pair<int, int>, pair_hash> nextStateMap;
    vector<string> path; // Path to store the solution steps
    int g_4 = 0, g_3 = 0; // Initial state

    // Generate the nextStateMap based on the rules of the problem
    nextStateMap[{0, 0}] = {0, 3}; // Fill 3g jug
    nextStateMap[{0, 3}] = {3, 0}; // Fill 4g jug
    nextStateMap[{3, 0}] = {3, 3}; // Transfer from 4g to 3g until 3g is full
    nextStateMap[{3, 3}] = {4, 2}; // Transfer from 3g to 4g until 4g is full
    nextStateMap[{0, 2}] = {2, 0}; // Transfer from 4g to 3g until 3g is full
    nextStateMap[{2, 0}] = {2, 3}; // Transfer from 3g to 4g until 4g is full
    nextStateMap[{2, 3}] = {4, 1}; // Transfer from 4g to 3g until 3g is full
    nextStateMap[{4, 1}] = {1, 0}; // Transfer from 4g to 3g until 3g is full
    nextStateMap[{1, 0}] = {1, 3}; // Transfer from 3g to 4g until 4g is full
    nextStateMap[{1, 3}] = {4, 0}; // Transfer from 4g to 3g until 3g is full
    nextStateMap[{4, 0}] = {2, 0}; // Transfer from 4g to 3g until 3g is full
    nextStateMap[{4, 2}] = {0, 2}; // Transfer from 4g to 3g until 3g is full

    // Iterative process to find the solution
    while (!isGoalState(g_4, g_3)) {
        // Print the current state
        cout << "Prev State: [" << g_4 << ", " << g_3 << "] => ";

        // Get the next state from the map
        auto nextState = nextStateMap[{g_4, g_3}];

        // Print the next state
        cout << "Next State: [" << nextState.first << ", " << nextState.second << "]" << endl;

        // Update the current state
        g_4 = nextState.first;
        g_3 = nextState.second;
    }

    // Print the final state
     cout<<"Goal reached"<<endl;
}

int main() {
    cout << "Let's start the water jug problem\n";
    cout << "Task: make 4g jug have 2g water\n";

    // Solve the water jug problem
    solveWaterJugProblem();

    return 0;
}

