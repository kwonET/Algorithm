// #include <bits/stdc++.h
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
using ll=long long;
using pii =pair<int,int>;
using pll=pair<ll,ll>;
#define all(v) v.begin(),v.end()
int n,k,step;
deque <int> arr;
deque <int> robot;
int validCur(int c){
    if(c<0){
        return 2*n-1;
    }else if(c>2*n-1){
        return 0;
    }else{
        return c;
    }
}
// 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
// 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
// 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
// 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
// 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
void robotPut(){
    robot[n-1]=0;
    for(int i=n-2;i>=0;i--){
        if(arr[i+1]>=1 && robot[i+1]==0 && robot[i]==1){
            robot[i+1]=1;
            robot[i]=0;
            arr[i+1]-=1;
        }
    }
    robot[n-1]=0;
    if(arr[0]>0&&robot[0]==0){
        robot[0]=1;
        arr[0]-=1;
    }
}
void robotMove(){
    arr.push_front(arr.back());
    arr.pop_back();

    robot.push_front(robot.back());
    robot.pop_back();
}
void solve(){
    cin>>n>>k;
    int a;
    for(int i=0;i<n*2;i++){
        cin>>a;
        arr.push_back(a);
        robot.push_back(0);
    }
    step=0;
    while(true){
        robotMove();
        robotPut();
        int tmp=0;
        for(int i=0;i<2*n;i++){
            if(arr[i]==0){
                tmp++;
            }
        }
        if(tmp>=k){
            cout<<step+1;
            return;
        }
        step++;
    }
}
 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}