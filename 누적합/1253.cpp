#include <cstdio>
#include <algorithm>
using namespace std;
int arr[2001],sum;
int i,n,l,r,answer,flag;
void tp(int target,int idx){
    while(l<r){
        if(arr[l]+arr[r]<target){
            l++;
        }
        else if(arr[l]+arr[r]>target){
            r--;
        }
        else{  
            if(l!=idx && r!=idx){
                answer+=1; break;
            }
            else{
                if(l==idx){l++;}
                else if (r==idx){r--;}
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d", &arr[i]);
    sort(arr,arr+n);
    for(i=0;i<n;i++){
        if(arr[i]!=0){flag=1; break;}
    }
    if(flag==0){ printf("%d",n);}
    else{
        for(i=0;i<n;i++){
            sum=0; r=n-1;l=0;
            tp(arr[i],i);
        }
        printf("%d",answer);
    }
    return 0;
}