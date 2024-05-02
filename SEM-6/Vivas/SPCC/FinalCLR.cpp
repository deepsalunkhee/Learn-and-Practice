#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<stack>
using namespace std;

void takeInput(vector<string>&input){
    cout<<"Pls enter the size of the string "<<endl;
    int n;
    cin >> n;
    cout << "Pls enter the string" << endl;

    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        input.push_back(temp);
    }

    return;
}

void find_operation(string stack_top,string &operation_type){
    if(stack_top=="0"||
       stack_top=="1"||
       stack_top=="2"||
       stack_top=="3"||
       stack_top=="4"||
       stack_top=="5"||
       stack_top=="6"||
       stack_top=="7"||
       stack_top=="8"||
       stack_top=="9"||
        stack_top=="10"||
        stack_top=="11"||
        stack_top=="12"||
        stack_top=="13")
       {
           operation_type="action";
           return;
       }else if(stack_top=="S"||
                stack_top=="L"||
                stack_top=="R"){
                    operation_type="goto";
                    return;
                }
    return;
}

void printstack(stack<string> temp){

    stack<string> temp1;
    while(!temp.empty()){
        temp1.push(temp.top());
        temp.pop();
    }

    while(!temp1.empty()){
        cout<<temp1.top();
        temp.push(temp1.top());
        temp1.pop();
    }

    cout<<"\t\t\t\t";
    return;

}

void printcurrinput(vector<string> input,int ip){
    for(int i=ip;i<input.size();i++){
        cout<<input[i];
    }
    cout<<"\t\t\t\t";
    return;
}

bool CLR(vector<string> input){

    //adding $ to the end of the input string
    input.push_back("$");


    //action CRL table
    //{state,terminal}=>{action,state}
    map<vector<string>,vector<string>> CRL_Actions;

    //goto CRL table
    //{state,non-terminal}=>{state}
    map<vector<string>,vector<string>> CRL_Goto;

  

    //initializing the action table
    CRL_Actions[{"0","*"}]={"s","4"};
    CRL_Actions[{"0","id"}]={"s","5"};
    CRL_Actions[{"1","$"}]={"ACC"};
    CRL_Actions[{"2","="}]={"s","6"};
    CRL_Actions[{"2","$"}]={"r","5"};
    CRL_Actions[{"3","$"}]={"r","2"};
    CRL_Actions[{"4","*"}]={"s","4"};
    CRL_Actions[{"4","id"}]={"s","5"};
    CRL_Actions[{"5","="}]={"r","4"};
    CRL_Actions[{"5","$"}]={"r","4"};
    CRL_Actions[{"6","*"}]={"s","11"};
    CRL_Actions[{"6","id"}]={"s","12"};
    CRL_Actions[{"7","="}]={"r","3"};
    CRL_Actions[{"7","$"}]={"r","3"};
    CRL_Actions[{"8","="}]={"r","5"};
    CRL_Actions[{"8","$"}]={"r","5"};
    CRL_Actions[{"9","$"}]={"r","1"};
    CRL_Actions[{"10","$"}]={"r","5"};
    CRL_Actions[{"11","*"}]={"s","11"};
    CRL_Actions[{"11","id"}]={"s","12"};
    CRL_Actions[{"12","$"}]={"r","4"};
    CRL_Actions[{"13","$"}]={"r","3"};
    
    


    //initializing the goto table
    CRL_Goto[{"0","S"}]={"1"};
    CRL_Goto[{"0","L"}]={"2"};
    CRL_Goto[{"0","R"}]={"3"};
    CRL_Goto[{"4","L"}]={"8"};
    CRL_Goto[{"4","R"}]={"7"};
    CRL_Goto[{"6","L"}]={"10"};
    CRL_Goto[{"6","R"}]={"9"};
    CRL_Goto[{"11","L"}]={"10"};
    CRL_Goto[{"11","R"}]={"13"};

    //reducing rules
    //Production number=> {Reduce to->Reduce from}
    map<string,vector<string>> CRL_Reduce;
    CRL_Reduce["1"]={"S","L","=","R"};
    CRL_Reduce["2"]={"S","R"};
    CRL_Reduce["3"]={"L","*","R"};
    CRL_Reduce["4"]={"L","id"};
    CRL_Reduce["5"]={"R","L"};




    //initializing the stack
    stack<string> stack;
    stack.push("0");

    //initializing the input pointer
    int ip=0;

    //lets start the parsing

    cout<<"Stack\t\t\tInput\t\t\tActionTaken"<<endl;

    string temp=stack.top();
    cout<<temp[0]<<"\t\t\t";
    printcurrinput(input,ip);
    cout << "This is just initail state" << endl;
    while(true){
        string stack_top=stack.top();
        
        string incoming_symbol = input[ip];


        //debugging
        //cout<<stack_top<<"\t"<<incoming_symbol<<endl;

        //the base case for accepting the string
        if(stack_top=="1" && incoming_symbol=="$"){
            return true;
        }

        //understand if it is a action or a goto
        string operation_type="None";
        find_operation(stack_top,operation_type);
        if(operation_type=="None"){
            return false;
        }

        //if it is a action
        if(operation_type=="action"){

            if(CRL_Actions.find({stack_top,incoming_symbol})==CRL_Actions.end()){
                return false;
            }
            vector<string> action=CRL_Actions[{stack_top,incoming_symbol}];
            string action_type;

            //cout<<action<<endl;
            if(action[0]=="s"){
                action_type="shift";
            }else if(action[0]=="r"){
                action_type="reduce";
            }else if(action[0]=="ACC"){
                //we will never come here beacuse I have  handled the base case before
                return true;
            }

            //if it is a shift operation
            if(action_type=="shift"){
                stack.push(incoming_symbol);
                stack.push(action[1]);
                ip++;

                //printing the stack and input
                printstack(stack);
                printcurrinput(input,ip);
                cout<<action_type<<action[1]<<endl;

            }

            //if it is a reduce operation
            if(action_type=="reduce"){

                string production_number=action[1];
                //debugging

                //cout<<production_number<<endl;
                vector<string> reduce_to_from=CRL_Reduce[production_number];
                for(int i=0;i<2*(reduce_to_from.size()-1);i++){
                    stack.pop();
                }
                stack.push(reduce_to_from[0]);
                //debugging
                //cout<<stack.top()<<endl;

                //printing the stack and input
                printstack(stack);
                printcurrinput(input,ip);
                cout<<action_type<<production_number<<endl;



            }

        }else{

          

            //if it is a goto operation

            //find the the number before the non-terminal
            string current_top=stack_top;
            stack.pop();
            string second_top=stack.top();
            stack.push(current_top);

            //cout<<second_top<<endl;
            if(CRL_Goto.find({second_top,stack_top})==CRL_Goto.end()){
                return false;
            }
            vector<string> goto_state=CRL_Goto[{second_top,stack_top}];
           stack.push(goto_state[0]);

           //debugging
            //cout<<goto_state<<endl;

            //printing the stack and input
            printstack(stack);
            printcurrinput(input,ip);
            cout<<"goto"<<goto_state[0]<<endl;




        }

    }

    return false;

    

}

int main(){

    vector<string>input;
    takeInput(input);
    bool result=false;
    result=CLR(input);
    if(result){
        cout<<"The string is successfully accepted by the given grammar"<<endl;
    }else{
        cout<<"The string is not accepted by the given grammar"<<endl;
    }
    return 0;
}