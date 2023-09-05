#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // Map to store Function Point types and their corresponding complexities
    map<string, map<string, int>> complexity_table;
    complexity_table["External Inputs (EI)"] = {{"Simple", 3}, {"Average", 4}, {"Complex", 6}};
    complexity_table["External Outputs (EO)"] = {{"Simple", 4}, {"Average", 5}, {"Complex", 7}};
    complexity_table["External Inquiries (EQ)"] = {{"Simple", 3}, {"Average", 4}, {"Complex", 6}};
    complexity_table["Internal Logical Files (ILF)"] = {{"Simple", 7}, {"Average", 10}, {"Complex", 15}};
    complexity_table["External Interface Files (EIF)"] = {{"Simple", 5}, {"Average", 7}, {"Complex", 10}};


    // 14 factors
    string aspects[14] = {
        "reliable backup and recovery required ?",
        "data communication required ?",
        "are there distributed processing functions ?",
        "is performance critical ?",
        "will the system run in an existing heavily utilized operational environment ?",
        "on line data entry required ?",
        "does the on line data entry require the input transaction to be built over multiple screens or operations ?",
        "are the master files updated on line ?",
        "is the inputs, outputs, files or inquiries complex ?",
        "is the internal processing complex ?",
        "is the code designed to be reusable ?",
        "are the conversion and installation included in the design ?",
        "is the system designed for multiple installations in different organizations ?",
        "is the application designed to facilitate change and ease of use by the user ?"
    };

    // Value Adjustment Factor (VAF)
    double sum = 0.0;

    // Get user input for complexities
    for (const auto& entry : complexity_table) {
        cout << "Complexity options for " << entry.first << ": ";
        for (const auto& complexity : entry.second) {
            cout << complexity.first << " " <<complexity.second<<" ";
        }
        cout << endl;

        string key;
        cout << "Enter the complexity for " << entry.first << ": ";
        cin >> key;
        int temp;
        cout<<"enter the value:";
        cin>>temp;

        // Use const_cast to temporarily remove const qualifier for the map value
        sum += (const_cast<map<string, int>&>(entry.second)[key])*temp;
    }

    // Get user input for 14 questions
    int addition = 0;
    
    for (int i = 1; i <= 14; ++i) {
        int value;
        cout<<aspects[i-1]<<endl;
        cout << "Enter value (0-4) for question " << i << ": ";
        cin >> value;
        addition += value;
    }

   

    double fp = sum * (0.65 + 0.01 * addition);
    //double adjusted_fp = fp * (1 + sum);

    // Display the results
    cout << "Function Points (FP): " << fp << endl;
   // cout << "Adjusted Function Points (AFP): " << adjusted_fp << endl;

    return 0;
}