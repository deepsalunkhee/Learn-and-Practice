#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int readfile(string &fileName,vector<string> &input){
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

void print_vector(vector<string> &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i]<<" ";
    }
    cout << endl;
}

void Tokenization(vector<string> &input, vector<string> &Tokensed, map<string, string> &keywords)
{
    for (int i = 0; i < input.size(); i++)
    {
        if(input[i]==";") continue;

        if (keywords.find(input[i]) != keywords.end())
        {
            Tokensed.push_back(keywords[input[i]]);
        }
        else
        {
            Tokensed.push_back("ID");
        }
    }
}

int main(){
    //Database starts
    map<string, string> keywords;
    keywords["int"] = "INT";
    keywords["float"] = "FLOAT";
    keywords["+"]="PLUS";
    keywords["-"]="MINUS";
    keywords["*"]="MULTIPLY";
    keywords["/"]="DIVIDE";
    keywords["="]="ASSIGN";
    keywords["^"]="POWER";
    keywords["("]="LPAREN";
    keywords[")"]="RPAREN";
    
    //ID for identifiers

    //Database ends
    string inputFile;
    vector<string>input;
    vector<string>Tokensed;

    cout << "Enter the name of the file: ";
    cin >> inputFile;
    readfile(inputFile, input);

    cout<<"The input file is: "<<endl;
    print_vector(input);

    Tokenization(input, Tokensed, keywords);
    cout<<"The tokens are: "<<endl;
    print_vector(Tokensed);






    return 0;
}