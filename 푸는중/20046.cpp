//맨 왼쪽 위 단위 격자에서 맨 오른쪽 아래 단위 격자로 도시의 차들이 가는 경로를 
//만들기 위해 필요한 최소한의 도로 건설 비용

//각 열의 정보는 정수 0, 1, 2, -1 로 나타내며 
//0 은 단위도로가 이미 존재하는 것을, 즉, 도로에 유실이 없는 상태, 
//1 은 단위 도로가 없고 1 의 비용으로 도로를 건설할 수 있는 단위 격자,
//2 는 단위 도로가 없고 2 의 비용으로 도로를 건설할 수 있는 단위 격자를 의미한다
// -1 은 X로 표시된 단위 격자로 그 위치에 단위 도로를 건설할 수 없는 상태를 의미한다.

// #include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll=long long;
using pii =pair<int,int>;
using pll=pair<ll,ll>;
#define all(v) v.begin(),v.end()
int n,m,a;
int arr[1001][1001];
int cost[1001][1001];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
struct elem{
    int y;
    int x;
    int c;
};
struct cmp{
    bool operator()(elem a, elem b){
        a.c>b.c; // 오름차순
    }
};
priority_queue <elem,vector<elem>,cmp> q;
void solve(){
    if(arr[0][0]==-1||arr[n][m]==-1){
        cout<<"-1";
        return;
    }
    cost[0][0]=arr[0][0];
    q.push({0,0,cost[0][0]});
    while(!q.empty()){
        int i=q.top().y;
        int j=q.top().x;
        int ccost=q.top().c;
        q.pop();
        if(cost[i][j]<=ccost){
            continue;
        }
        cost[i][j]=ccost;
        if (i==n-1 && j==m-1){
            break;
        }
        for(int d=0;d<4;d++){
            int ny=i+dy[d];
            int nx=j+dx[d];
            if(ny<0 || nx<0 || ny>=n||nx>=m){ continue; }
            if(arr[ny][nx]==-1){continue;}
            int ncost=ccost+arr[ny][nx];
            if(cost[ny][nx]>ncost){
                q.push({ny,nx,ncost});
            }
        }   
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){memset(arr[i],0,sizeof(int)*m);}
    // for(int i=0;i<n;i++){memset(cost[i],-1,sizeof(int)*m);}
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cost[i][j]=1e9;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a;
            arr[i][j]=a;
        }
    }
    int T=1; //cin>>T;
    while(T--) solve();
    if(cost[n-1][m-1]==1e9){
        cout<<-1;
        return 0;
    }
    cout<<cost[n-1][m-1];
    return 0;
}