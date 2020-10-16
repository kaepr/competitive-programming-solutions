#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int x){
    int l = 0, int r = n-1;
    
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    so
    // for(auto x : a){
    //     cout<<x<<" ";
    // }

    int ptr1 = 0;
    int ptr2 = n - 1;
    vector<int> b;
    bool flag = true;
    while (ptr1 <= ptr2)
    {
        if (flag)
        {
            flag = false;
            b.push_back(a[ptr2]);
            ptr2--;
        }
        else
        {
            flag = true;
            b.push_back(a[ptr1]);
            ptr1++;
        }
    }

    int cnt = 0;
    for (int i = 1; i < b.size() - 1; i++)
    {
        if (b[i] < b[i - 1] && b[i] < b[i + 1])
            cnt++;
    }

    cout << cnt << "\n";
    for (auto x : b)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int t = 1;
    while (t > 0)
    {
        solve();
        t--;
    }
}