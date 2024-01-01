#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1}; // 상 하 좌 우
int i,j,k,x,y,nx,ny,dir;
stack <vector<int>> st;
int arr[26][26][4];
int n,cost,corner;
void dfs(vector<vector<int>> &board){
    st.push({0,0,0});
    for(k=0;k<4;k++){
        arr[0][0][k]=0;
    }
    while(!st.empty()){
        y=st.top()[0];
        x=st.top()[1];
        dir=st.top()[2];
        st.pop();
        
        for(i=0;i<4;i++){
            ny=y+dy[i];
            nx=x+dx[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n ||board[ny][nx]==1){
                continue;
            }
            cost=100;
            if(dir!=i){
                if(y!=0 || x!=0){
                    cost+=500;
                }
            }
            if(arr[ny][nx][i]>=arr[y][x][dir]+cost){
                arr[ny][nx][i]=arr[y][x][dir]+cost; 
                st.push({ny,nx,i});
            }
        }
    }
}
int solution(vector<vector<int>> board) {
    int answer = 1e9;
    n=board.size();
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<4;k++){
                if(arr[i][j][k]==1){continue;}
                arr[i][j][k]=1e9;  
            }
        }
    }    
    dfs(board);

    
    for(k=0;k<4;k++){
        if(answer>arr[n-1][n-1][k]){
            answer=arr[n-1][n-1][k];
        }
    }
    
    return answer;
}