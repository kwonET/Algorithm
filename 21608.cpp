
// 2월 28일 11:30 ~ 12:30
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using ll=long long;
using pii =pair<int,int>;
using pll=pair<ll,ll>;
#define all(v) v.begin(),v.end()
// 상어 초등학교에는 교실이 하나 있고, 교실은 N×N 크기의 격자로 나타낼 수 있다. 학교에 다니는 학생의 수는 N2명이다. 오늘은 모든 학생의 자리를 정하는 날이다. 학생은 1번부터 N2번까지 번호가 매겨져 있고, (r, c)는 r행 c열을 의미한다. 교실의 가장 왼쪽 윗 칸은 (1, 1)이고, 가장 오른쪽 아랫 칸은 (N, N)이다.
// 선생님은 학생의 순서를 정했고, 각 학생이 좋아하는 학생 4명도 모두 조사했다. 
// 이제 다음과 같은 규칙을 이용해 정해진 순서대로 학생의 자리를 정하려고 한다. 
// 한 칸에는 학생 한 명의 자리만 있을 수 있고, |r1 - r2| + |c1 - c2| = 1을 만족하는 두 칸이 (r1, c1)과 (r2, c2)를 인접하다고 한다.

// 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
// 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
// 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.

// 첫째 줄에 N이 주어진다. 둘째 줄부터 N2개의 줄에 학생의 번호와 그 학생이 좋아하는 학생 4명의 번호가 한 줄에 하나씩 선생님이 자리를 정할 순서대로 주어진다.
// 학생의 번호는 중복되지 않으며, 어떤 학생이 좋아하는 학생 4명은 모두 다른 학생으로 이루어져 있다. 
// 입력으로 주어지는 학생의 번호, 좋아하는 학생의 번호는 N2보다 작거나 같은 자연수이다. 어떤 학생이 자기 자신을 좋아하는 경우는 없다.
int n,self,result;
int arr[21][21];
int pref[4];
int preArr[401][4];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
// 학생 별로 n*n 칸을 돌면서 1,2,3번 조건에 맞게 칸에 배치해나가는 함수
void search(int s){
    pair<pair<int,int>,pair<int,int>> resultp;
    resultp={{0,0},{-1,-1}};
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            // 비어있는 칸 중 인접한 칸에 대해
            if(arr[r][c]==0){ 
                int p=0;
                int e=0;
                for(int d=0;d<4;d++){
                    int ny=r+dy[d];
                    int nx=c+dx[d];
                    if(ny>=n||ny<0||nx>=n||nx<0){continue;}
                    // 빈칸인 경우
                    if(arr[ny][nx]==0){
                        e++;
                    }
                    else{
                        for(int k=0;k<4;k++){
                            // self가 선호하는 학생이 있는 경우
                            if(arr[ny][nx]==pref[k]){
                                p++;
                                break;
                            }
                        }   
                    }
                }
                if(resultp.first.first<p){
                    resultp={{p,e},{r,c}};
                }
                else if(resultp.first.first==p&&resultp.first.second<e){
                    resultp={{p,e},{r,c}};
                }
                else if(resultp.second.first==-1 && resultp.second.second==-1){
                    resultp={{p,e},{r,c}};
                }
                
                // cout<<p<<" " <<e<<" "<<r<<" "<<c<<"\n";
            }
        }
    }
    int row=resultp.second.first;
    int col=resultp.second.second;
    arr[row][col]=self;
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }cout<<"\n";
    // }
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        memset(arr[i],0,sizeof(int)*n);
        memset(preArr[i],0,sizeof(int)*4);
    }
    memset(pref,0,sizeof(int)*n);
    for(int i=0;i<n*n;i++){
        cin>>self;
        for(int j=0;j<4;j++){
            cin>>pref[j];
            preArr[self][j]=pref[j];
        }
        search(self);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int pr=0;
            for(int d=0;d<4;d++){
                int ny=i+dy[d];
                int nx=j+dx[d];
                if(ny>=n||ny<0||nx>=n||nx<0){continue;}  
                for(int k=0;k<4;k++){
                    // self가 선호하는 학생이 있는 경우
                    if(arr[ny][nx]==preArr[arr[i][j]][k]){
                        pr++;
                        break;
                    }
                }   
            }
            if(pr==0){
                result+=0;
            }
            else{
                result+=pow(10,pr-1);
            }
        }
    }
    cout<<result;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}