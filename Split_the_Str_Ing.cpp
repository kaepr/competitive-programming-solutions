#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

const int mod = 1e9 + 7;

#define pb push_back
#define f first
#define s second
#define mp make_pair

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve()
{
    int n;
    cin>>n;
    string s, s_orig;
    cin >> s;
    reverse(s.begin(), s.end());
    char first = s[0];
    bool flag = false;
    for(int i=1; i<n; i++){
        if(s[i]==first){
            flag = true;
            break;
        }
    }
    if(flag){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
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