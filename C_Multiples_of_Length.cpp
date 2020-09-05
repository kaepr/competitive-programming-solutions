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
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    if (N == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "1 1\n";
            cout << -A[0] << "\n";
            A[0] = 0;
        }
        return 0;
    }

    cout << "1 " << N << "\n";
    for (int i = 0; i + 1 < N; ++i)
        cout << -A[i] * N << " ";

    cout << "0\n";

    cout << "1 " << N - 1 << "\n";

    for (int i = 0; i + 1 < N; ++i)
        cout << A[i] * (N - 1) << " ";


    cout << "\n";


    cout << N << " " << N << "\n";


    cout << -A[N - 1] << "\n";

    return 0;
}