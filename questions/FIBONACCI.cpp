#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

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

//fibonacci

void multiply(ull F[2][2], ull M[2][2]);
void power(ull F[2][2], ull n);

// Function that returns nth Fibonacci number
ull fib(ull n)
{
    ull F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);

    return F[0][0];
}

// Optimized version of power() in method 4
void power(ull F[2][2], ull n)
{
    if (n == 0 || n == 1)
        return;
    ull M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

void multiply(ull F[2][2], ull M[2][2])
{
    ull x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    ull y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    ull z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    ull w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void solve()
{
    ull a, b, c;
    cin >> a >> b >> c;
    a = fib(a);
    b = fib(b);
    c = fib(c);
    if (b * b > a * c)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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