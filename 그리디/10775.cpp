#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int g,p,a,i,result;
int aRoot,bRoot;
vector <int> parr;
int arr[100001];

int find(int a){
    if(arr[a]==a) {return a;}
    else {return arr[a]=find(arr[a]);} //parent한테 조상을 넘겨줌
}

void union_(int a,int b){
     aRoot=find(a);
     bRoot=find(b);
     if(aRoot!=bRoot){
        arr[aRoot]=bRoot;
     }
}

int main(){
    cin>>g>>p;
    memset(arr,0,sizeof(arr));
    for(i=0;i<100001;i++){
        arr[i]=i;
    }
    while(p--){
        cin>>a;
        parr.push_back(a);
    }
    //도킹시킬 때 g번과 g-1번 루트를 합친다
    //도킹이 완료된 자리엔 불가하고, 그 앞에 도킹을 해야하기 떄문에
    for(auto pg:parr){
        if(find(pg)==0){
            break;
        }
        result+=1;
       union_(find(pg),find(pg)-1);
    }
    cout<<result;
    return 0;
}