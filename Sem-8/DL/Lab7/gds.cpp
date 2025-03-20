#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void mse(float w,float b,	vector<float>x_values,vector<float>y_values,int n){
	vector<float>y_cap(n,0);
	
	for(int i=0;i<n;i++){
		y_cap[i]=x_values[i]*w+b;
	}
	
	float sum=0;
	
	for(int i=0;i<n;i++){
		sum+=pow((y_values[i]-y_cap[i]),2);
	}
	
	float mse_value=sum/(2*n);
	
	cout<<mse_value<<endl;
	
	
}

// Stochastic Gradient Descent
void sgd(float w,float b,float neta,vector<float>x_values,vector<float>y_values,int n){
	
	float new_w=w;
	float new_b=b;
	
	for(int i=0;i<n;i++){
		float y_i_cap=x_values[i]*new_w+new_b;
		
		float do_w=-1*(y_values[i]-y_i_cap)*x_values[i];
		float do_b=-1*(y_values[i]-y_i_cap);
		
		new_w=new_w-(neta*do_w);
		new_b=new_b-(neta*do_b);
		
		
	}
	
	cout<<"Weight after one iteration for sgd "<<new_w<<" "<<new_b<<endl;
	cout<<"MSE for this w and b"<<endl;
	mse(new_w,new_b,x_values,y_values,n);
}


// Mini Batch Gradient Descent
void mgd(float w,float b,float neta,vector<float>x_values,vector<float>y_values,int n){
	
	cout<<"Enter momentum coeff"<<endl;
	float beta;
	cin>>beta;
	
	float v_w=0;
	float v_b=0;
	cout<<"Enter inital V_w & V_b"<<endl;
	cin>>v_w>>v_b;
	
	float new_w=w;
	float new_b=b;
	float new_v_w=v_w;
	float new_v_b=v_b;
	
	for(int i=0;i<n;i++){
		float y_i_cap=x_values[i]*new_w+new_b;
		
		float do_w=-1*(y_values[i]-y_i_cap)*x_values[i];
		float do_b=-1*(y_values[i]-y_i_cap);
		
		new_v_w=beta*new_v_w+neta*do_w;
		new_v_b=beta*new_v_b+neta*do_b;
		
		new_w=new_w-new_v_w;
		new_b=new_b-new_v_b;
		
		
	}
	cout<<"Weight after one iteration for mgd "<<new_w<<" "<<new_b<<endl;
	cout<<"MSE for this w and b"<<endl;
	mse(new_w,new_b,x_values,y_values,n);
	
	
	
	
	
}

// Adaptive Gradient Descent
void agd(float w,float b,float neta,vector<float>x_values,vector<float>y_values,int n){
	float new_w=w;
	float new_b=b;
	
	float alpha_t_w=0;
	float alpha_t_b=0;
	
	float epsilon=10e-8;
	
	for(int i=0;i<n;i++){
		float y_i_cap=x_values[i]*new_w+new_b;
		
		float do_w=-1*(y_values[i]-y_i_cap)*x_values[i];
		float do_b=-1*(y_values[i]-y_i_cap);
		
		//cout<<do_w<<endl;
		
		alpha_t_w+=pow(do_w,2);
		alpha_t_b+=pow(do_b,2);
		
		//cout<<alpha_t_w<<endl;
		
		float neta_1=neta/sqrt(alpha_t_w+epsilon);
		float neta_2=neta/sqrt(alpha_t_w+epsilon);
		
		//cout<<neta_1<<endl;
		
		new_w=new_w-neta_1*do_w;
		new_b=new_b-neta_2*do_b;
	
	}
	
	cout<<"Weight after one iteration for agd "<<new_w<<" "<<new_b<<endl;
	cout<<"MSE for this w and b"<<endl;
	mse(new_w,new_b,x_values,y_values,n);
}

int main(){
	float w,b,neta;
	cout<<"Enter w,b& neta"<<endl;
	cin>>w>>b>>neta;
	
	
	int tuple;
	cout<<"Enter number of tuple"<<endl;
	cin>>tuple;
	
	vector<float>x_values(tuple,0);
	cout<<"Enter x values"<<endl;
	for(int i=0;i<tuple;i++){
		cin>>x_values[i];
	}
	
	vector<float>y_values(tuple,0);
	cout<<"Enter y values"<<endl;
	for(int i=0;i<tuple;i++){
		cin>>y_values[i];
	}
	
	
	cout<<"MSE for initial values of w and b"<<endl;
	mse(w,b,x_values,y_values,tuple);
	
	sgd(w,b,neta,x_values,y_values,tuple);
	mgd(w,b,neta,x_values,y_values,tuple);
	agd(w,b,neta,x_values,y_values,tuple);
	
	
	
}