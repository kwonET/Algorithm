#include <iostream>
#include <vector>
#include <string.h>
// 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 
// 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 
// 같은 간선은 한 번만 주어진다.
// 연결 정점을 인접 리스트로 관리한 뒤에 방문하지 않은 정점에 대해 연결된 곳을 순회하게 처리

using namespace std;
int n,m,u,v;
int turn;
vector<int> arr[1001];
int visited[1001];
void find(int idx){
    if(visited[idx]!=0){ return; }
    visited[idx]=turn;
    for(int j=0;j<arr[idx].size();j++){
        find(arr[idx][j]);
    }  
}
int main(){
    cin>>n>>m;
    memset(visited,0,sizeof(int)*n);
    while(m--){ 
        cin>>u>>v;
        u-=1;
        v-=1;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0){ turn+=1; }
        find(i);
    }
    cout<<turn;
    return 0;

}