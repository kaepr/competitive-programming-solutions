#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    ll op = 0, rem = 0, bo = 0, bc = 0;
    ll ans = n * a;
    for (auto i : s)
    {
        if (i == '(')
            bo++;
        else
            bc++;
    }
    int x = min(bc, bo);

    bo = bo - x;
    bc = bc - x;

    ll back = 0, add = 0, del = 0;

    for (auto i : s)
    {
        if (i == '(')
            op++;
        else if (i == ')' && op)
            op--;
        else
        {
            if (bc > 0)
            {
                back += a;
                bc--;
            }
            else if (b < a)
            {
                back += b;
                add++;
            }
            else if (2 * a < b)
            {
                back += 2 * a;
                del++;
            }
            else
            {
                back += b;
                add++;
            }
        }
    }

    if (op)
    {
        op -= del;
        op -= add;
        if (op)
        {
            back += a * op;
        }
    }

    if (bc)
    {
        back += a * bc;
    }

    ans = min(ans, back);

    cout << ans << "\n";
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