#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
using namespace std;
int n,result;
int col[16]={-1,};
bool isSafe(int r, int c){
    for(int i=0;i<r;i++){
        if(c==col[i]){return false;} //같은 열에 있다
        if(abs(r-i)==abs(c-col[i])){return false;} //열의 차이와 행의 차이가 같다
    }
    return true;
}
void nqueen(int r){
    if(r==n){
        result+=1;
        return;
    }
    for(int i=0;i<n;i++){// 행을 늘려가며, 이전 열에 있는 퀸과 겹치지 않게 개수를 센다
        if(!isSafe(r,i)) continue;
        col[r]=i;
        nqueen(r+1);
    }
}

int main(){
    cin>>n;
    nqueen(0);
    cout<<result<<"\n";
    return 0;
}