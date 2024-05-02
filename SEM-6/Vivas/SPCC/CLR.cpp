#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<stack>
using namespace std;

void takeInput(string &input){
    cout<<"Pls enter the input string: "<<endl;
    cin>>input;
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
       stack_top=="9"){
           operation_type="action";
           return;
       }else if(stack_top=="S"||
                stack_top=="C"){
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

    cout<<"\t\t\t";
    return;

}

bool CLR(string input){

    //adding $ to the end of the input string
    input+="$";
   
    //Grammer
    //S->CC
    //C->cC|d

    //action CRL table
    //{state,terminal}=>action
    map<vector<string>,string> CRL_Actions;

    //goto CRL table
    //{state,non-terminal}=>goto
    map<vector<string>,string> CRL_Goto;

  

    //initializing the action table
    CRL_Actions[{"0","c"}]="s3";
    CRL_Actions[{"0","d"}]="s4";
    CRL_Actions[{"1","$"}]="ACC";//this will never reach for this code
    CRL_Actions[{"2","c"}]="s6";
    CRL_Actions[{"2","d"}]="s7";
    CRL_Actions[{"3","c"}]="s3";
    CRL_Actions[{"3","d"}]="s4";
    CRL_Actions[{"4","c"}]="r3";
    CRL_Actions[{"4","d"}]="r3";
    CRL_Actions[{"5","$"}]="r1";
    CRL_Actions[{"6","c"}]="s6";
    CRL_Actions[{"6","d"}]="s7";
    CRL_Actions[{"7","$"}]="r3";
    CRL_Actions[{"8","c"}]="r2";
    CRL_Actions[{"8","d"}]="r2";
    CRL_Actions[{"9","$"}]="r2";


    //initializing the goto table
    CRL_Goto[{"0","C"}]="2";
    CRL_Goto[{"0","S"}]="1";
    CRL_Goto[{"2","C"}]="5";
    CRL_Goto[{"3","C"}]="8";
    CRL_Goto[{"6","C"}]="9";

    //reducing rules
    //Production number=> {Reduce to->Reduce from}
    map<string,vector<string>> CRL_Reduce;
    CRL_Reduce["1"]={"S","CC"};
    CRL_Reduce["2"]={"C","cC"};
    CRL_Reduce["3"]={"C","d"};


    //initializing the stack
    stack<string> stack;
    stack.push("0");

    //initializing the input pointer
    int ip=0;

    //lets start the parsing

    cout<<"Stack\t\t\tInput\t\t\tActionTaken"<<endl;
    cout<<stack.top()<<"\t\t\t"<<input<<"\t\t\t"<<"This is just initail state"<<endl;
    while(true){
        string stack_top=stack.top();
        char incoming_char = input[ip];
        string incoming_symbol = string(1, incoming_char);


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
            string action=CRL_Actions[{stack_top,incoming_symbol}];
            string action_type;

            //cout<<action<<endl;
            if(action[0]=='s'){
                action_type="shift";
            }else if(action[0]=='r'){
                action_type="reduce";
            }else if(action=="ACC"){
                //we will never come here beacuse I have  handled the base case before
                return true;
            }

            //if it is a shift operation
            if(action_type=="shift"){
                stack.push(incoming_symbol);
                stack.push(string(1,action[1]));
                ip++;

                //printing the stack and input
                printstack(stack);
                cout<<input.substr(ip,input.length()-ip)<<"\t\t\t"<<action_type<<action[1]<<endl;
            }

            //if it is a reduce operation
            if(action_type=="reduce"){
                string production_number=string(1,action[1]);
                vector<string> reduce_to_from=CRL_Reduce[production_number];
                for(int i=0;i<2*reduce_to_from[1].length();i++){
                    stack.pop();
                }
                stack.push(reduce_to_from[0]);

                //printing the stack and input
                printstack(stack);
                cout<<input.substr(ip,input.length()-ip)<<"\t\t\t"<<action_type<<production_number<<endl;


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
            string goto_state=CRL_Goto[{second_top,stack_top}];
           stack.push(goto_state);

           //debugging
            //cout<<goto_state<<endl;

            //printing the stack and input
            printstack(stack);
            cout<<input.substr(ip,input.length()-ip)<<"\t\t\tgoto"<<goto_state<<endl;



        }

    }

    return false;

    

}

int main(){

    string input;
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