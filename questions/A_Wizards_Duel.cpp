#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    double x, ans, a, b, spd;
    cin >> x >> a >> b;
    spd = x / (a + b);
    ans = spd * a;
    cout << ans << "\n";

    return 0;
}