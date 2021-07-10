//https://codeforces.com/contest/236/problem/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int d=0;
    int flag = 0;
    for(int i=0; i<s.length(); i++){
        for(int j=0; j<i; j++){
            if(s[j]==s[i])
                flag=1;
        }
        if(flag==0)
            d++;
        flag=0;
    }
    if(d%2!=0)
        cout<<"IGNORE HIM!";
    else
        cout<<"CHAT WITH HER!";

    
    return 0;
}