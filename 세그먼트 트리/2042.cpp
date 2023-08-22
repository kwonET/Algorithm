#include <cstdio>
using namespace std;
int n,m,k,i,a,b,c;
int input[1000001],tree[4000001];
int init(){
}
int update(){
}
int sum(){
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++){
		scanf("%d",&input[i]);
	}
	for(i=0;i<m+k;i++){
		scanf("%d %d %d",&a,&b,&c);
		if(a==1) update();
		else if (a==2) sum();
	}
	return 0;
}


