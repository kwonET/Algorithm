#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
using namespace std;
int n,m;
char c;
char arr[1001][1001];
// vector<pair<int,int>,vector<pair<int,int>>> arr; //(0,0) -> {(1,1),(1,0)}
int visited[1001][1001];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
map<char, int> dir;
stack <pair<int,int>> st;
int result=0;
void dfs(int r,int c){
    visited[r][c]=1;
    int d=dir[arr[r][c]];
    int ny=r+dy[d];
    int nx=c+dx[d];
    if(visited[ny][nx]==1){
        result+=1;
    }
    if(visited[ny][nx]==0){
        dfs(ny,nx);
    }
    visited[r][c]=2;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            arr[i][j]=c;
        }
    }
    dir['U']=0;
    dir['D']=1;
    dir['L']=2;
    dir['R']=3;
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(visited[r][c]==0){
                dfs(r,c);
            }
        }
    }
    cout<<result;
    return 0;
}