#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    while (n > 0)
    {
        ans += n;
        n -= 2;
    }
    cout << ans << "\n";

    return 0;
}

/*

length : times
4 - 1
3 - 2
2 - 3
1 - 4

*/