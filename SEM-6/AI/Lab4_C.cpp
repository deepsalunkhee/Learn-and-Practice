#include<iostream>
#include<vector>
#include<map>
#include<math.h>
using namespace std;


bool moveUp(vector<vector<int> >&IS,vector<vector<int> >&GS){
	
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
	
	if(xb==0){
	 return false;
	}
	else{
		swap(IS[xb][yb],IS[xb-1][yb]);
		return true;
	}
	
}

bool moveRight(vector<vector<int> >&IS,vector<vector<int> >&GS){
	
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
	return false;
	else{
		swap(IS[xb][yb],IS[xb][yb+1]);
		return true;
	}
	
}
bool moveDown(vector<vector<int> >&IS,vector<vector<int> >&GS){
	
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
	return false;
	else{
		swap(IS[xb][yb],IS[xb+1][yb]);
		return true;
	}
	
}
bool moveLeft(vector<vector<int> >&IS,vector<vector<int> >&GS){
	
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
	return false;
	else{
		swap(IS[xb][yb],IS[xb][yb-1]);
		return true;
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

void generateOptions(vector<vector<int> >&IS,vector<vector<int> >&GS,	vector<vector<vector<int> > >&options,	map<vector<vector<int> >,bool>&visited){
	

		vector<vector<int> >currsu=IS;
		vector<vector<int> >currsr=IS;
		vector<vector<int> >currsd=IS;
		vector<vector<int> >currsl=IS;
	
		if(moveUp(currsu,GS)){
		  
		  if(visited.find(currsu)==visited.end())
		  {
		  	options.push_back(currsu);
		  
		   visited[currsu]=false;
		  }
		  
		  
		}
		
		if(moveRight(currsr,GS)){
			if(visited.find(currsr)==visited.end())
		  {
		  options.push_back(currsr);
		  visited[currsr]=false;
	}
		  
		}
		
		if(moveDown(currsd,GS)){
			if(visited.find(currsd)==visited.end())
		  {
		  options.push_back(currsd);
		  visited[currsd]=false;
	}
		  
		}
		
		if(moveLeft(currsl,GS)){
			if(visited.find(currsl)==visited.end())
		  {
		  options.push_back(currsl);
		  visited[currsl]=false;
	}
		  
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

void print3d(vector<vector<vector<int> > >options,map<vector<vector<int> >,bool> &visited,	vector<vector<int> >GS){
	int n=options.size();
	for(int i=0;i<n;i++){
	  if(visited[options[i]]==false){
	  	cout<<"option :"<<i<<endl;
	  	 display2d(options[i]);
	  	 int h=heuristic(options[i],GS);
	  	 cout<<"herustic value: "<<h<<endl;	  }
	 
	}
}


int main(){
	vector<vector<int> >IS={{2,8,3},{1,6,4},{7,0,5}};
	vector<vector<int> >GS={{1,2,3},{8,0,4},{7,6,5}};
	vector<vector<vector<int> > >options;
	map<vector<vector<int> >,bool>visited;
	cout<<"Goal state is"<<endl;
	display2d(GS);
	cout<<"Intial state is"<<endl;
	display2d(IS);
	
	while(true){
		
		generateOptions(IS,GS,options,visited);
		cout<<"Options"<<endl;
		print3d(options,visited,GS);
		cout<<"select one of the options"<<endl;
		int ind;
		cin>>ind;
		IS=options[ind];
		visited[IS]=true;
		
		if(goalReached(IS,GS)){
			cout<<"Congrats the goal is reached"<<endl;
			break;
		}
	}
	
	
}