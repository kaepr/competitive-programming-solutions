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
    string s;
    cin >> s;
    int n = s.length();
    reverse(s.begin(), s.end());
    int ptr = 0;

    // cout << s << "\n";
    int cnt = 0;

    char check = '0';
    for (int i = 0; i < n -1 ; i++)
    {
        if (s[i] == check)
        {
            cnt++;
        }
        else
        {
            cnt += 2;
            check = '1';
        }
    }

    if (check == '1')
    {
        cnt++;
    }

    cout << cnt << "\n";

    return 0;
}