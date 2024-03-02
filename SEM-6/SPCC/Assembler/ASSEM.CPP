#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int readAssembly(string &fileName, vector<string> &input)
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

void createOutputFile(vector<string> &input, map<string, string> &mneomonics_oppcode, map<string, int> &mneomonics_size, map<string, int> &label_def, map<string, int> &label_ref, string &fileName)
{
    ofstream outputFile;
    outputFile.open(fileName.c_str(), std::ios::out);

    if (!outputFile.is_open())
    {
        cerr << "Error creating the output file: " << fileName << endl;
        return;
    }

    int startAddress = 0;
    // counter to now which part of the line we are in
    int counter = 0;
    for (int i = 0; i < input.size(); i++)
    {
        string temp = input[i];

        if (temp == ";")
        {
            counter = 0;
            continue;
        }

        if (temp == "START")
        {
            startAddress = stoi(input[i + 1]);
            continue;
        }

        if (temp == "USING")
        {
            continue;
        }

        if (temp == "ACC")
        {
            continue;
        }

        if (temp == "EQU")
        {
            label_def[input[i - 1]] = stoi(input[i + 1]);
            continue;
        }

        if (temp == "L")
        {
            outputFile << "L";
            outputFile << " ";
            outputFile << input[i + 1];
            outputFile << " ";
            outputFile << label_ref[input[i + 1]] << endl;
            startAddress += mneomonics_size[temp];
            continue;
        }

        if (temp == "AR")
        {
            continue;
        }

        if (temp == "ST")
        {
            continue;
        }

        if (temp == "DC" || temp == "DS")
        {
            continue;
        }

        if (mneomonics_oppcode.find(temp) != mneomonics_oppcode.end())
        {
            outputFile << temp << " " << mneomonics_oppcode[temp] << " " << startAddress << endl;
            startAddress += mneomonics_size[temp];
            continue;
        }

        if (temp[temp.size() - 1] == ':')
        {
            label_ref[temp.substr(0, temp.size() - 1)] = startAddress;
            continue;
        }
    }

    outputFile.close();
}

int main()
{

    // the data set of the  mneomonics_oppcode and mneomonics
    map<string, string> mneomonics_oppcode;
    mneomonics_oppcode["L"] = "DC";
    mneomonics_oppcode["AR"] = "DC";
    mneomonics_oppcode["ST"] = "DC";
    mneomonics_oppcode["DC"] = "DC";
    mneomonics_oppcode["DS"] = "DS";
    mneomonics_oppcode["MOV"] = "000AH";
    mneomonics_oppcode["ADD"] = "000CH";
    mneomonics_oppcode["SUB"] = "0003H";
    mneomonics_oppcode["JUMP"] = "0002H";

    map<string, int> mneomonics_size;
    mneomonics_size["MOV"] = 1;
    mneomonics_size["ADD"] = 3;
    mneomonics_size["SUB"] = 5;
    mneomonics_size["JUMP"] = 1;
    map<string, int> label_def;
    map<string, int> label_ref;

    // the dataset end here
    vector<string> input;
    string inputfile;
    string outputfile;

    cout << "Enter filename to read" << endl;
    cin >> inputfile;

    // Call the readAssembly function to populate the input vector
    if (readAssembly(inputfile, input) == 0)
    {

        cout << "Save file as" << endl;
        cin >> outputfile;

        createOutputFile(input, mneomonics_oppcode, mneomonics_size, label_def, label_ref, outputfile);
        cout << "File Saved" << endl;
    }

    return 0;
}
