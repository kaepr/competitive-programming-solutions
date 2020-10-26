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
    int t;
    cin>>t;
    int a[t];
    for(int i=0; i<t; i++)
        cin>>a[i];
    
    vi ans;
    for(int i=0; i<t; i+=2){
        int first = a[i];
        int second = a[i+1];
        if(first > 0 && second > 0){
            ans.pb(-1 * second);
            ans.pb( first);
        }else if(first < 0 && second > 0){
            ans.pb(second);
            ans.pb(abs(first));
        }else if(first > 0 && second < 0){
            ans.pb(abs(second));
            ans.pb(first);
        }else{
            ans.pb(second);
            ans.pb(abs(first));
        }
    }
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";
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