#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int m;
    cin >> m;
    int acc = 0;
    int n = s.size();
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            acc++;
        arr[i] = acc;
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << arr[r - 1] - arr[l - 1] << "\n";
    }

    return 0;
}