#include <bits/stdc++.h>
using namespace std;

int main(){
   int k,count=0;
   string s;
   cin>>s;
   while(s.length()>1){
       k=0;
       for(int i=0; i<(int)s.length(); i++) k+=(s[i] - '0');
       s = to_string(k);
       count++;
   }
   cout<<count<<"\n";
    return 0;
}