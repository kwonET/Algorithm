//30분
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
using namespace std;
// 3^k가 1이 될 때까지 //3을 해서 
// 2차원을 순회하면서 다른 배열이 나온다면 바로
int zero, one, minus,n;
map <int,int> arr;
vector <vector<int>> paper;
bool check(int n,int y,int x){
    int flag=paper[y][x];
    for(int i=y;i<n+y;i++){
        for(int j=x;j<n+x;j++){ 
            if(paper[i][j]!=flag){
                return false;
            }
        }
    }
    return true;
}
void three(int n,int y,int x){
    if(check(n,y,x)){
        arr[paper[y][x]]++;
    }
    else{
        n=n/3;
        for(int k=0;k<3;k++){
            for(int p=0;p<3;p++){
                three(n,y+k*n,x+p*n);
            }
        }
    }
}
int main(){
    cin>>n;
    int a;
    for(int i=0;i<n;i++){
        vector <int> tmp;
        for(int j=0;j<n;j++){
            cin>>a;
            tmp.push_back(a);
        }
        paper.push_back(tmp);
    }

    three(n,0,0);
    cout<<arr[-1]<<"\n";
    cout<<arr[0]<<"\n";
    cout<<arr[1]<<"\n";
    return 0;
}