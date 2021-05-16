#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

#define PB push_back
#define F first
#define S second
#define MP make_pair

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
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
    string s;
    cin >> s;
    vi t_pos, m_pos;
    int m_cnt = 0, t_cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'T')
        {
            t_cnt++;
            t_pos.PB(i);
        }
        else
        {
            m_cnt++;
            m_pos.PB(i);
        }
    }

    if (m_cnt * 2 != t_cnt)
    {
        cout << "NO\n";
        return;
    }

    int tc = 0, mc = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'T')
        {
            tc++;
        }
        else
        {
            mc++;
        }
        if (mc > tc)
        {
            // cout << "here\n";
            cout << "NO\n";
            return;
        }
    }
    // trace(s);
    reverse(s.begin(), s.end());
    // trace(s);
    tc = 0, mc = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'T')
        {
            tc++;
        }
        else
        {
            mc++;
        }

        if (mc > tc)
        {
            // cout << "here\n";
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    // int cnt[m_pos.size()] = {0};
    // int ptr1 = 0, ptr2 = 0, ptr3 = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (s[i] == 'T')
    //     {
    //         cnt[ptr1]++;
    //         ptr1++;
    //     }
    //     else if ()
    // }

    // if (m_cnt * 2 != t_cnt)
    // {
    //     cout << "NO\n";
    //     return;
    // }

    // int to_fill = m_pos.size();
    // // trace(s);
    // bool f = true;
    // int satisfy = 0;
    // int tsz = t_pos.size();
    // for (int i = 0; i < m_pos.size(); i++)
    // {
    //     int pos = m_pos[i];

    //     //if there exists a T before and after pos

    //     auto bnd = upper_bound(t_pos.begin(), t_pos.end(), pos);
    //     if (bnd == t_pos.end())
    //     {
    //         cout << "NO\n";
    //         return;
    //     }
    //     int x = bnd - t_pos.begin();
    //     int y = t_pos.end() - bnd;
    //     // trace(x, y);
    //     // trace(m_pos[i]);
    //     // trace(i + 1);
    //     int total_m = i + 1 - satisfy;

    //     if (x < 1 || (tsz - y) < 1)
    //     {
    //         cout << "NO\n";
    //         return;
    //     }

    //     // if (total_m > abc || total_m > abcd)
    //     // {
    //     //     cout << "NO\n";
    //     //     return;
    //     // }
    //     // // trace(abc, abcd);
    //     // there are index amount of elements less than m_pos
    //     // there are t_pos - index amount of T greater than m_pos

    //     // t_pos.erase(t_pos.begin() + t_pos.size() - 1);
    //     // t_pos.erase(t_pos.begin() + low);
    //     satisfy++;
    //     to_fill--;
    // }

    // if (to_fill != 0)
    // {
    //     cout << "NO\n";
    // }
    // else
    // {
    //     cout << "YES\n";
    // }
    // cout << "NEW CASE\n";
    // trace(t_cnt, m_cnt);
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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