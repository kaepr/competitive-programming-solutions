#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    vector<int> ans;
    int p1 = 0, p2 = n - 1;

    int flag = 0;

    while (p1 <= p2)
    {
        if (flag)
        {
            ans.push_back(arr[p1]);
            p1++;
            flag = 0;
        }
        else
        {
            ans.push_back(arr[p2]);
            p2--;
            flag = 1;
        }
    }

    int sol;

    if (n % 2 == 0)
    {
        sol = n / 2 - 1;
    }
    else
    {
        sol = n / 2;
    }
    cout << sol << "\n";
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}