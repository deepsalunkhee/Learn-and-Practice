


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<map>

using namespace std;


int readAssembly(string& fileName, vector<string>& lines) {
    char ch;
    fstream fp;
    fp.open(fileName.c_str(), std::fstream::in);

    if (!fp) {
        cerr << "Error opening the file: " << fileName << endl;
        return 1; // Return an error code
    }

    string line;
    while (fp >> noskipws >> ch) {
        if (ch == '\n') {
            lines.push_back(line);
            line.clear();
        } else {
            line.push_back(ch);
        }
    }


        lines.push_back(line);
    

    fp.close();
    return 0; // Return success code
}


void createOutputFile( vector<string>& input, map<string, string>& m, string& fileName) {
    ofstream outputFile;
    outputFile.open(fileName.c_str(), std::ios::out);

    if (!outputFile.is_open()) {
        cerr << "Error creating the output file: " << fileName <<endl;
        return;
    }

    for (int i = 0; i < input.size(); i++) {
        string temp = input[i];
        outputFile << temp <<" "<< m[temp] << std::endl;
    }

    outputFile.close();
}


int main() {
	
	//the data set of the oppcode and mneomonics
	map<string,string>m;
	m["MOV"]="000AH";
	m["ADD"]="000CH";
	m["SUB"]="0003H";
	
	//the dataset end here
    vector<string> input;
    string inputfile ;
    string outputfile;
    
    cout<<"Enter filename to read"<<endl;
    cin>>inputfile;

    // Call the readAssembly function to populate the input vector
    if (readAssembly(inputfile, input) == 0) {
    	
    cout<<"Save file as"<<endl;
	cin>>outputfile;	
    
     createOutputFile(input,m,outputfile);
     cout<<"File Saved"<<endl;
    }

    return 0;
}
