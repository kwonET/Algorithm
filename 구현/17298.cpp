#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
using namespace std;
int n,a;
stack<int> st;
stack<int> st2;
map<int,int> m;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        st.push(a);
    }
    int idx=n-1;
    while(!st.empty()){
        int t=st.top();
        st.pop();
        m[idx]=-1;
        while(!st2.empty()){
            int last= st2.top();
            if(last>t){
                m[idx]=last;
                break;
            }
            else{
                st2.pop();
            }
        }
        st2.push(t);
        idx--;
    }
    for(int i=0;i<n;i++){
        cout<<m[i]<<" ";
    }
    return 0;
}