// 11:25 시작

// 오늘은 비바라기를 크기가 N×N인 격자에서 연습하려고 한다. 격자의 각 칸에는 바구니가 하나 있고, 바구니는 칸 전체를 차지한다. 
// 바구니에 저장할 수 있는 물의 양에는 제한이 없다. (r, c)는 격자의 r행 c열에 있는 바구니를 의미하고, A[r][c]는 (r, c)에 있는 바구니에 저장되어 있는 물의 양을 의미한다.

// 격자의 가장 왼쪽 윗 칸은 (1, 1)이고, 가장 오른쪽 아랫 칸은 (N, N)이다. 
// 마법사 상어는 연습을 위해 1번 행과 N번 행을 연결했고, 1번 열과 N번 열도 연결했다. 

// 비바라기를 시전하면 (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름이 생긴다. 
// 이제 구름에 이동을 M번 명령하려고 한다. i번째 이동 명령은 방향 di과 거리 si로 이루어져 있다. 
// 방향은 총 8개의 방향이 있으며, 8개의 정수로 표현한다. 1부터 순서대로 ←, ↖, ↑, ↗, →, ↘, ↓, ↙ 이다. 이동을 명령하면 다음이 순서대로 진행된다.

// 1. 모든 구름이 di 방향으로 si칸 이동한다.
// 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
// 3. 구름이 모두 사라진다.
// 4. 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다. 
//     물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다.    
//     이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
// 5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
// 6. M번의 이동이 모두 끝난 후 바구니에 들어있는 물의 양의 합을 구해보자.

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
int n,m,D,S,result;
int y,x,ny,nx;
int arr[51][51];
int visited[51][51];
int dy[8]={0,-1,-1,-1,0,1,1,1};
int dx[8]={-1,-1,0,1,1,1,0,-1};
int d2y[4]={-1,-1,1,1};
int d2x[4]={-1,1,1,-1};
vector <pair<int,int>> cloud;
void initVisit(){
    for(int v=0;v<n;v++){
        memset(visited[v],0,sizeof(int)*n);
    }
    for(auto c:cloud){
        y=c.first;
        x=c.second;
        visited[y][x]=1;
    }
}
void play(int D,int S){
    for(int c=0;c<cloud.size();c++){
        y=cloud[c].first;
        x=cloud[c].second;
        for(int s=0;s<S;s++){
            y+=dy[D-1];
            x+=dx[D-1];
            if(y>n-1){y=0;}
            if(y<0){y=n-1;}
            if(x>n-1){x=0;}
            if(x<0){x=n-1;}
        }
        cloud[c]={y,x};
        arr[cloud[c].first][cloud[c].second]+=1;
    }

    initVisit();
    for(auto c:cloud){
        int flag=0;
        y=c.first;
        x=c.second;
        for(int d=0;d<4;d++){
            ny=y+d2y[d];
            nx=x+d2x[d];
            if(ny<0||ny>=n||nx<0||nx>=n){
                continue;
            }
            if(arr[ny][nx]>0){
                flag++;
            }
        }
        arr[y][x]+=flag;
    }
    cloud.clear();
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            if(arr[r][c]>=2 && visited[r][c]==0){
                cloud.push_back({r,c});
                arr[r][c]-=2;
            }
        }
    }  
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        memset(arr[i],0,sizeof(int)*n);
    }
    int t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>t;
            arr[i][j]=t;
        }
    }
    // (N, 1), (N, 2), (N-1, 1), (N-1, 2)
    cloud.push_back({n-1,0});
    cloud.push_back({n-1,1});
    cloud.push_back({n-2,0});
    cloud.push_back({n-2,1});
    for(int i=0;i<m;i++){
        cin>>D>>S;
        play(D,S);
    }
    for(int ii=0;ii<n;ii++){
        for(int j=0;j<n;j++){
            result+=arr[ii][j];
        }
    }
    cout<<result;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}