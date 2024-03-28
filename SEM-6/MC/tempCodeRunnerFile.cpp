#include <string>
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

string Random128(){

   // Seed the random number generator
    srand(time(nullptr));
    
    // This function creates a random 128-bit string comprising of 0 and 1
    std::string s;
    for (int i = 0; i < 128; ++i) {
        s.push_back('0' + rand() % 2); // Convert 0 and 1 to characters '0' and '1'
    }
    return s;

}

void printstring(string s){
    for(int i=0;i<s.length();i++){
        cout<<s[i];
    }
    cout<<endl;
}

string A3(string key, string random){
    //logic for A3
    //Divide key and random in two 64 bits strings
    //say key_64_L, key_64_R, random_64_L, random_64_R
    //XOR key_64_L and random_64_R and store in A3_64_1
    //XOR key_64_R and random_64_L and store in A3_64_2
    //Divide A3_64_1 and A3_64_2 in two 32 bits strings
    //name them as A3_64_1_L, A3_64_1_R, A3_64_2_L, A3_64_2_R
    //XOR A3_64_1_L and A3_64_2_R and store in A3_32_1
    //XOR A3_64_1_R and A3_64_2_L and store in A3_32_2
    //Xor A3_32_1 and A3_32_2 and store in A3_32
    //return A3_32

    string key_64_L=key.substr(0,64);
    string key_64_R=key.substr(64,64);
    string random_64_L=random.substr(0,64);
    string random_64_R=random.substr(64,64);

    string A3_64_1;
    string A3_64_2;
    for(int i=0;i<64;i++){
        A3_64_1.push_back(key_64_L[i]^random_64_R[i]);
        A3_64_2.push_back(key_64_R[i]^random_64_L[i]);
    }

    string A3_64_1_L=A3_64_1.substr(0,32);
    string A3_64_1_R=A3_64_1.substr(32,32);
    string A3_64_2_L=A3_64_2.substr(0,32);
    string A3_64_2_R=A3_64_2.substr(32,32);

    string A3_32_1;
    string A3_32_2;
    for(int i=0;i<32;i++){
        A3_32_1.push_back(A3_64_1_L[i]^A3_64_2_R[i]);
        A3_32_2.push_back(A3_64_1_R[i]^A3_64_2_L[i]);
    }

    string A3_32;
    for(int i=0;i<32;i++){
        A3_32.push_back(A3_32_1[i]^A3_32_2[i]);
    }

    

    return A3_32;


}

string changebit(string s){
    int i=rand()%128;
    if(s[i]=='0'){
        s[i]='1';
    }
    else{
        s[i]='0';
    }

    return s;
}

string A8(string key ,string random){
  //logic for A8
  //Divide key and random in two 64 bits strings
  //say key_64_L, key_64_R, random_64_L, random_64_R
  //XOR key_64_L and random_64_R and store in A8_64_1
  //XOR key_64_R and random_64_L and store in A8_64_2
  //Xor A8_64_1 and A8_64_2 and store in A8_64
  //return A8_64

    string key_64_L=key.substr(0,64);
    string key_64_R=key.substr(64,64);

    string random_64_L=random.substr(0,64);
    string random_64_R=random.substr(64,64);

    string A8_64_1;
    string A8_64_2;

    for(int i=0;i<64;i++){
        A8_64_1.push_back(key_64_L[i]^random_64_R[i]);
        A8_64_2.push_back(key_64_R[i]^random_64_L[i]);
    }

    string A8_64;
    for(int i=0;i<64;i++){
        A8_64.push_back(A8_64_1[i]^A8_64_2[i]);
    }

    return A8_64;
}

int main(){
    string Key_AUC = Random128();
    string Key_SIM=Key_AUC;
    string Random_Number = Random128();

    string Random_Number_2=changebit(Random_Number);
    

    cout<<"Key_AUC: "<<endl;
    printstring(Key_AUC);
    cout<<"Key_SIM: "<<endl;
     printstring(Key_AUC);
    cout<<"Random_Number: "<<endl;
    printstring(Random_Number);

    string A3_AUC=A3(Key_AUC,Random_Number);
    string A3_SIM=A3(Key_SIM,Random_Number);

   
    

    if(A3_AUC==A3_SIM){
        cout<<"Valid SIM Card"<<endl;
    }
    else{
        cout<<"Invalid SIM Card"<<endl;
    }

    string ecrykey_AUC=A8(Key_AUC,Random_Number);
    string ecrykey_SIM=A8(Key_SIM,Random_Number);

    

    if(ecrykey_AUC==ecrykey_SIM){
        cout<<"Proper ecryption is possible"<<endl;
    }
    else{
        cout<<"Proper encryption is not possible"<<endl;
    }


    return 0;
}