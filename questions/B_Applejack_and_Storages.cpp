#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

const int MAX = 100005;
int a[MAX];
int cnt[MAX];

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
        cnt[a[x]]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        int x;
        cin >> c;
        cin>>x;
        if (c == '+')
        {
            a[x]++;
            cnt[a[x]]++;
        }
        else
        {
            cnt[a[x]]--;
            a[x]--;
            
        }

        if (cnt[8] > 0 || cnt[4] >= 2 || (cnt[6] > 0 && cnt[2] >= 2) || cnt[4] > 0 && cnt[2] >= 3)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}