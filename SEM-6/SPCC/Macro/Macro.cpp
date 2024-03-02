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
        cout << input[i] <<endl;
    }
    cout << endl;
}

void pass1(	map<string,int>&MNT_MDTP,map<string,int>&MNT_PP,vector<string>&MDT,	map<string,vector<string> >&FPL,map<string,vector<string> >&APL,vector<string>input,vector<string>&input_copy){
	
	//start going throught the inptus
	int inputsize=input.size();
	for(int i=0;i<inputsize;i++){
		
		 if(input[i]==";") continue;
		
		if(input[i]=="MACRO"){
			
			 //filling the MNT
			 i++;
			 i++;
			 int MDTnextindex=MDT.size();
			 string line1="";
			 string Macro_Name=input[i];
			 line1=line1+Macro_Name+" ";
			 MNT_MDTP[Macro_Name]=MDTnextindex;
			 //counting number of positional parameter
			 int ppc=0;
			 i++;
			 while(input[i]!=";"){
                int currindex=FPL[Macro_Name].size();
                //convertt it to string
                string temp=to_string(currindex);

			 	line1=line1+temp+" ";
			 	//adding it to FPL and APL
                FPL[Macro_Name].push_back(input[i]);
                
			 	ppc++;
			 	i++;
			 }
			 MNT_PP[Macro_Name]=ppc;
			 
			 MDT.push_back(line1);
			 
			 string line="";
			 i++;
			 
			while(input[i]!="MEND"){
				
				
				
				if(input[i]==";"){
					i++;
					MDT.push_back(line+";");
					line="";
					continue;
				}
				//replacing the positional parameter
                if(input[i][0]=='&'){
                    //find index[i] in the FPL[Macro_Name]

                    //cout<<input[i]<<endl;
                    int size=FPL[Macro_Name].size();
                    for(int j=0;j<size;j++){
                        //cout<<to_string(j)<<"test"<<endl;
                        //cout<<input[i]<<endl;
                        if(FPL[Macro_Name][j]==input[i]){
                            //cout<<to_string(j)<<"test"<<endl;
                            line=line+"#"+to_string(j)+" ";
                            break;
                        }
                    }
                    
                }else{
                  line=line+input[i]+" ";
				 
                }

                i++; 

				
				
				
				
			}
			MDT.push_back(input[i]);
			
			
		}
	}
	
}

void Map_print(map<string, int> &m)
{
    
    for (std::map<std::string, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void Map_print2(map<string, vector<string>> &m)
{
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        std::cout << it->first << ": ";
        for (const auto &value : it->second)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}



void Expand(map<string, int> &MNT_MDTP, map<string, int> &MNT_PP, vector<string> &MDT, map<string, vector<string>> &FPL, vector<string> input, vector<string> &input_copy) {
    cout << "Ready to expand" << endl;
    vector<string> output;
    int inputsize = input.size();

    // Open the output file for writing
    ofstream outputFile("macroexpanded.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (int i = 0; i < inputsize; i++) {
        if (input[i] == ";") {
            outputFile << endl;
            continue;
        };
        if (input[i] == "MACRO") {
            //skip the macro
            while (input[i] != "MEND") {
                i++;
            }
            continue;
        }

        //if macro call is found
        if (MNT_MDTP.find(input[i]) != MNT_MDTP.end()) {
            string Macro_Name = input[i];
            map<int, string> APL;
            int MDTindex = MNT_MDTP[input[i]];
            MDTindex++;
           
            i++;
            int ind = 0;
            while (input[i] != ";") {
                APL[ind] = input[i];
                i++;
                ind++;
                if(i >= inputsize) break;
            }
                //  cout << "The macro name is " << Macro_Name << MDTindex<<endl;
                

            //creating the output
            while (MDT[MDTindex] != "MEND") {
                string line = MDT[MDTindex];
                int size = line.size();
                string temp = "";
                for (int i = 0; i < size; i++) {
                    if (line[i] == ' ' || line[i] == ';') {
                        outputFile << temp << " ";
                        if (line[i] == ';') outputFile << endl;
                        temp = "";
                        continue;
                    }

                    if (line[i] == '#') {
                        i++;
                        int ind = line[i] - '0';
                        outputFile << APL[ind] << " ";
                        continue;
                    }

                    temp += line[i];
                }
                MDTindex++;
            }
        }
    }

    // Close the output file
    outputFile.close();

    cout << "The macro expansion is done." << endl;
}

int main(){
	
	//macro name table structure
	map<string,int>MNT_MDTP;
	map<string,int>MNT_PP;
    vector<string>input_copy;
	
	//FPL and APL
	map<string,vector<string> >FPL,APL;
	
	//macro defination table
	vector<string>MDT;
	
	//input file
	vector<string>input;
	
	//files to read and save;
	string readfrom;
	string saveas;
	
	cout<<" Enter file name to read"<<endl;
	cin>>readfrom;
	if(readfile(readfrom,input)==0){
		
		//cout<<"The inputfile is"<<endl;
		//print_vector(input);
		//filling the datasets
		pass1(MNT_MDTP,MNT_PP,MDT,FPL,APL,input,input_copy);
		
		cout<<"The MNT is"<<endl;
		Map_print(MNT_MDTP);
		Map_print(MNT_PP);
		
		cout<<"The MDT is"<<endl;
		print_vector(MDT);
		
//		int temp=MDT.size();
//		cout<<temp<<endl;

        cout<<"The FPL and APL is"<<endl;
        Map_print2(FPL);

        // cout<<"The input_copy is"<<endl;
        // print_vector(input_copy);

         //cout<<"The APL is"<<endl;
         //Map_print2(APL);

       // pass2(MNT_MDTP,MNT_PP,MDT,FPL,APL,input, input_copy);
       Expand(MNT_MDTP,MNT_PP,MDT,FPL,input, input_copy);
		
		
		
		
	}
	
	
	
	return 0;
}