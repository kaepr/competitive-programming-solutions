#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
string s;
int sz;
vector<int> dp(1e6, -1);

int cnt(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    if (n == 2)
    {
        string s2 = s.substr(sz - 2);
        int num = stoi(s2);
        s2.clear();
        if (num >= 10 && num <= 26)
            return 2;

        return 1;
    }

    int &ans = dp[n];
    if (ans != -1)
        return ans;

    ans = cnt(n - 1);
    string s2 = s.substr((sz - n), 2);
    int num = stoi(s2);
    s2.clear();
    if (num >= 10 && num <= 26)
        ans += cnt(n - 2);

    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    sz = s.size();
    cout << cnt(sz) << "\n";

    return 0;
}