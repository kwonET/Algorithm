#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
using namespace std;
vector <int> arr;
void dfs(int idx, int t){
    if(idx==t){
        for(int k=0;k<arr.size();k++){
            cout<<arr[k]<<" ";
        }cout<<"\n";
        return;
    }
    else{
        for(int i=0;i<=9;i++){
            if(idx>1&&arr[idx-1]>i) { 
                cout<<"ㅁㅁ:"<<arr[idx-1]<<" "<<i<<"\n";
                arr.push_back(i);
                dfs(idx+1,2);
                arr.pop_back();
            }
        }
    }
}
int main(){
    dfs(0,2);
    return 0;
}