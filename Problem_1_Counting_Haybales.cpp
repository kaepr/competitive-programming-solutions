#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

const int maxn = 100005;

set<int> pos;
map<int, int> compress;
int psums[maxn];

int main()
{
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> vals;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vals.push_back(x);
        pos.insert(x);
    }

    int cnt = 0;
    for (int x : pos)
    {
        compress[x] = cnt++;
    }

    for (int x : vals)
    {
        psums[compress[x]]++;
    }

    for (int i = 1; i < n; i++)
    {
        psums[i] += psums[i - 1];
    }

    for (int i = 0; i < q; i++)
    {
        int ql, qr;
        cin >> ql >> qr;
        auto it1 = pos.lower_bound(ql);
        auto it2 = pos.upper_bound(qr);
        if (it1 == pos.end() || it2 == pos.begin())
        {
            cout << 0 << "\n";
        }
        else
        {
            ql = *it1;
            qr = *(--it2);
            ql = compress[ql], qr = compress[qr];
            cout << psums[qr] - psums[ql - 1] << "\n";
        }
    }

    return 0;
}