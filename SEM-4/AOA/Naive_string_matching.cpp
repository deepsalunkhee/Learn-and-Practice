#include <iostream>
#include <string>

using namespace std;

void naive_string_matching(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    // Iterate through each character in the text
    for (int i = 0; i <= n - m; i++) {
        int j;

        // Check if the current substring of text matches the pattern
        for (j = 0; j < m; j++) {
            if (text[i+j] != pattern[j])
                break;
        }

        // If the entire pattern was matched, print the starting index
        if (j == m)
        {
            cout << "Pattern found at index " << i << endl;
            return;
        }
            
    }

    cout<<"No Matching Pattern found"<<endl;
}

int main() {
    string text, pattern;

    // Get input from the user
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern to match: ";
    getline(cin, pattern);

    // Call the naive string matching function
    naive_string_matching(text, pattern);

    return 0;
}
