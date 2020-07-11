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

    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n];
    ll b[m];
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    for (ll i = 0; i < m; i++)
        cin >> b[i];

    ll indA = 0;
    ll indB = 0;
    ll time = 0;
    ll cnt = 0;
    int flag = 1;
    while (flag)
    {
        if (a[indA] <= b[indB] && indA < n && indB < m)
        {
            time += a[indA];
            if (time >= k)
            {
                flag = 0;
            }
            else
            {
                indA++;
                cnt++;
            }
        }
        else if (a[indA] > b[indB] && indA < n && indB < m)
        {
            time += b[indB];
            if (time >= k)
            {
                flag = 0;
            }
            else
            {
                indB++;
                cnt++;
            }
        }
        //cout<<"time is "<<time<<"\n";
    }
    cout << cnt << "\n";
    return 0;
}