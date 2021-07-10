#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

#define pb push_back
#define F first
#define S second
#define mp make_pair

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = INT_MAX;
    if (n == 1)
    {
        cout << a[0] << "\n";
    }
    else if (n == 2)
    {
        cout << max(a[0], a[1]) << "\n";
    }
    else if (n == 3)
    {
        sort(a, a + n);
        cout << max(a[0] + a[1], a[2]) << "\n";
    }
    else if (n == 4)
    {
        sort(a, a + n);

        // int ans7 = max(a[0] + a[1] + a[2], a[3]);

        // int ans1 = max(a[0], a[1]) + min(a[2], a[3]);
        // int ans2 = max(a[0], a[2]) + min(a[3], a[1]);
        // // int ans3 = max(a[0], a[3]) + min(a[1], a[2]);
        // // int ans4 = max(a[1], a[2]) + min(a[0], a[3]);
        // int ans5 = max(a[1], a[3]) + min(a[2], a[0]);
        // int ans6 = max(a[2], a[3]) + min(a[0], a[1]);

        set<int> st;
        st.insert(a[0]);
        st.insert(a[1]);
        st.insert(a[2]);
        st.insert(a[3]);

        int ans1 = max(a[0] + a[1] + a[2], a[3]);
        int ans2 = max(a[0] + a[1], a[2] + a[3]);
        int ans3 = max(a[0] + a[2], a[1] + a[3]);
        int ans4 = max(a[0] + a[3], a[2] + a[1]);

        vi v;
        // trace(ans1);
        // trace(ans2);
        // trace(ans3);
        // trace(ans4);
        // trace(ans5);
        // trace(ans6);

        v.pb(ans1);
        v.pb(ans2);
        v.pb(ans3);
        v.pb(ans4);
        // v.pb(ans5);
        // v.pb(ans6);

        sort(v.begin(), v.end());
        cout << v[0] << "\n";
    }
}

/*
    done2, 3, 0, 1
    done3, 2, 0, 1
    3, 2, 1, 0
    2, 3, 1, 0
    1, 3, 2, 0
    3, 1, 2, 0
    2, 1, 3, 0
    1, 2, 3, 0
    done0, 1, 2, 3
    done 1, 0, 2, 3
    done2, 0, 1, 3
    done0, 2, 1, 3
    done1, 2, 0, 3
    done2, 1, 0, 3
    done3, 1, 0, 2
    done1, 3, 0, 2
    done0, 3, 1, 2
    done3, 0, 1, 2
    done1, 0, 3, 2
    done0, 1, 3, 2
    done0, 2, 3, 1
    done2, 0, 3, 1
    done3, 0, 2, 1
    done0, 3, 2, 1
    
*/

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