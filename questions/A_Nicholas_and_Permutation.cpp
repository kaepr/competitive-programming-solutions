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

    int n;
    cin >> n;
    int pos[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> pos[i];

    int pos1 = 0, posn = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pos[i] == 1)
            pos1 = i;
        if (pos[i] == n)
            posn = i;
    }
    if (abs(posn - pos1) == n - 1)
    {
        cout << n - 1 << "\n";
    }
    else
    {
        int ans = max(abs(posn - 1), abs(posn - n));
        //cout<<"current max "<<ans<<"\n";
        ans = max(ans, abs(pos1 - n));
        ans = max(ans, abs(pos1 - 1));
        cout << ans << "\n";
    }

    return 0;
}