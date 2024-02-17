#include<iostream>
using namespace std;

int gcd(int x,int y){
	
	if(y==0)
	return x;
	else
	return gcd(y,x%y);
}

bool ispossible(int x,int y,int d){
	int valgcd=gcd(x,y);
	if(d%valgcd==0)
	return true;
	return false;
}

void fillx(int &xState,int &xcapacity){
	xState=xcapacity;
}

void emptyy(int &yState,int ycapacity){
	yState=0;
}

void transfer_x_to_y(int &xState,int &yState,int &xcapacity,int &ycapacity){
	
	int y_can_take=(ycapacity-yState);
	if(y_can_take>=xState){
		yState=yState+xState;
		xState=0;
	}else{
		xState=xState-y_can_take;
		yState=ycapacity;
		
	}
}

int main(){
	
	int xcapacity,ycapacity,finalx;
	int xState=0,yState=0;
	bool possible=true;
	cout<<"Enter capacity for first container"<<endl;
	cin>>xcapacity;
	
	cout<<"Enter capacity for second container"<<endl;
	cin>>ycapacity;
		
	cout<<"Enter Final state of first container"<<endl;
	cin>>finalx;
	
	possible=ispossible(xcapacity,ycapacity,finalx);
	if(!possible){
		cout<<"Not possible"<<endl;
		return 0;
	}
	
	cout<<"X"<<" "<<"Y"<<endl;
	
	while(xState!=finalx){
		if(xState==0){
			fillx(xState,xcapacity);
		}else if(yState==ycapacity){
			emptyy(yState,ycapacity);
		}else{
			transfer_x_to_y(xState,yState,xcapacity,ycapacity);
		}
		
		cout<<xState<<" "<<yState<<endl;
		if(xState==finalx ||  yState==finalx ){
			cout<<"congratulation"<<endl;
			return 0;
		}
		
	}
	
	
	
	
	return 0;
}