#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
using namespace std;
int n,a,d,idx,dc,cost;
vector<int> c;
vector<pair<int,int>> p[11];
vector<int> arr;
bool visited[11];
int result=1e9;
void dfs(int depth){
    if(depth==n){
        cost=0;
        vector<int> tmp(c);
        // for(int k=0;k<n;k++){
        //     cout<<tmp[k]<<" ";
        // }
        for(auto x:arr){
            cost+=tmp[x];
            for(auto pt:p[x]){
                int next=pt.first;
                int ncost=pt.second;
                tmp[next]-=ncost;
                if(tmp[next]<1){
                    tmp[next]=1;
                }
            }
        }
        if(result>cost){result=cost;}
        return;
    }
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        visited[i]=true;
        arr[depth]=i;
        dfs(depth+1);
        visited[i]=false;
        arr[depth]=0;    
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;    
    arr.resize(n);
    c.resize(n);
    for(int i=0;i<n;i++){
        cin>>a;
        c[i]=a;
    }
    for(int i=0;i<n;i++){
        cin>>d;
        for(int j=0;j<d;j++){
            cin>>idx>>dc;
            p[i].push_back({idx-1,dc});
        }
    }
    dfs(0);
    cout<<result<<endl;
    return 0;
}