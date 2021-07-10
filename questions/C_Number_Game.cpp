#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

const int N = 50000;

bool isPrime(int n)
{
    for (int i = 2; i < min(N, n); i++)
        if (n % i == 0)
            return 0;

    return 1;
}

void solve()
{
    int n;
    cin >> n;
    bool lose = (n == 1);
    if (n > 2 && n % 2 == 0)
    {
        if ((n & (n - 1)) == 0)
            lose = 1;
        else if (n % 4 != 0 && isPrime(n / 2))
            lose = 1;
    }
    if (lose)
        cout << "FastestFinger\n";
    else
        cout << "Ashishgup\n";
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