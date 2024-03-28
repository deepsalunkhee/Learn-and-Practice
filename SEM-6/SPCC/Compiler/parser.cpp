#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
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

void print_vector_2D(vector<vector<string> > &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i][0] << " " <<"*->"<< input[i][1] << " ";
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

void Tokenization(vector<string> &input, vector<vector<string> > &Tokensed, map<string, string> &keywords, map<string, int> &intcp, map<string, float> &floatcp, map<string, string> &idp)
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


bool S(vector<vector<string>> Tokensed,int &pin);
bool E(vector<vector<string>> Tokensed,int &pin);
bool E_(vector<vector<string>> Tokensed,int &pin);
bool T(vector<vector<string>> Tokensed,int &pin);
bool T_(vector<vector<string>> Tokensed,int &pin);
bool P(vector<vector<string>> Tokensed,int &pin);
bool P_(vector<vector<string>> Tokensed,int &pin);
bool F(vector<vector<string>> Tokensed,int &pin);



bool F(vector<vector<string>> Tokensed,int &pin){
	cout<<"Entering F  :"<<pin<<endl;
	
	int thispin=pin;
	if(Tokensed[pin][0]=="10"){
			cout<<"10 obtained  :"<<pin<<endl;
		pin++;
		if(E(Tokensed,pin)){
			if(Tokensed[pin][0]=="11"){
				cout<<"11 obtained  :"<<pin<<endl;
                pin++;
                cout<<"Exiting F  :"<<pin<<endl;
				return true;
			}
		}
	}
	
	pin = thispin;
	
	if(Tokensed[pin][0]=="1"){
	cout<<"1 obtained  :"<<pin<<endl;
    pin++;
    cout<<"Exiting F  :"<<pin<<endl;
	return true;
}
	
		if(Tokensed[pin][0]=="2"){
	cout<<"2 obtained  :"<<pin<<endl;
    pin++;
    cout<<"Exiting F  :"<<pin<<endl;
	return true;
}
		if(Tokensed[pin][0]=="3"){
	cout<<"3 obtained  :"<<pin<<endl;
    pin++;
    cout<<"Exiting F  :"<<pin<<endl;
	return true;
}
	
    cout<<"Exiting F  :"<<pin<<endl;

    if(Tokensed[pin][0]=="-1")
    return true;

	return false;
	
}

bool P(vector<vector<string>> Tokensed,int &pin){
	cout<<"Entering P  :"<<pin<<endl;
	if(F(Tokensed,pin)){
		bool some=P_(Tokensed,pin);

        cout<<"Exiting P  :"<<pin<<endl;
        return some;
	}
	
    cout<<"Exiting P  :"<<pin<<endl;
    if(Tokensed[pin][0]=="-1")
    return true;
	return false;
}

bool P_(vector<vector<string>> Tokensed,int &pin){
	cout<<"Entering P_  :"<<pin<<endl;
	int thispin=pin;
	if(Tokensed[pin][0]=="8"){
		cout<<"8 obtained  :"<<pin<<endl;
	pin++;
	bool some=P(Tokensed,pin);
    cout<<"Exiting P_  :"<<pin<<endl;
    return some;
	}
	
	pin= thispin;
	if(pin!=Tokensed.size()-1){
        cout<<"Exiting P_  :"<<pin<<endl;
		return true;
	}
	
    cout<<"Exiting P_  :"<<pin<<endl;
    if(Tokensed[pin][0]=="-1")
    return true;
	return false;
	
	
}





bool T_(vector<vector<string>> Tokensed,int &pin){
	
	cout<<"Entering T_  :"<<pin<<endl;
	
	int thispin=pin;
	
	if(Tokensed[pin][0]=="6"){
		pin++;
		cout<<"6 obtained  :"<<pin<<endl;
		if(P(Tokensed,pin)){
			bool some= T_(Tokensed,pin);
            cout<<"Exiting T_  :"<<pin<<endl;
            return some;
		}
	}
	
	pin = thispin;
	if(Tokensed[pin][0]=="7"){
		pin++;
		cout<<"7 obtained  :"<<pin<<endl;
		if(P(Tokensed,pin)){
			bool some= T_(Tokensed,pin);
            cout<<"Exiting T_  :"<<pin<<endl;
            return some;    
		}
	}
	
	pin = thispin;
	if(pin!=Tokensed.size()-1){
        cout<<"Exiting T_  :"<<pin<<endl;
		return true;
	}
	
    cout<<"Exiting T_  :"<<pin<<endl;
    if(Tokensed[pin][0]=="-1")
    return true;
	return false;
	
	
}


bool T(vector<vector<string>> Tokensed,int &pin){
	
	cout<<"Entering T  :"<<pin<<endl;
	if(P(Tokensed,pin)){
		bool some= T_(Tokensed,pin);
        cout<<"Exiting T  :"<<pin<<endl;
        return some;
	}

    cout<<"Exiting T  :"<<pin<<endl;
    if(Tokensed[pin][0]=="-1")
    return true;
	return false;
}


bool E_(vector<vector<string>> Tokensed,int &pin){
	
	cout<<"Entering E_  :"<<pin<<endl;
	
	int thispin=pin;
	
	if(Tokensed[pin][0]=="4"){
			cout<<"4 obtained  :"<<pin<<endl;
		pin++;
		if(T(Tokensed,pin)){
			bool some= E_(Tokensed,pin);
            cout<<"Exiting E_  :"<<pin<<endl;
            return some;
		}
	}
	
	pin=thispin;
	if(Tokensed[pin][0]=="5"){
		cout<<"5 obtained  :"<<pin<<endl;
		pin++;
		if(T(Tokensed,pin)){
			bool some= E_(Tokensed,pin);
            cout<<"Exiting E_  :"<<pin<<endl;
            return some;
		}
	}
	
	
	pin=thispin;
	if(pin!=Tokensed.size()-1){
        cout<<"Exiting E_  :"<<pin<<endl;
		return true;
	}
	
    cout<<"Exiting E_  :"<<pin<<endl;
    if(Tokensed[pin][0]=="-1")
    return true;
	return false;
	
}



bool E(vector<vector<string>> Tokensed,int &pin){
	cout<<"Entering E  :"<<pin<<endl;
	if(T(Tokensed,pin)){
		bool some= E_(Tokensed,pin);
        cout<<"Exiting E  :"<<pin<<endl;
        return some;
	}
	
    cout<<"Exiting E  :"<<pin<<endl;
    if(Tokensed[pin][0]=="-1")
    return true;
	return false;
}










bool S(vector<vector<string>> Tokensed,int &pin){
	cout<<"Entering S  :"<<pin<<endl;
	if(Tokensed[pin][0]=="1"){
		cout<<"1 obtained  :"<<pin<<endl;
		pin++;
		if(Tokensed[pin][0]=="9"){
			cout<<"9 obtained  :"<<pin<<endl;
			pin++;
			bool some= E(Tokensed,pin);
            cout<<"Exiting S  :"<<pin<<endl;
            return some;
		}
    }
    

    cout<<"Exiting S  :"<<pin<<endl;
    return false;
}

bool Parser(vector<vector<string>> Tokensed){
	
	int pin=0;
	
	return S(Tokensed,pin);
	
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
    keywords["$"] = "-1"; // End of file

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
    
    bool iscorrect= Parser(Tokensed);
    if(iscorrect){
    	cout<<"The format grammer is follow"<<endl;
	}else{
		cout<<"The grammer is not followed"<<endl;
	}
    
    



    return 0;
}
