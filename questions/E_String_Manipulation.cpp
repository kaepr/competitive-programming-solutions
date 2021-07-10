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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (k == n)
    {
        cout << "\n";
    }
    else
    {
        int freq[26] = {0};
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        // for (int i = 0; i < 26; i++)
        // {
        //     trace(i, freq[i]);
        // }

        //reducing k from this freq array
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] >= k)
            {
                freq[i] = freq[i] - k;
                k = 0;
            }
            else if (k > freq[i])
            {
                k -= freq[i];
                freq[i] = 0;
            }
        }

        // for (int i = 0; i < 26; i++)
        // {
        //     trace(i, freq[i]);
        // }

        vector<pair<char, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.PB(MP(s[i], 0));
        }

        // for (int i = 0; i < n; i++)
        // {
        //     if (freq[s[i] - 'a'] > 0)
        //     {
        //         cout << s[i];
        //         freq[s[i]]--;
        //     }
        // }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << v[i].F << " " << v[i].S << "\n";
        // }

        reverse(v.begin(), v.end());

        // reverse()

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if (freq[i] <= 0)
                    {
                        break;
                    }
                    // trace(s[j]);
                    // trace(v[j].F);
                    char temp = i + 'a';
                    // cout << temp << "\n";
                    if (v[j].F == temp && v[j].S != 1 && freq[i] > 0)
                    {
                        v[j].S = 1;
                        freq[i]--;
                    }
                }
            }
            // while (freq[i] > 0)
            // {
            //     for (int j = 0; j < n; j++)
            //     {
            //         if (freq[i] <= 0)
            //         {
            //             break;
            //         }
            //         char temp = s[j] + 'a';
            //         cout << temp << "\n";
            //         if (v[j].F == temp && v[j].S != 1 && freq[i] > 0)
            //         {
            //             v[j].S = 1;
            //             freq[i]--;
            //         }
            //     }
            //     freq[i]--;
            // }
        }
        reverse(v.begin(), v.end());

        
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].S == 1)
            {
                cout << v[i].F;
            }
            // cout << v[i].F;
        }
    }
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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