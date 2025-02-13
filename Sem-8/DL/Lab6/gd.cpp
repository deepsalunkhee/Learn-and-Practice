#include<iostream>
#include<vector>
using namespace std;


void printThetas(vector<float>&thetas){
	int n=thetas.size();
	
	for(int i=0;i<n;i++){
		cout<<thetas[i]<<" ";
	}
	cout<<endl;
}

void print2d(vector<vector<float>>&thetas){
	int n=thetas.size();
	int m=thetas[0].size();
	 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<thetas[i][j]<<" ";
		}
		cout<<endl;
	}
}


void gd(vector<float>&thetas,vector<vector<float>>data,vector<float>target,int tc,int tl,float lr){
	//cout<<"hi"<<endl;
	
	vector<float>y_cap(tl);

		
	for(int i=0;i<tl;i++){
		float c_y_cap=thetas[0];
		for(int j=0;j<tc-1;j++){
			c_y_cap+=data[i][j]*thetas[j+1];
		}
			y_cap[i]=c_y_cap; 
		//cout<<y_cap[i]<<endl;
		
	
		
	}
	
	for(int i=0;i<tc;i++){
		if(i==0){
			
			float val=-1.0/tl;
			
			float sum=0;
			for(int j=0;j<tl;j++){
				sum+=target[j]-y_cap[j];
			}
			val=val*sum;
			
			thetas[i]=thetas[i]-(lr*(val));
			cout<<thetas[i]<<endl;
			
			
		}else{
			
			float val=-1.0/tl;
			
			float sum=0;
			for(int j=0;j<tl;j++){
				sum+=(target[j]-y_cap[j])*data[j][i-1];
			}
			val=val*sum;
			
			thetas[i]=thetas[i]-(lr*(val));
			cout<<thetas[i]<<endl;
			
		}
	}
}

int main(){
	int tc;//thetaCount
	cout<<"Enter the number of thetas"<<endl;
	cin>>tc;
	
	vector<float>thetas(tc);
	cout<<"Enter thetas"<<endl;
	for(int i=0;i<tc;i++){
		cin>>thetas[i];
	}
	
	printThetas(thetas);
	
	float lr;//learning rate
	cout<<"Enter learning rate"<<endl;
	cin>>lr;
	
	
	int tl;//tuple count
	cout<<"Enter number of tuples"<<endl;
	cin>>tl;
	vector<vector<float>>data(tl,vector<float>(tc-1));
	vector<float>target(tl);

	
	cout<<"Enter Data"<<endl;
	
	for(int i=0;i<tl;i++ ){
		for(int j=0;j<tc-1;j++){
			cin>>data[i][j];
		}
	}
	
	cout<<"Enter target"<<endl;
	
	for(int i=0;i<tl;i++){
		cin>>target[i];
	}
	
	printThetas(target);
	print2d(data);
	
	gd(thetas,data,target,tc,tl,lr);
	printThetas(thetas);
	

	
	
	
	return 0;
}