
#include<iostream>
#include<vector>
using namespace std;

// Function to check if the current state is the goal state
bool isGoalState(int g_4, int g_3) {
    return g_4 == 2;
}

// Function to print the solution path
void printSolutionPath(const vector<string>& path) {
    cout << "Solution Found!\n";
    cout << "Steps:\n";
    for (const string& step : path) {
        cout << step << endl;
    }
}

// Function to solve the water jug problem using iterative approach
void solveWaterJugProblem() {
    int g_4 = 0, g_3 = 0; // Initial state
    vector<string> path; // Path to store the solution steps

    // Iterative process to find the solution
    while (!isGoalState(g_4, g_3)) {
        if (g_4 < 4) {
            // Fill 4g jug
            int prev_g_4 = g_4;
            g_4 = 4;
            path.push_back("Fill 4g jug (" + to_string(prev_g_4) + "g -> " + to_string(g_4) + "g)");
        } else if (g_3 < 3) {
            // Fill 3g jug
            int prev_g_3 = g_3;
            g_3 = 3;
            path.push_back("Fill 3g jug (" + to_string(prev_g_3) + "g -> " + to_string(g_3) + "g)");
        } else if (g_4 > 0) {
            // Empty 4g jug
            int prev_g_4 = g_4;
            g_4 = 0;
            path.push_back("Empty 4g jug (" + to_string(prev_g_4) + "g -> " + to_string(g_4) + "g)");
        } else if (g_3 > 0) {
            // Empty 3g jug
            int prev_g_3 = g_3;
            g_3 = 0;
            path.push_back("Empty 3g jug (" + to_string(prev_g_3) + "g -> " + to_string(g_3) + "g)");
        } else if (g_3 > 0 && g_4 < 4) {
            // Transfer from 3g to 4g until 4g is full
            int prev_g_4 = g_4, prev_g_3 = g_3;
            int transfer_amount = min(4 - g_4, g_3);
            g_4 += transfer_amount;
            g_3 -= transfer_amount;
            path.push_back("Transfer " + to_string(transfer_amount) + "g from 3g to 4g (" + to_string(prev_g_3) + "g, " + to_string(prev_g_4) + "g -> " + to_string(g_3) + "g, " + to_string(g_4) + "g)");
        } else if (g_4 > 0 && g_3 < 3) {
            // Transfer from 4g to 3g until 3g is full
            int prev_g_4 = g_4, prev_g_3 = g_3;
            int transfer_amount = min(3 - g_3, g_4);
            g_3 += transfer_amount;
            g_4 -= transfer_amount;
            path.push_back("Transfer " + to_string(transfer_amount) + "g from 4g to 3g (" + to_string(prev_g_4) + "g, " + to_string(prev_g_3) + "g -> " + to_string(g_4) + "g, " + to_string(g_3) + "g)");
        }
    }

    // Print the solution path
    printSolutionPath(path);
}

int main() {
    cout << "Let's start the water jug problem\n";
    cout << "Task: make 4g jug have 2g water\n";

    // Solve the water jug problem
    solveWaterJugProblem();

    return 0;
}

