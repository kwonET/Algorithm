#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define MAX 987654321
using namespace std;
int w,h,i,j;
vector <int> cpoint;
char c;
char map[101][101];
int D[101][101][4];
int visited[101][101][4];
queue <vector<int>> q;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

int bfs(){
    int si=cpoint[0];
    int sj=cpoint[1];
    map[si][sj]='c';
    q.push({si,sj,-1});
    fill(&D[0][0][0],&D[100][100][4],MAX);
    fill(&visited[0][0][0],&visited[100][100][4],0);
    for(int i=0;i<4;i++){
        D[si][sj][i]=0;
        visited[si][sj][i]=1;
    }
    while(!q.empty()){
        int y=q.front()[0];
        int x=q.front()[1];
        int dir=q.front()[2];
        q.pop(); 
        for(int d=0;d<4;d++){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(ny<0||ny>=h||nx<0||nx>=w) continue;
            if(map[ny][nx]=='*')continue;
            if(dir==d){ //1. 방향이 같은 경우
                if(visited[ny][nx][d]==0){ //처음 방문한 경우
                    D[ny][nx][d]=D[y][x][dir]; //무조건 갱신
                    visited[ny][nx][d]=1;
                    q.push({ny,nx,d});
                }
                else{ // 다시 방문한 경우
                    if(D[ny][nx][d]>D[y][x][dir]){ //다시 방문한 경우에도 경로마다 꺾은 횟수가 다르기 때문에 비교 -> 클 때만 업데이트
                        D[ny][nx][d]=D[y][x][dir];
                        q.push({ny,nx,d});
                    }
                }
            }
            else{ //2. 방향이 다른 경우
                if(dir==-1){dir=d;}
                if(visited[ny][nx][d]==0){ 
                    D[ny][nx][d]=D[y][x][dir]+1;
                    visited[ny][nx][d]=1;
                    q.push({ny,nx,d});
                }
                else{       
                    if(D[ny][nx][d]>D[y][x][dir]+1){ 
                        D[ny][nx][d]=D[y][x][dir]+1;
                        q.push({ny,nx,d});
                    }
                }
            }
            
        }

    }

    //C에 도달하더라도 queue에 대한 탐방은 계속되어야
    int result=987654321;
    int ei=cpoint[2];
    int ej=cpoint[3];
    for(int n=0;n<4;n++){
        if(result>D[ei][ej][n]){
            result=D[ei][ej][n];
        }
    }
    return result;   
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>w>>h;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin>>c;
            map[i][j]=c;
            if(c=='C'){
                cpoint.push_back(i);
                cpoint.push_back(j);
            }
        }
    }
    int result=bfs();
    cout<<result-1<<"\n";
    // int tmp;
    // for(int i=0;i<h;i++){
    //     for(int j=0;j<w;j++){
    //         tmp=1e9;
    //         for(int k=0;k<4;k++){
    //             if(tmp>D[i][j][k]){
    //                 tmp=D[i][j][k];
    //             }
    //         }
    //         cout<<tmp<<" ";
    //     }cout<<"\n";
    // }
    return 0;
}