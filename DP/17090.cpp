#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,cnt,dp[501][501];
char map[501][501];

int dfs(int r, int c){
    if(r<0||r>=n||c<0||c>=m){
        return 1;
    }
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    dp[r][c]=0;
    if(map[r][c]=='D'){
        dp[r][c]=dfs(r+1,c);
    }
    else if(map[r][c]=='U'){
        dp[r][c]=dfs(r-1,c);
    }
    else if(map[r][c]=='R'){
        dp[r][c]=dfs(r,c+1);
    }
    else if(map[r][c]=='L'){
        dp[r][c]=dfs(r,c-1);
    }
    return dp[r][c];
}
int main(){
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",&map[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            dp[i][j]=-1;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(dp[i][j]==-1){
                dfs(i,j);
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cnt+=dp[i][j];
        }
    }
    printf("%d\n",cnt);
    return 0;
}