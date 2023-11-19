#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int i,j,k;
int solution(int alp, int cop, vector<vector<int>> problems) {
    n=-1; m=-1;
    for(auto p: problems){ // 알고력, 코딩력의 최댓값을 각각 n,m에 저장
        if(n<p[0]){
            n=p[0];
        }
        if(m<p[1]){
            m=p[1];
        }
    }
    if(alp>=n && cop>=m){ // 이미 달성한 경우는 0의 시간이 걸림
        return 0;
    }
    vector<vector<int>> a(n+1, vector<int>(m+1,1e9));// n x m 크기의 알고력 x 코딩력을 달성하는 데 걸리는 시간을 저장
    
    // 코딩력, 알고력 중 하나만 이미 달성한 경우엔 최댓값이 이미 달성한 것으로 생각 (아래 for문을 위해)
    if(alp>n){
        alp=n; 
    }
    if(cop>m){
        cop=m;
    }
    a[alp][cop]=0;
    for(i=alp;i<=n;i++){
        for(j=cop;j<=m;j++){
            if(j+1<=m){  //알고리즘 공부
                a[i][j+1]=min(a[i][j]+1,a[i][j+1]);
            }
            if(i+1<=n){ //코딩공부
                a[i+1][j]=min(a[i][j]+1,a[i+1][j]);
            } 
            // 문제를 푸는 경우
            for(auto p:problems){
                if(p[0]<=i && p[1]<=j){
                    a[min(i+p[2],n)][min(j+p[3],m)]=min(a[min(i+p[2],n)][min(j+p[3],m)],a[min(i,n)][min(j,m)]+p[4]);   
                }
            }
        }
    }
    int answer=a[n][m];
    return answer;
}