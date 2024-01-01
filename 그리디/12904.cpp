#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
string s,t;
int result;
int main(){
    cin>>s>>t;
    while(true){
        if(t.length()==s.length()){ //길이가 같아진 경우
            if(t==s){
                cout<<1;
                return 0;
            }
            else{
                cout<<0;
                return 0;
            }
        }
        if(t[t.length()-1]=='A'){
            t.pop_back();
        }else{
            t.pop_back();
            reverse(t.begin(),t.end());
        }
    }
}