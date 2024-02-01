#include<iostream>
using namespace std;

void fill_3g(int &x,int &y){
    if(y<3){
        y=3;
        return;
    }else{
        cout<<"Already Filled"<<endl;
    }
}

void fill_4g(int &x,int &y){
    if(x<4){
        x=4;
        return;
    }else{
        cout<<"Already Filled"<<endl;
    }
}

void empty_3g(int &x,int &y){
    if(y>0){
        y=0;
        return;
    }else{
        cout<<"Already Empty"<<endl;
    }
}

void transfer_all_3g_to_4g(int &x,int &y){
    if(x+y<=4 && y>0){
        x=x+y;
        y=0;
        return;
    }else{
        if(y<=0){
            cout<<"3g is empty"<<endl;
        }else{
            cout<<"Water will over flow"<<endl;
        }
    }
}

void transfer_all_4g_to_3g(int &x,int &y){
    if(x+y<=3 && x>0){
        y=x+y;
        x=0;
        return;
    }else{
        if(x<=0){
            cout<<"4g is empty"<<endl;
        }else{
            cout<<"Water will over flow"<<endl;
        }
    }
}

void transfer_some_3g_to_4g_Until_4g_is_Full(int &x,int &y){
    if(x+y>4 && y>0  && x<4 ){
        y=y-(4-x);
        x=4;
        
        return;
    }else{
        if(y==0){
            cout<<"3g is empty"<<endl;
        }else if(y==4){
            cout<<"4 is already filled"<<endl;
            
        }else{
            cout<<"what is not enough to fill 4g"<<endl;
        }
    }
}

void transfer_some_4g_to_3g_Until_3g_is_Full(int &x,int &y){
    if(x+y>3 && x>0 && y<3){
        x=x-(3-y);
        y=3;
        
        return;
    }else{
        if(x==0){
            cout<<"4g is empty"<<endl;
        }else if(y==3){
            cout<<"3 is already filled"<<endl;
            
        }else{
            cout<<"what is not enough to fill 3g"<<endl;
        }
    }
}


void empty_4g(int &x,int &y){
    if(x>0){
        x=0;
        return;
    }else{
        cout<<"Already Empty";
    }
}

int main(){

cout << "Let's start the water jug problem" << endl;
cout<<"Task: make 4g jug to have 2g water"<<endl;
    int g_4 = 0;
    int g_3 = 0;

    while (true) {
        cout << "\nCurrent States :" << endl;
        cout << "4g:" << g_4 << endl;
        cout << "3g:" << g_3 << endl;
        
         if(g_4==2){
            cout<<"congratulation you are smart!"<<endl;
            return 0;
        }

        cout << "\nMenu:" << endl;
        cout << "1. Fill 3g jug\n2. Fill 4g jug\n3. Empty 3g jug\n4. Empty 4g jug\n";
        cout << "5. Transfer all from 3g to 4g\n6. Transfer all from 4g to 3g\n";
        cout << "7. Transfer some from 3g to 4g until 4g is full\n";
        cout << "8. Transfer some from 4g to 3g until 3g is full\n9. Quit\n";

        int choice;
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                fill_3g(g_4, g_3);
                break;
            case 2:
                fill_4g(g_4, g_3);
                break;
            case 3:
                empty_3g(g_4, g_3);
                break;
            case 4:
                empty_4g(g_4, g_3);
                break;
            case 5:
                transfer_all_3g_to_4g(g_4, g_3);
                break;
            case 6:
                transfer_all_4g_to_3g(g_4, g_3);
                break;
            case 7:
                transfer_some_3g_to_4g_Until_4g_is_Full(g_4, g_3);
                break;
            case 8:
                transfer_some_4g_to_3g_Until_3g_is_Full(g_4, g_3);
                break;
            case 9:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 9.\n";
        }
        
       
    }

    return 0;
}
