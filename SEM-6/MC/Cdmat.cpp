#include<iostream>
#include<vector>
using namespace std;

void TakeCode(string &s,int size){
    
    int originalsize=size;
    
    cin>>s;
    if(s.length()!=size){
            cout<<"Invalid size "<<endl;
     		return;
    }
    for(int i=0;i<size;i++){
        if(s[i]=='1'|| s[i]=='0'){
            continue;
     }else{
     	cout<<"Not a Binary"<<endl;
     	return;
     }
        
    }
    
}

void Bipolar(vector<int>&C,string s){
    int size=s.length();
    for(int i=0;i<size;i++){
        if(s[i]=='1'){
            C.push_back(1);
        }else{
            C.push_back(-1);
        }
    }

}

void 	Multiply(vector<int>A,vector<int>B,vector<int>&M){
    int size=A.size();
    for(int i=0;i<size;i++){
        M.push_back(A[i]*B[i]);
    }
}

int  getorthogonals(vector<int>&Ortho_A,vector<int>&Ortho_B){

    int len=4;
	cout<<"The lenght for orthogonal will be 4"<<endl;
	
	string A,B;
	cout<<"Enter first code(Binary)"<<endl;
	TakeCode(A,len);
	cout<<"Enter Secont code(Binary)"<<endl;
	TakeCode(B,len);
	vector<int>M;
	Bipolar(Ortho_A,A);
	Bipolar(Ortho_B,B);
	Multiply(Ortho_A,Ortho_B,M);
	int temp=0;
	int size=A.size();
	for(int i=0;i<size;i++){
	temp=temp+M[i];
	}
	
	for(int i=0;i<len;i++){
		cout<<M[i];
		if(i!=len-1) cout<<"*";
	}
	cout<<"="<<temp<<endl;
	
	if(temp==0){
		cout<<"It is Orthogonal"<<endl;
		
		
	}else
	{
			cout<<"It is Not Orthogonal"<<endl;
	}
	return 0;

}

void TakeData(vector<int>&A,vector<int>&B){
	
	string Bd,Ad;
	
	cout<<"Enter data A (make sure that data is just 1 bit)"<<endl;
	
	cin>>Ad;
	int la=Ad.length();
    if(la!=1){
        cout<<"Invalid data"<<endl;
        return;
    }
	for(int i=0;i<la;i++){
		if(Ad[i]=='1')
		A.push_back(1);
		else{
			A.push_back(-1);
		}
	}

    cout<<"Enter data B (make sure that data is just 1 bit)"<<endl;
	
	
	cin>>Bd;
	int lb=Bd.length();

    if(lb!=1){
        cout<<"Invalid data"<<endl;
        return;
    }
	for(int i=0;i<lb;i++){
		if(Bd[i]=='1')
		B.push_back(1);
		else{
			B.push_back(-1);
		}
	}
	
	
}

void cal_data_signal(vector<int>&data,vector<int>&code,vector<int>&signal){
    
    int n=code.size();
    for(int i=0;i<n;i++){
        signal.push_back(data[0]*code[i]);
    }			
}

void printvector(vector<int>data){
    int size=data.size();
    for(int i=0;i<size;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}


void cal_carrier_signal(vector<int>&A,vector<int>&B,vector<int>&C){
    int size=A.size();
    for(int i=0;i<size;i++){
        C.push_back(A[i]+B[i]);
    }
   
}

void receiver(vector<int>Csignal,vector<int>Ortho_A,vector<int>Ortho_B){

    vector<int>Reveive_A,Reveive_B;


    //received A
    for(int i=0;i<4;i++){
        Reveive_A.push_back(Csignal[i]*Ortho_A[i]);
    }

    //received B
    for(int i=0;i<4;i++){
        Reveive_B.push_back(Csignal[i]*Ortho_B[i]);
    }

    int sumA=0,sumB=0;
    for(int i=0;i<4;i++){
        sumA+=Reveive_A[i];
        sumB+=Reveive_B[i];
    }

    cout<<"Sum of A :"<<sumA<<endl;
    cout<<"Sum of B :"<<sumB<<endl;

    if(sumA>0){
        cout<<"A=1"<<endl;
    }else{
        cout<<"A=0"<<endl;
    }

    if(sumB>0){
        cout<<"B=1"<<endl;
    }else{
        cout<<"B=0"<<endl;
    }


}

int main(){
    //lets get to autogonal values

    vector<int>Ortho_A,Ortho_B;
    getorthogonals(Ortho_A,Ortho_B);

    vector<int>Adata,Bdata;
	TakeData(Adata,Bdata);

    vector<int>signalA,signalB,Csignal;
    cal_data_signal(Adata,Ortho_A,signalA);
    cal_data_signal(Bdata,Ortho_B,signalB);

    cout<<"Signal of A"<<endl;
    printvector(signalA);
    cout<<"Signal of B"<<endl;
    printvector(signalB);

    cal_carrier_signal(signalA,signalB,Csignal);

    printvector(Csignal);

    receiver(Csignal,Ortho_A,Ortho_B);

    return 0;
}