#include<iostream>
#include<vector>
using namespace std;

bool Takeinput(vector<int>&input,int &size){
	
	cout<<"Pls enter the size"<<endl;
	cin>>size;
	
	string tempinput;
	
	cout<<"pls Enter value"<<endl;
	cin>>tempinput;
	
	if(tempinput.length()!=size){
		cout<<"Invalid size"<<endl;
		return false;
	}
	
	for(int i=0;i<size;i++){
		
		char temp=tempinput[i];
		
		if(temp=='1')
		input.push_back(1);
		else
		input.push_back(0);
	}
	
	return true;
	

	
	
}

void DSSS_encrypt(vector<int>data,int data_size,vector<int>chipping_code,int chipping_size,vector<vector<int> >&division){
	
	int parts=data_size;
	int size_of_part=chipping_size/parts;
	
	int index=0;
	for(int i=0;i<chipping_size;i++){
		
		int parts=size_of_part;
		vector<int>temp;
		while(parts--){
			int xored=chipping_code[i]^data[index];
			temp.push_back(xored);
			i++;
		}
		i--;
		index++;
		division.push_back(temp);
		
		
	}
	
	cout<<"Encryted value"<<endl;
	for(int i=0;i<division.size();i++){
		for(int j=0;j<division[0].size();j++){
			cout<<division[i][j]<<" ";
		}
	}
	cout<<endl;
	

}

vector<int> DSSS_decode(vector<vector<int> >encoded,vector<int>chipping){
	
	int index=0;
	vector<int>ans;
	
	for(int i=0;i<encoded.size();i++){
		for(int j=0;j<encoded[0].size();j++){
			int temp=chipping[index]^encoded[i][j];
			ans.push_back(temp);
			index++;
		}
		
	}
	
	return ans;
}

void Print(vector<int>ans){
	cout<<" Decrypted value"<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
}


int main(){
	vector<int>data;
	int data_size;
	vector<int>chippingCode;
	int chipping_code_size;
	vector<vector<int> >encoded;
	bool check=true;
	
	cout<<"For Data"<<endl;
	check=Takeinput(data,data_size);
	if(!check) return 0;
	
	cout<<"For ChippingCode"<<endl;
	check=Takeinput(chippingCode,chipping_code_size);
	if(!check) return 0;
	
	DSSS_encrypt(data,data_size,chippingCode,chipping_code_size,encoded);
	vector<int>ans=DSSS_decode(encoded,chippingCode);
	Print(ans);
	return 0;
}