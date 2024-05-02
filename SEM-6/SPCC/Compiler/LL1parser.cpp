#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

int readfile(string &fileName, vector<string> &input)
{
    char ch;
    fstream fp;
    fp.open(fileName.c_str(), std::fstream::in);

    if (!fp)
    {
        cerr << "Error opening the file: " << fileName << endl;
        return 1; // Return an error code
    }

    string word;
    while (fp >> noskipws >> ch)
    {
        if (ch == '\n')
        {
            input.push_back(word);
            input.push_back(";");
            word = "";
        }
        else if (ch == ' ')
        {
            input.push_back(word);
            word = "";
        }
        else
        {
            word += ch;
        }
    }

    input.push_back(word);

    fp.close();
    return 0; // Return success code
}

void print_vector_2D(vector<vector<string>> &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i][0] << " "
             << "*->" << input[i][1] << " ";
        cout << endl;
    }
    cout << endl;
}

void print_vector(vector<string> &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}

void Tokenization(vector<string> &input, vector<vector<string>> &Tokensed, map<string, string> &keywords, map<string, int> &intcp, map<string, float> &floatcp, map<string, string> &idp)
{
    int idc = 0;
    int intcc = 0;
    int floatcc = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ";")
            continue;

        if (keywords.find(input[i]) != keywords.end())
        {

            Tokensed.push_back({keywords[input[i]], "NA"});
        }
        else
        {
            // if the value in not in keyword db it can be eithre identifier or constant

            string curr = input[i];
            char first_of_curr = curr[0]; // foc
            int val_of_foc = first_of_curr - '0';
            // cout << val_of_foc << endl;
            if (val_of_foc >= 0 && val_of_foc <= 9)
            {
                bool isfloat = false;
                for (auto x : curr)
                {
                    if (x == '.')
                        isfloat = true;
                }
                if (isfloat)
                {
                    float v = atof(curr.c_str());
                    string p = to_string(floatcc);
                    Tokensed.push_back({"3", p});
                    floatcp[p] = v;
                    floatcc++;
                }
                else
                {
                    int v = stoi(curr);
                    string p = to_string(intcc);
                    Tokensed.push_back({"2", p});
                    intcp[p] = v;
                    intcc++;
                }
            }
            else
            {
                string p = to_string(idc);

                Tokensed.push_back({"1", p});
                idp[p] = curr;
                idc++;
            }
        }
    }
}

void print_all_Symtabs(map<string, int> &intcp, map<string, float> &floatcp, map<string, string> &idp)
{
    cout << "The integer constant pointer is: " << endl;
    for (auto x : intcp)
    {
        cout << x.first << "->" << x.second << endl;
    }
    cout << endl;

    cout << "The float constant pointer is: " << endl;
    for (auto x : floatcp)
    {
        cout << x.first << "->" << x.second << endl;
    }
    cout << endl;

    cout << "The identifier pointer is: " << endl;
    for (auto x : idp)
    {
        cout << x.first << "->" << x.second << endl;
    }
    cout << endl;
}

void DisplayPT(vector<vector<string>> productions, map<vector<string>, int> PT)
{
    cout << "table" << endl;
    ;
}

bool LL1Parser(vector<vector<string>> Tokensed)
{

    // Parser table

    vector<vector<string>> productions = {
        {"1", "9", "E"},   // 0
        {"T", "E_"},       // 1
        {"4", "T", "E_"},  // 2
        {"5", "T", "E_"},  // 3
        {"P", "T_"},       // 4
        {"6", "P", "T_"},  // 5
        {"7", "P", "T_"},  // 6
        {"F", "P_"},       // 7
        {"8", "P"},        // 8
        {"1"},             // 9
        {"10", "E", "11"}, // 10
        {"2"},             // 11
        {"3"},             // 12
        {"0"},             // 13

    };

    // Parser table
    map<vector<string>, int> PT;
    PT[{"S", "1"}] = 0;
    PT[{"E", "1"}] = 1;
    PT[{"T", "1"}] = 4;
    PT[{"P", "1"}] = 7;
    PT[{"F", "1"}] = 9;
    PT[{"E_", "4"}] = 2;
    PT[{"T_", "4"}] = 13;
    PT[{"P_", "4"}] = 13;
    PT[{"T_", "5"}] = 13;
    PT[{"E_", "5"}] = 3;
    PT[{"P_", "5"}] = 0;
    PT[{"T_", "6"}] = 5;
    PT[{"P_", "6"}] = 13;
    PT[{"T_", "7"}] = 6;
    PT[{"P_", "7"}] = 13;
    PT[{"P_", "8"}] = 8;
    PT[{"E", "10"}] = 1;
    PT[{"T", "10"}] = 4;
    PT[{"P", "10"}] = 7;
    PT[{"F", "10"}] = 10;
    PT[{"E_", "11"}] = 13;
    PT[{"T_", "11"}] = 13;
    PT[{"P_", "11"}] = 13;
    PT[{"E", "2"}] = 1;
    PT[{"E", "3"}] = 1;
    PT[{"T", "2"}] = 4;
    PT[{"T", "3"}] = 4;
    PT[{"P", "2"}] = 7;
    PT[{"P", "3"}] = 7;
    PT[{"F", "2"}] = 11;
    PT[{"F", "3"}] = 12;
    PT[{"E_", "$"}] = 13;
    PT[{"T_", "$"}] = 13;
    PT[{"P_", "$"}] = 13;

    // DisplayPT(productions,PT);

    string Inputstring = "";
    for (auto x : Tokensed)
    {

        Inputstring = Inputstring + x[0];
    }

    cout << "The input string is:" << endl;
    cout << Inputstring << endl;

    stack<string> s;
    s.push("S");
    int pin = 0;
    bool success = false;

    while (s.empty() == false && pin < Inputstring.size())
    {

        cout << "Stack top: " << s.top() << endl;
        cout << "Input string: " << Inputstring[pin] << endl;

        // condition for epsilon

        if (s.empty() == false && s.top() == "0")
        {
            s.pop();
            if(s.empty() == true && Inputstring[pin] == '$')
            {
                success = true;
                break;
            }
            continue;
        }

        if (Inputstring[pin] == '$' && s.empty() == true)
        {
            success = true;
            break;
        }
        string some = string(1, Inputstring[pin]);
        if (s.top() == some)
        {
            s.pop();
            pin++;

            continue;
        }

        string stop = s.top();

        //what does string(1,Inputstring[pin] do? )=> it converts the char to string
        string ic = string(1, Inputstring[pin]);

        if (PT.find({stop, ic}) != PT.end())
        {

            s.pop();
            vector<string> temp = productions[PT[{stop, ic}]];
            int ts = temp.size();
            for (int i = ts - 1; i >= 0; i--)
            {
                s.push(temp[i]);
            }
        }
        else
        {
            success = false;
            break;
        }
    }

    return success;
}

int main()
{
    // Database starts
    map<string, string> keywords;
    keywords["int"] = "INT";
    keywords["float"] = "FLOAT";
    keywords["+"] = "4";
    keywords["-"] = "5";
    keywords["*"] = "6";
    keywords["/"] = "7";
    keywords["="] = "9";
    keywords["^"] = "8";
    keywords["("] = "10";
    keywords[")"] = "11";
    keywords["$"] = "$"; // End of file
    // 3 for float
    // 2 for int

    // 1 for identifiers

    // pointer to intc
    map<string, int> intcp;
    // pointer ot intf
    map<string, float> floatcp;
    // pointer to identifier
    map<string, string> idp;

    // Database ends
    string inputFile;
    vector<string> input;
    vector<vector<string>> Tokensed;

    cout << "Enter the name of the file: ";
    cin >> inputFile;
    readfile(inputFile, input);

    cout << "The input file is: " << endl;
    print_vector(input);

    Tokenization(input, Tokensed, keywords, intcp, floatcp, idp);
    cout << "The tokens are: " << endl;
    print_vector_2D(Tokensed);

    print_all_Symtabs(intcp, floatcp, idp);

    // Logic of Parser

    bool iscorrect = LL1Parser(Tokensed);
    if (iscorrect)
    {
        cout << "The format grammer is follow" << endl;
    }
    else
    {
        cout << "The grammer is not followed" << endl;
    }

    return 0;
}
