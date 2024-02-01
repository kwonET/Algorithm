// 강의실 배정
// <시작 시간, 종료 시간>
// 시작 시간이 빠른 것 대로 정렬
// 가장 먼저 시작하는 것부터 배정 -> 해당 종료 시점 이상인 것 중 가장 빠른 시작 시간 배정
// 위 단계를 visited에 check하며 queue가 빌 때까지 큐에 계속 넣고 empty일 때까지 방문하기.

// #include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll=long long;
using pii =pair<int,int>;
using pll=pair<ll,ll>;
#define all(v) v.begin(),v.end()
int n, s,e;
vector<pii> arr;
priority_queue<int, vector<int>, greater<int>> pq; //오름차순
int st,et,result;
void solve(){
    pq.push(arr[0].second);
    for(int i=1;i<n;i++){ 
        // i번째의 종료 시간 push
        pq.push(arr[i].second); 
        // 마지막 종료시간이 다음 시작시간보다 작거나 같아야 pop
        if(pq.top()<=arr[i].first){
            pq.pop();
        }
    }
    //pq에 남아있는 종료시간 개수가 강의실의 개수
    cout<<pq.size();
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        arr.push_back({s,e});
    }
    sort(all(arr));
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}