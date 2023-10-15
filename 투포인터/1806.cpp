#include <cstdio>
using namespace std;
int n,s,i,arr[100001],l,r,result,sum,less;
int main(){
    scanf("%d %d", &n,&s);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    // 배열의 총합이 s에 못미치는 경우 -> 0 return 
    for(i=0;i<n;i++){
        less+=arr[i];
    }
    if(less<s){
        printf("0");
        return 0;
    }

    sum=arr[l]; result=n;
    while(l<n && l<=r){
        if(sum<=s){ // sum이 s보다 같거나 작은 경우
            if(r==n-1){ // r이 n-1인 경우 더이상 배열의 길이를 늘릴 수 없다.
                if(r-l<result){
                    result=r-l;
                }
                printf("%d",result+1);
                return 0; // early return
            }
            if(sum==s){ // 같을 땐 result값을 갱신
                if(r-l<result){
                    result=r-l;
                }
            }
            sum+=arr[++r]; // r값을 더 크게 만들어 더 긴 배열로 만들어줌
        }
        else if(sum>s){ // sum이 s보다 큰 경우
            if(r-l<result){ // 이상에 해당되므로 result 값 갱신
                result=r-l;
            }
            sum-=arr[l++]; // l값을 더 크게 만들어 길이가 더 작은 배열에 대해서도 조사해볼 수 있도록 함
        }
    }
    printf("%d",result+1);
    return 0;
}