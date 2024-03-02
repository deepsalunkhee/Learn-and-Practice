#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void ISGS(vector<vector<int> >&IS,vector<vector<int> >&GS){
	cout<<"NOTE: To enter blank use 0"<<endl;
	cout<<"Pls enter the Goal state"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>GS[i][j];
		}
	}
	
	cout<<"Pls enter the Initial state"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>IS[i][j];
		}
	}
	
}

void display2d(vector<vector<int> >v){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool goalReached(vector<vector<int> >&IS,vector<vector<int> >&GS){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		  if(IS[i][j]!=GS[i][j])
		  return false;
		}
		
	}
	
	return true;
}

void moveUp(vector<vector<int> >&IS,vector<vector<int> >&GS){
	
	int xb;
	int yb;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(IS[i][j]==0){
                //cout<<"Deep Salunkhe"<<endl; 
				xb=i;
				yb=j;
			}
		}
	}
	
	if(xb==0)
	cout<<"Cant go any up"<<endl;
	else{
		swap(IS[xb][yb],IS[xb-1][yb]);
	}
	
}

void moveRight(vector<vector<int> >&IS,vector<vector<int> >&GS){
	
	int xb;
	int yb;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(IS[i][j]==0){
				xb=i;
				yb=j;
			}
		}
	}
	
	if(yb==2)
	cout<<"Cant go any right"<<endl;
	else{
		swap(IS[xb][yb],IS[xb][yb+1]);
	}
	
}
void moveDown(vector<vector<int> >&IS,vector<vector<int> >&GS){
	
	int xb;
	int yb;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(IS[i][j]==0){
				xb=i;
				yb=j;
			}
		}
	}
	
	if(xb==2)
	cout<<"Cant go any Down"<<endl;
	else{
		swap(IS[xb][yb],IS[xb+1][yb]);
	}
	
}
void moveLeft(vector<vector<int> >&IS,vector<vector<int> >&GS){
	
	int xb;
	int yb;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(IS[i][j]==0){
				xb=i;
				yb=j;
			}
		}
	}
	
	if(yb==0)
	cout<<"Cant go any Left"<<endl;
	else{
		swap(IS[xb][yb],IS[xb][yb-1]);
	}
	
}

int heuristic(vector<vector<int> >&IS,vector<vector<int> >&GS){
	int value=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int curr_ele=IS[i][j];
			int cex=i;
			int cey=j;
			int fx;
			int fy;
			if(curr_ele==0)
			continue;
			for(int x=0;x<3;x++){
				for(int y=0;y<3;y++){
					if(GS[x][y]==curr_ele){
						value=value+abs(cex-x)+abs(cey-y);
					}
				}
			}
		}
	}
	
	return value;
}

int main(){
	vector<vector<int> >IS(3,vector<int>(3,0));
	vector<vector<int> >GS(3,vector<int>(3,0));
	ISGS(IS,GS);
	
	
	while(!goalReached(IS,GS)){
		cout<<"Goal State is"<<endl;
		display2d(GS);
		cout<<"Current State is"<<endl;
		display2d(IS);
		int hvalue=heuristic(IS,GS);
		cout<<"heuristic value :"<<hvalue<<endl;
		
		
		cout<<"What should we do with the blank(-1)"<<endl;
		cout<<"1. Move UP"<<endl;
		cout<<"2. Move RIGHT"<<endl;
		cout<<"3. Move DOWN"<<endl;
		cout<<"4. Move LEFT"<<endl;
		
		int choice;
		cin>>choice;
		switch(choice){
			case 1: moveUp(IS,GS);
					break;
			case 2: moveRight(IS,GS);
					break;
			case 3: moveDown(IS,GS);
					break;
			case 4: moveLeft(IS,GS);
					break;
		    default:cout<<"Invalid choice"<<endl;
		}
		
			if(!goalReached(IS,GS)){
			cout<<"Goal State is"<<endl;
			display2d(GS);
			cout<<"Current State is"<<endl;
			display2d(IS);
			int hvalue=heuristic(IS,GS);
			cout<<"heuristic value :"<<hvalue<<endl;
		}
		
		
	}
	
	cout<<"You have completed task"<<endl;
	
	
	return 0;
}