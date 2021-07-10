#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    int one = 0;
    int two = 0;
    int ptr = 0;
    if (x == y)
    {
        if (x % 2 == 0)
        {
            one = x / 2 + 1;
            two = x / 2 - 1;
        }
        else
        {
            one = x / 2 + 1;
            two = x / 2;
        }
    }
    else if (x > y)
    {
        one = y;
        two = 0;
    }
    else if (y > x)
    {
        one = max(x,y-x);
        two = min(x,y-x);
        if(one > x)
            one = x;
        
        if(two > one)
            swap(one, two);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ptr % 2 == 0)
            {
                arr[i][j] = one;
            }
            else
            {
                arr[i][j] = two;
            }
            ptr++;
        }
    }

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += arr[i][j];
            //cout<<arr[i][j]<<" ";
        }
        //cout<<"\n";
    }
    cout << sum << "\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}