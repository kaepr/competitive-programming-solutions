#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve()
{
    int n;
    cin >> n;
    int a[2 * n];
    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];

    // to get n - 1 elements, to remove

    vector<pair<int, int>> ind;
    vector<int> even_index;
    vector<int> odd_index;

    int cnt = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (a[i] % 2 == 0)
        {
            even_index.push_back(i + 1);
        }
        else if (a[i] % 2 != 0)
        {
            odd_index.push_back(i + 1);
        }
    }

    for (int i = 0; i < even_index.size(); i++)
    {
        //cout << " even index is " << even_index[i] << "\n";
    }

    for (int i = 0; i < odd_index.size(); i++)
    {
        //cout << " odd index is " << odd_index[i] << "\n";
    }
    //cout << even_index.size() << " size of index "
    //<< "\n";
    for (int i = 0; i < even_index.size(); i += 2)
    {
        if (i == even_index.size() - 1)
        {
            break;
        }
        else
        {
            int a = even_index[i];
            int b = even_index[i + 1];
            //cout << "even pair added is" << a << " " << b << "\n";
            ind.push_back({a, b});
        }
    }

    for (int i = 0; i < odd_index.size(); i += 2)
    {

        if (i == odd_index.size() - 1)
        {
            break;
        }
        else
        {
            int a = odd_index[i];
            int b = odd_index[i + 1];
            //cout << "odd pair added is" << a << " " << b << "\n";
            ind.push_back({a, b});
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << ind[i].first << " " << ind[i].second << "\n";
    }

    //cout << "done once\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}