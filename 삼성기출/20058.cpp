// 9:55 시작

// A[r][c]가 0인 경우 얼음이 없는 것이다.
// 파이어스톰을 시전하려면 시전할 때마다 단계 L을 결정해야 한다. 
// 파이어스톰은 먼저 격자를 2L × 2L 크기의 부분 격자로 나눈다. 
// 그 후, 모든 부분 격자를 시계 방향으로 90도 회전시킨다. 
// 이후 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어든다.
// (r, c)와 인접한 칸은 (r-1, c), (r+1, c), (r, c-1), (r, c+1)이다. 
// 아래 그림의 칸에 적힌 정수는 칸을 구분하기 위해 적은 정수이다.

// 마법사 상어는 파이어스톰을 총 Q번 시전하려고 한다. 모든 파이어스톰을 시전한 후, 다음 2가지를 구해보자.
// 남아있는 얼음 A[r][c]의 합
// 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
// 얼음이 있는 칸이 얼음이 있는 칸과 인접해 있으면, 두 칸을 연결되어 있다고 한다. 덩어리는 연결된 칸의 집합이다.

// 첫째 줄에 N과 Q가 주어진다. 둘째 줄부터 2N개의 줄에는 격자의 각 칸에 있는 얼음의 양이 주어진다. 
// r번째 줄에서 c번째 주어지는 정수는 A[r][c] 이다.
// 마지막 줄에는 마법사 상어가 시전한 단계 L1, L2, ..., LQ가 순서대로 주어진다.

// 1) 90도 회전
// - 모든 칸 순회 하면서 얼음 여부 판단
// 2) 덩어리의 합
// 3) 얼음의 합 

#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
using ll=long long;
using pii =pair<int,int>;
using pll=pair<ll,ll>;
#define all(v) v.begin(),v.end()
int n,q,m,t,s,result,cnt;
int arr[65][65];
int tmp[65][65];
int check[65][65];
int visited[65][65];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int maxCnt=0;
void dfs(int r, int c){
    visited[r][c]=1;
    for(int d=0;d<4;d++){
        int ny=r+dy[d];
        int nx=c+dx[d];
        if(ny<0||ny>=m||nx<0||nx>=m || visited[ny][nx]==1 ||arr[ny][nx]==0){continue;}
        dfs(ny,nx);
        cnt++;
    }
}
void getAnswer(){ //dfs를 통해 가장 큰 덩어리 개수를 찾고, 얼음의 합을 도출
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            result+=arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        memset(visited[i],0,sizeof(int)*m);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && arr[i][j]!=0){
                cnt=1;
                dfs(i,j);
                if(cnt>maxCnt){
                    maxCnt=cnt;
                }
            }
        }
    }

    cout<<result<<"\n";
    cout<<maxCnt<<"\n";
}
void rotate(int r, int c){ //r,c을 기준으로 가로 세로 s만큼 크기의 블록을 오른쪽 90도로 회전
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            tmp[i][j]=arr[r+s-1-j][c+i];
        }
    }
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            arr[r+i][c+j]=tmp[i][j];
        }
    }
}
void preRotate(int t){
    s=pow(2,t); 
    for(int i=0;i<m;i++){
        memset(check[i],0,sizeof(int)*m);
    }
    for(int r=0;r<m;r++){
        for(int c=0;c<m;c++){
            if(c%s==0 && r%s==0){
                rotate(r,c);
            }
        }
    }
    for(int r=0;r<m;r++){
        for(int c=0;c<m;c++){
            // 이후 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어든다. 
            // (r, c)와 인접한 칸은 (r-1, c), (r+1, c), (r, c-1), (r, c+1)이다.
            if(arr[r][c]==0){
                continue;
            }
            int flag=0;
            for(int d=0;d<4;d++){
                int ny=r+dy[d];
                int nx=c+dx[d];
                if(ny<0||ny>=m||nx<0||nx>=m){continue;}
                if(arr[ny][nx]!=0){
                    flag++;
                }
            }
            if(flag<3){
                check[r][c]=1;
            }
        }
    } 
    for(int r=0;r<m;r++){
        for(int c=0;c<m;c++){
            if(check[r][c]==1){
                arr[r][c]-=1;
            }
        }
    }
}
void solve(){
    cin>>n>>q;
    m=pow(2,n);
    for(int i=0;i<m;i++){
        memset(arr[i],0,sizeof(int)*m);
    }
    for(int i=0;i<m;i++){
        memset(tmp[i],0,sizeof(int)*m);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int a=0;a<q;a++){
        cin>>t;
        preRotate(t);
    }
    getAnswer();
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}