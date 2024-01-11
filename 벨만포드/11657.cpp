#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 987654321
using namespace std;
int n,m,a,b,c;
vector <pair<int,pair<int,int>>> arr;
long long D[505];
int bellman(){
    D[1]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int from=arr[j].first;
            int to=arr[j].second.first;
            int cost=arr[j].second.second;
            if(D[from]==MAX)continue;
            if(D[to]>D[from]+cost){
                D[to]=D[from]+cost;
                if(i==n){
                    return -1;
                }
            }
        }
    }
    return 1;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        arr.push_back({a,{b,c}});
    }
    fill_n(D,n+1,MAX);
    int result=bellman();
    if(result==-1){
        cout<<-1;
        return 0;
    }
    else if(result==1){
        for(int i=2;i<=n;i++){
            if(D[i]==MAX){
                cout<<-1<<"\n";
            }
            else{
                cout<<D[i]<<"\n";
            }
            
        }
    }
    return 0;
}