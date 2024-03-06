// 2시간 
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define all(v) v.begin(),v.end()
int n,mid,sand,beforeS;
int arr[500][500];
int dy[4]={0,1,0,-1}; //좌 하 우 상
int dx[4]={-1,0,1,0}; //0 1 2 3
int dy2[4]={-1,1,0,0}; // 상 하 좌 우
int dx2[4]={0,0,-1,1};
int result;
// (r,c)에서 d 인덱스에 해당하는 방향으로 e의 배수만큼 s%의 모래가 움직인다.
void sandPlus(int r, int c, int d,int s,int e){
    int ty,tx;
    ty=r+dy2[d]*e;
    tx=c+dx2[d]*e;
    if(ty<0||ty>=n||tx<0||tx>=n){ // 격자를 넘어간 경우
        result+=trunc(sand*s*0.01);
    }
    else{
        arr[ty][tx]+=trunc(sand*s*0.01);
    }
    beforeS-=trunc(sand*s*0.01);
}

// 좌 0 : 1) x의 상하 1%, 2) y의 상하 2% 7%씩, 3) y의 왼쪽 나머지, 4) y의 왼쪽 상하 10%, 5)y의 왼 왼쪽 5% 
// 우 2 : x의 상하 1%, y의 상하 2% 7%씩, y의 오른쪽 나머지, y의 오른쪽 상하 10%, y의 오른 오른쪽 5%
// 하 1 : x의 좌우 1%, y의 좌우 2% 7%씩, y의 아래 나머지, y의 아래 좌우 10%, y의 아래 아래쪽 5%
// 상 3 : x의 좌우 1%, y의 좌우 2% 7%씩, y의 위 나머지, y의 위 좌우 10%, y의 위 위 5%
void sandMove(int idx, int y, int x){ // idx의 방향으로 y,x 좌표에서 모래 이동
    // y 좌표
    int ny=y+dy[idx];
    int nx=x+dx[idx]; 
    sand=arr[ny][nx];
    arr[ny][nx]=0;
    beforeS=sand;
    if(idx==0 || idx==2){
        // 1)
        for(int d=0;d<2;d++){
            sandPlus(y,x,d,1,1);
        }
        // 2) 
        for(int d=0;d<2;d++){
            sandPlus(ny,nx,d,7,1);
        }
        for(int d=0;d<2;d++){
            sandPlus(ny,nx,d,2,2);
        }
        // 4)
        for(int d=0;d<2;d++){
            sandPlus(ny+dy[idx],nx+dx[idx],d,10,1); //a 좌표 (ny+dy[idx],nx+dx[idx])
        }
        // 5)
        if(idx==0){
            sandPlus(ny+dy[idx],nx+dx[idx],2,5,1); //좌
        }
        if(idx==2){
            sandPlus(ny+dy[idx],nx+dx[idx],3,5,1); //우
        }
        // 3)
        int ay=ny+dy[idx];
        int ax=nx+dx[idx];
        if(ay<0||ay>=n||ax<0||ax>=n){ // 격자를 넘어간 경우
            result+=beforeS;
        }
        else{
            arr[ay][ax]+=beforeS;
        }
    }
    else if(idx==1 || idx==3){
        // 1)
        for(int d=2;d<4;d++){
            sandPlus(y,x,d,1,1);
        }
        // 2) 
        for(int d=2;d<4;d++){
            sandPlus(ny,nx,d,7,1);
        }
        for(int d=2;d<4;d++){
            sandPlus(ny,nx,d,2,2);
        }
      // 3)
        for(int d=2;d<4;d++){
            sandPlus(ny+dy[idx],nx+dx[idx],d,10,1); //a 좌표 (ny+dy[idx],nx+dx[idx])
        }
        // 5)
        if(idx==1){
            sandPlus(ny+dy[idx],nx+dx[idx],1,5,1); //하
        }
        if(idx==3){
            sandPlus(ny+dy[idx],nx+dx[idx],0,5,1); //상
        }
        int ay=ny+dy[idx];
        int ax=nx+dx[idx];
        if(ay<0||ay>=n||ax<0||ax>=n){ // 격자를 넘어간 경우
            result+=beforeS;
        }
        else{
            arr[ay][ax]+=beforeS;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }cout<<"\n";
    // }
}
void stormMove(){
    int y=mid;
    int x=mid;
    int flag=1;
    while(true){
        for(int i=0;i<2;i++){
            for(int j=0;j<flag;j++){
                sandMove(i,y,x);
                y+=dy[i];
                x+=dx[i];
            }
        }
        flag++;
        for(int i=2;i<4;i++){
            for(int j=0;j<flag;j++){
                sandMove(i,y,x);
                y+=dy[i];
                x+=dx[i];
            }
        }
        // 마지막 좌 하 우 상이 끝나고 한번만 실행되는 구문
        if(y==0 && flag==n-1){
            for(int j=0;j<flag;j++){

                sandMove(0,y,x);
                y+=dy[0];
                x+=dx[0];
                if(y==0 && x==0){
                    continue;
                }
            }
            break;
        }
        flag++;
    }
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        memset(arr[i],0,sizeof(int)*n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    mid=n/2;
    stormMove();
    cout<<result;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}