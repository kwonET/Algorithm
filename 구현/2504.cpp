#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
string str;
int i,result,tmp;
stack<char> ss;
int main(){
    getline(cin,str);
    int l=str.length()-1;
    for(i=l;i>=0;i--){
        if(str[i]==')'||str[i]==']'){
            ss.push(str[i]);
        }
        else if(str[i]=='('){
            if(ss.top()==')'){
                ss.pop();
                if(str[i+1]=='['||str[i+1]=='('){
                    result+=2;
                }
                else if(str[i+1]==']'||str[i+1]==')'){
                    tmp*=2;
                }
            }
        }
        else if(str[i]=='['){

        }
    }
    while(!ss.empty()){
        char target=ss.top();
        if(target==']'){

        }
    }
    return 0;
}