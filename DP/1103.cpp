#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,i,j;
char map[51][51];
bool visited[51][51];
int dp[51][51];
int dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1};
int M;

int dfs(int r, int c){
    if(visited[r][c]){
        printf("-1");
        exit(0);
    }
    if(dp[r][c]!=0){
        return dp[r][c];
    }

    visited[r][c]=1;
    int pos=map[r][c]-'0';

    for(int d=0;d<4;d++){
        int ny=r+dy[d]*pos; 
        int nx=c+dx[d]*pos;
        if(ny<0 || ny>=n||nx<0||nx>=m || map[ny][nx]=='H') continue;
        dp[r][c]=max(dp[r][c],dfs(ny,nx)+1);
    }
    visited[r][c]=0;
    return dp[r][c];
}
int main(){
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",&map[i]);
    }
     printf("%d",dfs(0,0)+1);
}