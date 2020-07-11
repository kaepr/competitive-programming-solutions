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

    int a=0,b=0,c=0,d=0;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s=="AC")
            a++;
        if(s=="TLE")
            b++;
        if(s=="WA")
            c++;
        if(s=="RE")
            d++;
    }
    cout<<"AC x "<<a<<"\n";
    cout<<"WA x "<<c<<"\n";
    cout<<"TLE x "<<b<<"\n";
    cout<<"RE x "<<d<<"\n";

      
    return 0;
}