#include<iostream>
#include<vector>
using namespace std;

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

int main(){
	int len=0;
	cout<<"Enter length"<<endl;
	cin>>len;
	string A,B;
	cout<<"Enter first code(Binary)"<<endl;
	TakeCode(A,len);
	cout<<"Enter Secont code(Binary)"<<endl;
	TakeCode(B,len);
	vector<int>AC,BC,M;
	Bipolar(AC,A);
	Bipolar(BC,B);
	Multiply(AC,BC,M);
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