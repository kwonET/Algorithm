//https://www.acmicpc.net/blog/view/9
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k,i;
long long arr[1000001], tree[4000002];
long long init(int node, int start, int end){
    if(start==end){
        return tree[node]=arr[start];
    }
    return tree[node]=init(node*2,start,(start+end)/2)+init(node*2+1,(start+end)/2+1,end);
}
long long sum(int node, int start, int end, int left, int right){
    if(start>right || end<left){
        return 0;
    }
    if(left<=start && end<=right){
        return tree[node];
    }
    // 왼쪽 : node * 2 | start | (start + end)/2 
    // 오른쪽 : node * 2 + 1 | (start + end)/2 + 1 | end
    return sum(node*2, start,(start+end)/2,left,right)+sum(node*2+1,(start+end)/2+1,end,left,right);
}
void update(int node, int start, int end,int index, long long diff){
    if(index<start || index>end) return; 
    tree[node]+=diff;
    if(start!=end){
        update(node*2, start, (start+end)/2,index,diff);
        update(node*2+1,(start+end)/2+1, end,index,diff);
    }
}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    init(1,0,n-1);
    for(i=0;i<m+k;i++){
        int a;
        scanf("%d",&a);
        if(a==1){
            int b;
            long long c;
            scanf("%d %lld",&b,&c);
            long long diff=c-arr[b-1];
            arr[b-1]=c;
            update(1,0,n-1,b-1,diff);
        }
        else if(a==2){
            int b, c;
            scanf("%d %d",&b,&c);
            printf("%lld\n",sum(1,0,n-1,b-1,c-1));
        }
    }
    return 0;
}