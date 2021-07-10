#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

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
    cin >> n;
    int arr[n][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j][i];
        }
    }
    int ans[n];
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; i++)
    {
        int nextPtr = i % n + 1;
        int prevPtr = i - 1;
        if (prevPtr == -1)
        {
            prevPtr = n - 1;
        }
        if (nextPtr == n)
        {
            nextPtr = 0;
        }

        if (ans[prevPtr] == -1 && ans[nextPtr] == -1)
        {
            ans[i] = arr[i][0];
        }
        else if (ans[prevPtr] != -1 && ans[nextPtr] == -1)
        {
            int prevElm = ans[prevPtr];
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] != prevElm)
                {
                    ans[i] = arr[i][j];
                    break;
                }
            }
        }
        else if (ans[prevPtr] != -1 && ans[nextPtr] != -1)
        {
            int nextElm = ans[nextPtr];
            int prevElm = ans[prevPtr];
            // int elmToChoose;
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] != nextElm && arr[i][j] != prevElm)
                {
                    ans[i] = arr[i][j];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
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