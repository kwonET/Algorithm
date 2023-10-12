#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,i,j, arr[100001][4], DP[4];
int maxX(int a, int b, int c){
    int maX=a;
    if(maX<b){ maX=b;}
    if(maX<c){ maX=c;}
    return maX;
}
int minX(int a, int b, int c){
    int minX=a;
    if(minX>b){ minX=b;}
    if(minX>c){ minX=c;}
    return minX;
}
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    // 최대값
    DP[0]=arr[0][0]; DP[1]=arr[0][1]; DP[2]=arr[0][2]; 
    for(i=1;i<n;i++){
        int d1=DP[0]; int d2=DP[1]; int d3=DP[2];
        //case 1
        DP[0]=max(d1+arr[i][0],d2+arr[i][0]);
         //case 2
        DP[1]=maxX(d1+arr[i][1],d2+arr[i][1],d3+arr[i][1]);
        //case 3
        DP[2]=max(d2+arr[i][2],d3+arr[i][2]);
    }
    int maxR=-1e9;
    for(i=0;i<3;i++){
        if(maxR<DP[i]){
            maxR=DP[i];
        }
    }

    //최솟값
    DP[0]=arr[0][0]; DP[1]=arr[0][1]; DP[2]=arr[0][2]; 
    for(i=1;i<n;i++){
        int d1=DP[0]; int d2=DP[1]; int d3=DP[2];
        //case 1
        DP[0]=min(d1+arr[i][0],d2+arr[i][0]);
         //case 2
        DP[1]=minX(d1+arr[i][1],d2+arr[i][1],d3+arr[i][1]);
        //case 3
        DP[2]=min(d2+arr[i][2],d3+arr[i][2]);
    }
    int minR=1e9;
    for(i=0;i<3;i++){
        if(minR>DP[i]){
            minR=DP[i];
        }
    }

    printf("%d %d",maxR,minR);
    return 0;
}