#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
// 입력은 여러 개의 테스트 케이스로 이루어져 있다. 
// 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. w와 h는 50보다 작거나 같은 양의 정수이다.
// 둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.
// 입력의 마지막 줄에는 0이 두 개 주어진다.
int w,h,n,result;
vector<int> answer;
int arr[51][51];
int visited[51][51];
int dy[8]={-1,-1,-1,1,1,1,0,0}; // 상하좌우 대각선
int dx[8]={-1,0,1,-1,0,1,-1,1}; 
void find(int c,int r){
    if(visited[c][r]==1){return ;}
    visited[c][r]=1;
    for(int k=0;k<9;k++){
        int y=c+dy[k];
        int x=r+dx[k];
        if(y<0 ||x<0 ||y>=h||x>=w||arr[y][x]==0){ continue; }
        find(y,x);
    }
}
int main(){
    while(true){
        cin>>w>>h;
        if(w==0 && h==0){
            for(int p=0;p<answer.size();p++){
                cout<<answer[p]<<" ";
            }
            return 0;
        }
        result=0;
        for(int i=0; i<h; i++){memset(arr[i], 0, sizeof(int)* w);}
        for(int i=0; i<h; i++){memset(visited[i], 0, sizeof(int)* w);}
        // memset(arr,0,sizeof(arr));
        // memset(visited,0,sizeof(visited));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>n;
                arr[i][j]=n;
            }
        }   
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(visited[i][j]==0 && arr[i][j]==1){
                    find(i,j);
                    result+=1;
                }
            }
        }
        answer.push_back(result); 
    }
}
// 0
// 1
// 1
// 3
// 1
// 9