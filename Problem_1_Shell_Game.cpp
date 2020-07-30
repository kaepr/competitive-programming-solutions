#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;



int main()
{
    freopen("shell.in","r",stdin);
	freopen("shell.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int ans =0;
    int one=0,two=0,three=0;
    int a[n],b[n],g[n];
    for(int i=0 ;i <n; i++){
        cin>>a[i]>>b[i]>>g[i];
    }

    //when shell is at first 1
    int curr = 1,start=1;
    for(int i=0; i<n; i++){
        if(a[i]==curr)
            curr = b[i];
        else if(b[i]==curr)
            curr = a[i];
        if(curr == g[i])
            one++;
    }
    curr = 2,start=2;
    for(int i=0; i<n; i++){
        if(a[i]==curr)
            curr = b[i];
        else if(b[i]==curr)
            curr = a[i];
        if(curr == g[i])
            two++;
    }
    curr = 3,start=3;
    for(int i=0; i<n; i++){
        if(a[i]==curr)
            curr = b[i];
        else if(b[i]==curr)
            curr = a[i];
        if(curr == g[i])
            three++;
    }
    cout<<max(one,max(two,three))<<"\n";


    return 0;
}