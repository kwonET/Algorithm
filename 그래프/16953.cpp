#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
long long t;
int a,b;
queue <pair<long long,int>> q;
string s;
// 주어진 숫자에서 2를 곱하거나, 1을 추가하는 식으로 bfs의 가지를 뻗어나감
// 원하는 숫자보다 커지면 그 즉시 종료
int main(){
    cin>>a>>b;
    q.push({a,1});
    while(!q.empty()){
        long long num=q.front().first;
        int cnt=q.front().second;
        q.pop();
        // cout<<num<<" ";
        if(num==b){
            cout<<cnt;
            return 0;
        }
        //2를 곱한다
        if(num*2<=b){
            q.push({num*2,cnt+1});
        }
        //1을 더한다
        if(num*10+1<=b){
            q.push({num*10+1,cnt+1});
        }
    }
    cout<<-1;
    return 0;
}