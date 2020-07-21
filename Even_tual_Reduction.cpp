#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char, int> elm;
    int f = 1;
    for(int i=0; i<n; i++){
        elm[s[i]]++;
    }
    for(auto it : elm){
        if(it.second %2 !=0)
            f = 0;
    }
    if(f)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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