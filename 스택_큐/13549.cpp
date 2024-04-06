// #include <bits/stdc++.h>

#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll=long long;
using pii =pair<int,int>;
using pll=pair<ll,ll>;
#define all(v) v.begin(),v.end()
bool visited[100001];
priority_queue <pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
int n,k;

void solve(){
    cin>>n>>k;
    pq.push({0,n});
    visited[n]=true;
    while(!pq.empty()){
        int c=pq.top().first;
        int t=pq.top().second;
        pq.pop();

        if(t==k){
            cout<<c;
            break;
        }

        if(t*2<100001&& !visited[t*2]){
            pq.push({c,t*2}); 
            visited[t*2]=true;
        }
        if(t+1<100001&& !visited[t+1]){
            pq.push({c+1,t+1});
            visited[t+1]=true;
        }
        if(t-1>=0&& !visited[t-1]){
            pq.push({c+1,t-1});
            visited[t-1]=true;
        }   
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}