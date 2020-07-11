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

    int n, k;
    cin >> n >> k;
    if (k > n || k == 1 && n > 1)
    {
        cout << "-1";
    }
    else
    {
        int af = 1, bf = 0;
        int d = k - 2;
        if (d < 0)
            d = 0;
        for (int i = 0; i < n - d; i++)
        {
            if (af)
            {
                cout << "a";
                af = 0;
                bf = 1;
            }
            else if (bf)
            {
                cout << "b";
                bf = 0;
                af = 1;
            }
        }
        char c = 'c';
        for (int i = 0; i < d; i++)
        {
            cout << c;
            c++;
        }
    }

    return 0;
}