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
    string s;
    cin >> s;
    int n = s.length();
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }

    int ans = 0;

    //deal with casses when count is 2
    int freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }

    int cntOnes = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == 1)
        {
            cntOnes++;
        }
    }

    // for (int i = 0; i < 26; i++)
    // {
    //     char x = 'a' + i;
    //     cout << x << " " << freq[i] << " " << i << "\n";
    // }

    while (true)
    {
        int maxx = *max_element(freq, freq + 26);

        int largestIndex = -1;
        for (int i = 0; i < 26; i++)
        {
            if (maxx == freq[i])
            {
                largestIndex = i;
                break;
            }
        }
        int minn = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0 && freq[i] < minn && i != largestIndex)
            {
                minIndex = i;
                minn = freq[i];
            }
        }
        if (minIndex == -1)
        {
            minIndex = largestIndex;
        }
        // trace(minIndex, largestIndex, freq[minIndex], freq[largestIndex]);
        if (freq[largestIndex] < 2)
        {
            break;
        }
        if (freq[largestIndex] == freq[minIndex] && largestIndex == minIndex && freq[largestIndex] < 3)
        {
            break;
        }

        ans++;
        freq[largestIndex] = freq[largestIndex] - 2;
        freq[minIndex]--;
    }
    cout << ans << "\n";
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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