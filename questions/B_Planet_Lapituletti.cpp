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

#define TRACE̥
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

int h, m;
string s;
int arr[] = {0, 1, 2, 5, 8};

bool timeValid(string strr)
{
    char h1 = strr[0], h2 = strr[1], m1 = strr[2], m2 = strr[3];
    int num1 = h1 - '0';
    int num2 = h2 - '0';
    int num3 = m1 - '0';
    int num4 = m2 - '0';

    int hValue = num1 * 10 + num2;
    int mValue = num3 * 10 + num4;
    if (hValue <= (h - 1) && mValue <= (m - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValid(char h1, char h2, char m1, char m2)
{
    int num1 = h1 - '0';
    int num2 = h2 - '0';
    int num3 = m1 - '0';
    int num4 = m2 - '0';

    if (num1 == 2)
    {
        num1 = 5;
    }
    else if (num1 == 5)
    {
        num1 = 2;
    }

    if (num2 == 2)
    {
        num2 = 5;
    }
    else if (num2 == 5)
    {
        num2 = 2;
    }

    if (num3 == 2)
    {
        num3 = 5;
    }
    else if (num3 == 5)
    {
        num3 = 2;
    }

    if (num4 == 2)
    {
        num4 = 5;
    }
    else if (num4 == 5)
    {
        num4 = 2;
    }

    bool flag = true;
    if (num1 == 0 || num1 == 1 || num1 == 2 || num1 == 5 || num1 == 8)
    {
    }
    else
    {
        return false;
    }

    if (num2 == 0 || num2 == 1 || num2 == 2 || num2 == 5 || num2 == 8)
    {
    }
    else
    {
        return false;
    }

    if (num3 == 0 || num3 == 1 || num3 == 2 || num3 == 5 || num3 == 8)
    {
    }
    else
    {
        return false;
    }

    if (num4 == 0 || num4 == 1 || num4 == 2 || num4 == 5 || num4 == 8)
    {
    }
    else
    {
        return false;
    }

    string strr = "";
    char nh1 = num4 + '0';
    char nh2 = num3 + '0';
    char nm2 = num2 + '0';
    char nm1 = num1 + '0';

    strr += nh1;
    strr += nh2;
    strr += nm2;
    strr += nm1;
    // trace(h1, h2, m1, m2);
    // trace(strr);
    // s += (char)num4 + '0';
    if (timeValid(strr))
    {
        return true;
    }
    else
    {
        return false;
    }
    // return true;
}

string reverse(string strr)
{
    char h1 = strr[0], h2 = strr[1], m1 = strr[3], m2 = strr[4];
    string str = "";
    str += m2;
    str += m1;
    str += ':';
    str += h2;
    str += h1;
    return str;
}

string addTime(string strr)
{
    // cout << "in add time\n";
    // trace(strr);
    //adding minute
    char h1 = strr[0], h2 = strr[1], m1 = strr[3], m2 = strr[4];
    int num1 = h1 - '0';
    int num2 = h2 - '0';
    int num3 = m1 - '0';
    int num4 = m2 - '0';
    int mValue = num3 * 10 + num4;
    mValue++;
    // trace(mValue);
    if (mValue == m)
    {
        //need to increase hour now
        m1 = '0';
        m2 = '0';
        int hValue = num1 * 10 + num2;
        hValue++;
        if (hValue == h)
        {
            //basically everything becomes 00:00
            h1 = '0';
            h2 = '0';
        }
        else
        {
            string temp = to_string(hValue);
            if (hValue < 10)
            {
                h1 = '0';
                h2 = temp[0];
            }
            else
            {
                h1 = temp[0];
                h2 = temp[1];
            }
        }
    }
    else
    {
        string temp = to_string(mValue);
        if (mValue < 10)
        {
            m1 = '0';
            m2 = temp[0];
        }
        else
        {
            m1 = temp[0];
            m2 = temp[1];
        }
    }

    string ans = "";
    ans += h1;
    ans += h2;
    ans += ':';
    ans += m1;
    ans += m2;
    // trace(ans);
    return ans;
}

void solve()
{
    cin >> h >> m;
    cin >> s;
    char h1 = s[0], h2 = s[1], m1 = s[3], m2 = s[4];

    string temp_str = s;

    while (true)
    {
        // trace(s);
        if (isValid(h1, h2, m1, m2))
        {
            cout << s << "\n";
            return;
        }
        else
        {
            string str = addTime(s);
            s = str;
            h1 = str[0], h2 = str[1], m1 = str[3], m2 = str[4];
        }
    }
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