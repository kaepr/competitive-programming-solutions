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

string mult(string a, int i)
{
    string ans = "";
    for (int j = 1; j <= i; j++)
    {
        ans += a;
    }
    return ans;
}

bool divisible(string a, string b)
{
    //a should be bigger
    if (a.length() < b.length())
    {
        swap(a, b);
    }
    int len1 = a.length();
    int len2 = b.length();
    int times = len1 / len2;

    string c = b;
    for (int i = 1; i <= times + 1; i++)
    {
        if (a == c)
        {
            return true;
        }
        c += b;
    }

    return false;
}

bool divisible2(string a, string b)
{
    //a should be bigger
    if (a.length() < b.length())
    {
        return false;
    }
    int len1 = a.length();
    int len2 = b.length();
    int times = len1 / len2;

    string c = b;
    for (int i = 1; i <= times + 1; i++)
    {
        if (a == c)
        {
            return true;
        }
        c += b;
    }

    return false;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    // trace(a, b);
    // if (divisible(a, b))
    // {
    //     cout << "HAPPENS\n";
    // }
    // cout << mult(a, 3) << "\n";
    // trace(a);
    string div = "";

    for (int i = 0; i < b.length(); i++)
    {
        div += a[i];
        if (divisible(a, div) && divisible(b, div))
        {
            string temp = div;
            while (true)
            {
                if (divisible2(temp, a) && divisible2(temp, b))
                {
                    cout << temp << "\n";
                    return;
                }
                temp += div;
            }
        }
    }

    cout << -1 << "\n";
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