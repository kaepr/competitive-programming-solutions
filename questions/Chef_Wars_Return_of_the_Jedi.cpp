#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int p, h;
    cin >> h >> p;
    int won;
    int move = 1;
    while (1)
    {
        if (p <= 0)
        {
            won = 0;
            break;
        }
        else if (h <= 0)
        {
            won = 1;
            break;
        }
        if (move)
        {
            h = h - p;
            move = 0;
        }
        else if (move == 0)
        {
            p /= 2;
            move = 1;
        }
    }
    if(won){
        cout<<1<<"\n";
    }else{
        cout<<0<<"\n";
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