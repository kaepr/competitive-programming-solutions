#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int input(int i, int j)
{
    cout << "? " << i + 1 << " " << j + 1 << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> ans(n);
    int mx = 0;
    for (int i = 1; i < n; i++)
    {
        int a = input(mx, i);
        int b = input(i, mx);
        if (a > b)
        {
            ans[mx] = a;
            mx = i;
        }
        else
        {
            ans[i] = b;
        }
    }
    ans[mx] = n;
    cout<<"! ";
    for(auto x : ans)
        cout<<x<<" ";
    


    return 0;
}