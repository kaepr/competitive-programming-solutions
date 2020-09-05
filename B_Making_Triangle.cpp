#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int check(int a, int b, int c)
{
    if (a == b || b == c || a == c)
        return 0;

    if (a + b > c && b + c > a && c + a > b)
        return 1;

    return 0;
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {

                if (check(a[i], a[j], a[k]))
                    cnt++;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}