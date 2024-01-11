#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;
int n,m,a,b;
queue <int> q;
int arr[32001];
int visited[32001];
vector <int> result;
vector <int> adjlist[32001];
int main(){
    cin>>n>>m;
    memset(arr, 0, sizeof(int)*(n+1));
    memset(visited, 0, sizeof(int)*(n+1));
    while(m--){
        cin>>a>>b;
        adjlist[a].push_back(b);
        arr[b]+=1;
    }
   
    for(int i=1;i<=n;i++){
        if(arr[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int tmp=q.front();
        q.pop();

        cout<<tmp<<" ";
        for(auto adj:adjlist[tmp]){
            if(--arr[adj]==0){
                q.push(adj);
            }
        }
    }
    return 0;}