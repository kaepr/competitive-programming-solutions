#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }
    //number of elements greater than
    auto it = cnt.begin();
    int times = 0;
    int morethan2 = 0;
    for (auto it = cnt.begin(); it != cnt.end(); it++)
    {
        int t = it->second;
        if (t >= n / 2)
        {
            times++;
        }
        if (t > 2)
        {
            morethan2 = 1;
        }
        //cout<<t<<'\n';
    }

    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(a[i]);

    if (morethan2 == 1)
    {
        cout << "NO\n";
    }
    else if (n % 2 == 0 && st.size() <= n / 2)
    {
        cout << "NO\n";
    }else if(n%2!=0 && st.size() < (n+1)/2){
        cout<<"NO\n";
    }
    else
    {
        if (st.size() > n / 2)
        {
            if (times % 2 == 0)
            {
                cout << "YES\n";
                vector<int> one1;
                vector<int> one2;
                for (auto it = cnt.begin(); it != cnt.end(); it++)
                {
                    while (it->second > 0)
                    {
                        if (it->second % 2 == 0)
                        {
                            int elm = it->first;
                            one1.push_back(elm);
                            it->second = it->second - 1;
                        }
                        else
                        {
                            int elm = it->first;
                            one2.push_back(elm);
                            it->second = it->second - 1;
                        }
                    }
                }
                for (auto x : one1)
                    cout << x << " ";

                sort(one2.begin(), one2.end(), greater<int>());

                for (auto x : one2)
                    cout << x << " ";

                cout << "\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if (st.size() <= n / 2)
        {
            cout << "NO\n";
        }
    }
    
    //cout<<"new test case\n";
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

/*
if (times % 2 == 0)
            {
                cout << "YES\n";
                vector<int> one1;
                vector<int> one2;
                for (auto it = cnt.begin(); it != cnt.end(); it++)
                {
                    while (it->second > 0)
                    {
                        if (it->second % 2 == 0)
                        {
                            int elm = it->first;
                            one1.push_back(elm);
                            it->second = it->second - 1;
                        }
                        else
                        {
                            int elm = it->first;
                            one2.push_back(elm);
                            it->second = it->second - 1;
                        }
                    }
                }
                for (auto x : one1)
                    cout << x << " ";

                sort(one2.begin(), one2.end(), greater<int>());

                for (auto x : one2)
                    cout << x << " ";

                cout << "\n";
            }
*/