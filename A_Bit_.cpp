#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int x=0;
    int n;
    cin>>n;
    while(n>0){
        string s;
        cin>>s;
        if(s == "X++" || s == "++X")
            x++;
        else
            x--;
        n--;
    }
    cout<<x<<"\n";
      
    return 0;
}