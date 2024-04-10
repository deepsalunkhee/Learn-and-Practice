#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

size_t stringHashing(string s)
{
 
    // Get the string
    // to get its hash value
    string hashing1 = s;
 
    // Instantiation of Object
    hash<string> mystdhash;
 
    // Using operator() to get hash value
    
    
    
    size_t ans=mystdhash(hashing1);
    return ans;
         
}

string encryption(string s){
	
	int n=s.size();
	string encry_s="";
	for(int i=0;i<n;i++){
		char temp=s[i]+1;
		encry_s= encry_s + (temp);
	}
	
	return encry_s;
}

string decryption(string s){
	
	int n=s.size();
	string decry_s="";
	for(int i=0;i<n;i++){
		char temp=s[i]-1;
		decry_s= decry_s + (temp);
	}
	
	return decry_s;
}

void manupulate(string &s){
	s[0]=s[0]+1;
}

int main(){
	
	string message;
	
	cin>>message;
	
	size_t hashed_message_int=stringHashing(message);
	string hashedMessage=to_string(hashed_message_int);
	string encrypt_hash=encryption(hashedMessage);
	string encrypt_message=encryption(message);
	
	cout<<"The sender side"<<endl;
	
	cout<<"The orignal message"<<endl;
	cout<<message<<endl;
	cout<<"the hashed message"<<endl;
	cout<<hashedMessage<<endl;
	cout<<"the encrypted hashed message "<<endl;
	cout<<encrypt_hash<<endl;
	cout<<"the encrypted  message "<<endl;
	cout<<encrypt_message<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
		
	
	cout<<"The receiver side"<<endl;
	
	
	cout<<"Do you want to manupulate the data"<<endl;
	cout<<"1=>Yes"<<endl;
	cout<<"2=>NO"<<endl;
	
	int t;
	cin>>t;
	
	if(t==1){
		manupulate(encrypt_message);
	}
	
	string decrypted_message= decryption(encrypt_message);
	string decrypted_hash=decryption(encrypt_hash);
	string hashed_decrypted_message=to_string(stringHashing(decrypted_message));
	cout<<"decrypted message"<<endl;
	cout<<decrypted_message<<endl;
	cout<<"decrypted hash"<<endl;
	cout<<decrypted_hash<<endl;
	cout<<"Hashed decrypted message"<<endl;
	cout<<hashed_decrypted_message<<endl;
	
	
	
	
	
	
	
	if(hashed_decrypted_message==decrypted_hash){
		cout<<"correct message"<<endl;
	}else{
		cout<<"incorrect message"<<endl;
	}
	
	
	
	
	return 0;
}
