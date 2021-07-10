#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100;
string arr[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        int moves = 0;
        for (int j = 0; j < n; j++)
        {
            string tmp = arr[j];
            bool found = 0;
            for (int k = 0; k < tmp.size(); k++)
            {
                if (tmp == arr[i])
                {
                    moves += k;
                    found = 1;
                    break;
                }
                rotate(tmp.begin(), tmp.begin() + 1, tmp.end());
            }
            if (!found)
            {
                cout << "-1\n";
                return 0;
            }
        }
        ans = min(ans, moves);
    }
    cout << ans << "\n";

    return 0;
}