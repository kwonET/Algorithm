#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,arr[4000][4],i,j;
vector<int> arr1;
vector<int> arr2;
int l,r;
long long result,lnum,rnum;

int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<4;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr1.push_back(arr[i][0]+arr[j][1]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr2.push_back(arr[i][2]+arr[j][3]);
        }
    }

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    r=arr2.size()-1; // r의 인덱스 정확히

    while(r>=0 && l<arr1.size()){ // 둘 중에 하나 만족 시 -> 탈출 -> and 사용
        if(arr1[l]+arr2[r]<0){
            l++;
        }
        else if(arr1[l]+arr2[r]>0){
            r--;
        }
        if(arr1[l]+arr2[r]==0){
            int orgL=l;
            lnum=0;rnum=0;
            while(arr1[l]+arr2[r]==0){ // 굳이 처음부터 다시 순회할 필요 없음
                if(l>=arr1.size())break; // break 구문 작성 주의
                l++;
                lnum++;
            }
            while(arr1[orgL]+arr2[r]==0){
                if(r<0)break;
                r--;
                rnum++;
            }
            result+=(lnum*rnum); 
        }
    }
    cout<<result;
    return 0;
}