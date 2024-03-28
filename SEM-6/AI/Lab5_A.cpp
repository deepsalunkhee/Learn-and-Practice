#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


void printmaze(vector<vector<float> >maze){
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			cout<<float(maze[i][j])<<"        ";
		}
		cout<<endl;
		cout<<endl;
		cout<<endl;
	}
	
	return ;
}


float EU(int ri,int ci,int rf,int cf){
	float val=0;
	val=sqrt(abs(ri-rf)*abs(ri-rf)+abs(ci-cf)*abs(ci-cf));
	return val;
}

float MH(int ri,int ci,int rf,int cf){
	float val=0;
	val=abs(ri-rf)+abs(ci-cf);
	return val;
}

void calf(vector<vector<float> >&maze){
		for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			if(maze[i][j]==-1) continue;
			
			maze[i][j]=max(i,j)+EU(i,j,3,7);
		}
		
	}
}

void findpath(vector<vector<float> >maze,vector<vector<int> >&visted){
    vector<vector<int> >dir={{1,1},{1,0},{0,1},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1}};
    
    int isr=0;
    int isc=0;
    int fsr=3;
    int fsc=7;
    float minf=maze[0][0];
   
    cout<<"("<<isr<<","<<isc<<")->";
    
    while(isr!=3 || isc!=7){ // Changed '&&' to '||' in the loop condition
       for(auto x:dir){
            int nr=isr+x[0];
            int nc=isc+x[1]; // Corrected the variable used for column index
            //cout<<nr<<" "<<nc<<endl;
            if(nr<=3 && nr>=0 && nc<=7 && nc>=0 && maze[nr][nc]!=-1.0000 && visted[nr][nc]==0){
                //cout<<"("<<nr<<","<<nc<<")->";
                //cout<<maze[nr][nc]<<endl;
                //cout<<"Deep Salunkhe"<<endl;
                if(maze[nr][nc]<=minf){
                    
                    //mark as visited
                    visted[isr][isc]=1;
                    minf=maze[nr][nc];
                    isr=nr;
                    isc=nc;
                    cout<<"("<<isr<<","<<isc<<")->";
                }
            }
       }
    }
    
    cout<<"("<<isr<<","<<isc<<")"<<endl;
}


int main(){
	
  vector<vector<float> >maze(4,vector<float>(8,0));
  maze[2][0]=-1.0000;
  maze[3][0]=-1.0000;
  maze[2][1]=-1.0000;
  maze[2][3]=-1.0000;
  maze[0][4]=-1.0000;
  maze[2][4]=-1.0000;
  maze[0][5]=-1.0000;
  maze[1][5]=-1.0000;
  maze[0][6]=-1.0000;
  maze[1][6]=-1.0000;
  maze[0][7]=-1.0000;
  maze[1][7]=-1.0000;

  //definging a visterd vector
    vector<vector<int> >visted(4,vector<int>(8,0));
  
  cout<<"The Maze is"<<endl;
  printmaze(maze);
  cout<<"lets build the f valued matrix"<<endl;
  calf(maze);
  
  printmaze(maze);
  findpath(maze,visted);
  
  return 0;
  
  
}