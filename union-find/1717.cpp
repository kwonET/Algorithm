#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m,a,b,c;
vector <int> arr;

int Find(int a){
    if(arr[a]==a) return a;
    else{
        return arr[a]=Find(arr[a]);
    }
}
void Union(int a,int b){
    int aRoot=Find(a);
    int bRoot=Find(b);
    if(aRoot>bRoot){
        arr[aRoot]=bRoot;
    }else if(aRoot<bRoot){
        arr[bRoot]=aRoot;
    }
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        arr.push_back(i);
    }
    while(m--){
        cin>>a>>b>>c;
        if(a==0){
            Union(b,c);
        }else if(a==1){
            if(Find(b)==Find(c)){
                cout<<"YES"<<"\n";
            }else {
                cout<<"NO"<<"\n";
            }
        }
    }

    return 0;
}