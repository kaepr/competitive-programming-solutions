#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;
    string s(100, 'a');
    cout<<s<<"\n";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(s[x]=='a')
            s[x] = 'b';
        else
            s[x] = 'a';
        cout<<s<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}