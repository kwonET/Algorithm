#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,a;
int arr[2001][2001];
int visited[2001][2001];
pair <int,int> fin;
queue <pair<int,int>> q;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
//bfs로 진행하되, 2인 곳에서 시작
//2에서 다른 정점까지의 최단거리를 bfs로 실행
void dfs(int i,int j){
    q.push({i,j});
    visited[i][j]=0;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(ny<0 ||nx<0||ny>=n||nx>=m||arr[ny][nx]==0){
                continue;
            }
            if((ny==fin.first&&nx==fin.second)||visited[ny][nx]!=0){
                continue;
            }
            q.push({ny,nx});
            visited[ny][nx]=visited[y][x]+1;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){memset(arr[i], 0, sizeof(int)* m);}
    for(int i=0; i<n; i++){memset(visited[i], 0, sizeof(int)* m);}
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a;
            if(a==2){
                fin={i,j};
            }
            arr[i][j]=a;
        }
    }
    dfs(fin.first,fin.second);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1 && visited[i][j]==0){
                cout<<-1<<" ";
            }
            else{
                cout<<visited[i][j]<<" ";
            }
        }cout<<"\n";
    }
    return 0;
}