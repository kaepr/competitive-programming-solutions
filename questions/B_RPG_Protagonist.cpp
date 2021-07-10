#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int p, f;
int cnts, cntw;
int s, w;
int cnt[100005][100005];

int ans(int pRem, int fRem, int swordCnt, int axeCnt, int toAdd)
{
    if (pRem < 0 || fRem < 0)
    {
        cnt[swordCnt][axeCnt] = 0;
        return cnt[swordCnt][axeCnt];
    }

    if (swordCnt > cnts || axeCnt > cntw)
    {
        cnt[swordCnt][axeCnt] = 0;
        return cnt[swordCnt][axeCnt];
    }

    if (cnt[swordCnt][axeCnt] != -1)
    {
        return cnt[swordCnt][axeCnt];
    }

    cnt[swordCnt][axeCnt] = toAdd + max(ans(pRem - s, fRem - w, swordCnt++, axeCnt++, 2), max(ans(pRem - s, fRem, swordCnt++, axeCnt, 1), max(ans(pRem, fRem - w, swordCnt, axeCnt++, 1), max(ans(pRem, fRem - s, swordCnt++, axeCnt, 1),ans(pRem- s, fRem , swordCnt, axeCnt++, 1)));

    return cnt[swordCnt][axeCnt];
}

void solve()
{

    for (int i = 0; i < cnts; i++)
    {
        for (int j = 0; j < cntw; j++)
        {
            cnt[i][j] = -1;
        }
    }

    cin >> p >> f;
    // p and f are capacities
    cin >> cnts >> cntw;

    //number of sword and axes in each shop

    cin >> s >> w;

    //weight of each shop

    int amt = ans(p, f, 0, 0, 0);
    int ans1 = 0;
    for (int i = 0; i < cnts; i++)
    {
        for (int j = 0; j < cntw; j++)
        {
            ans1 = max(cnt[i][j], ans1);
        }
    }
    cout << ans1 << "\n";
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

/*


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





*/