#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int n,i,j,a,b,result;
int arr[1001];
vector <pair<int,int>> hwInfo;
priority_queue <pair<int,int>> pq;

struct compare{
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        return (a.second>b.second);
    }
};

int main(){
    cin>>n;
    memset(arr,0,sizeof(arr));
    for(i=0;i<n;i++){
        cin>>a>>b;
        hwInfo.push_back({a,b});
    }
    sort(hwInfo.begin(),hwInfo.end(),compare());
    for(auto hw:hwInfo){
        for(j=hw.first;j>0;j--){
            if(arr[j]==0){  //최대한 미뤄서 배치
                arr[j]=hw.second;
                break;
            }
        }
    }
    for(i=0;i<=1000;i++){ //조심, 1000일까지 있을 수 있다
        result+=arr[i];
    }
    cout<<result;
    return 0;
}