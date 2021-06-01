#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

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

const int MOD = 1e9 + 7;

bool chk(int str_len, int sub_len, string s, int k, int freq_a[], int freq_b[])
{

    // total substrings = str_len - sub_len + 1
    // trace(sub_len);
    bool f = false;
    for (int i = 0; i < str_len - sub_len + 1; i++)
    {
        int left_index = i, right_index = i + sub_len - 1;
        int a_cnt = 0, b_cnt = 0;
        if (left_index == 0)
        {
            a_cnt = freq_a[right_index];
            b_cnt = freq_b[right_index];
        }
        else
        {
            a_cnt = freq_a[right_index] - freq_a[left_index - 1];
            b_cnt = freq_b[right_index] - freq_b[left_index - 1];
        }

        int a_needed = sub_len - b_cnt;
        int b_needed = sub_len - a_cnt;

        if (a_needed <= k || b_needed <= k)
        {
            f = true;
        }
    }

    return f;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int curr = 0, cnt = 0, back_ptr = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'b')
        {
            curr++;
        }

        while (back_ptr < i && curr > k)
        {
            back_ptr++;
            if (s[back_ptr] == 'b')
            {
                curr--;
            }
        }

        cnt = max(cnt, i - back_ptr);
    }

    int ans = cnt;

    curr = 0, cnt = 0, back_ptr = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            curr++;
        }

        while (back_ptr < i && curr > k)
        {
            back_ptr++;
            if (s[back_ptr] == 'a')
            {
                curr--;
            }
        }

        cnt = max(cnt, i - back_ptr);
    }
    ans = max(ans, cnt);
    cout << ans << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}