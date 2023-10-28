#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int t,i,j, n,m,a[1001],b[1001];
long long result;
int asum[999999],bsum[999999];
int as,bs,idx,bidx;
int main(){
    scanf("%d",&t);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }

    for(i=0;i<n;i++){
        as=0; 
        for(j=i;j<n;j++){
            as+=a[j];
            asum[idx++]=as;
        }
    }
    sort(asum,asum+idx);
    
    for(i=0;i<m;i++){
        bs=0;
        for(j=i;j<m;j++){
            bs+=b[j];
            bsum[bidx++]=bs;
        }
    }
    sort(bsum,bsum+bidx);
    // for(i=0;i<idx;i++){

    // printf("%d ",asum[i]);
    // }
    //     for(i=0;i<bidx;i++){

    // printf("%d ",bsum[i]);
    // }
    
    
    for(i=0;i<idx;i++){
        int target=t-asum[i];
        result+=upper_bound(bsum,bsum+bidx,target)-lower_bound(bsum,bsum+bidx,target);
        
    }

    cout<<result<<endl;
    return 0;
}