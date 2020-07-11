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

    int n, c;
    cin >> n >> c;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> elms;
    elms.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > c)
        {
            //cout<<"all removed\n";
            elms.clear();
            elms.push_back(a[i]);
        }
        else if (a[i] - a[i - 1] <= c)
        {
            //cout<<"elm added\n";
            elms.push_back(a[i]);
        }
        //cout<<"elmenet is "<<a[i]<<"\n";
    }

    // for(auto i : elms){
    //     cout<<i<<" ";
    // }
    //cout<<"\n";
    cout << elms.size()<< "\n";

    return 0;
}