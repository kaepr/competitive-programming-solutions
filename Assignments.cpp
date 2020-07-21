#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int N;
ll dp[(1 << 20) + 1];
int topic[20][20];

void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> topic[i][j];

    fill(dp, dp + (1 << N) + 1, 0);
    int maxi = (1 << N);
    for (int mask = 0; mask < maxi; mask++)
    {
        int n = 0;
        int temp = mask;
        while (temp > 0)
        {
            if (temp & 1)
                n++;
            temp >>= 1;
        }
        cout << "mask right now is " << mask << "\n";
        cout << "count of set bits is " << n << "\n";
        for (int i = 0; i < N; i++)
        {
            if (topic[n][i] == 1 && (mask & (1 << i)) == 0)
            {
                cout<<"true for n : "<<n<<" i : "<<i<<"\n";
                if (n == 0)
                    dp[mask | (1 << i)] = 1;
                else
                    dp[mask | (1 << i)] += dp[mask];
            }
        }
        cout << "printing dp right now \n";
        for (int i = 0; i < maxi; i++)
        {
            cout << dp[i] << " ";
        }
        cout << "\n";
        cout << "new mask now "
             << "\n";
    }
    cout << dp[maxi - 1] << "\n";
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