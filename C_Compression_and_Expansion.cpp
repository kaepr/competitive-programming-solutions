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

vi find(vector<vector<int>> v, int elm)
{
    // to find and return that vector, which if extended satisfies the equation
    vi ans;

    int ptr = v.size() - 1;

    // if theres exist an array, whose last element is <= elm
    // and if it does not exist in this whole array, then return it
    // trace(elm);
    while (ptr >= 0)
    {
        vi curr_arr = v[ptr];

        int curr_last = curr_arr[curr_arr.size() - 1], curr_len = curr_arr.size();

        if (curr_last == elm)
        {
            // situation like 1.1 , and elm = 1
            if (elm != 1)
            {
                ptr--;
                continue;
            }
            vi tmp = curr_arr;
            tmp.PB(elm);
            bool f = false;
            for (auto x : v)
            {
                if (x == tmp)
                {
                    f = true;
                    break;
                }
            }

            if (f)
            {
                ptr--;
                continue;
            }
            if (tmp > curr_arr)
            {
                return tmp;
            }
        }
        else if (curr_last < elm)
        {
            // situtation like 1.1.1
            /*
            1.1.1
            1.1.2

            and elm = 2
            */

            // trace(elm, curr_last);

            vi tmp = curr_arr;
            tmp[curr_len - 1] = elm;

            // check if this already exists or not

            bool f = false;
            for (auto x : v)
            {
                if (x == tmp)
                {
                    f = true;
                    break;
                }
            }

            if (f)
            {
                ptr--;
                continue;
            }
            if (tmp > curr_arr)
            {
                return tmp;
            }

            // return tmp;
        }
        else if (curr_last > elm)
        {
            if (elm == 1)
            {
                vi tmp = curr_arr;
                tmp.PB(elm);

                bool f = false;
                for (auto x : v)
                {
                    if (x == tmp)
                    {
                        f = true;
                        break;
                    }
                }

                if (f)
                {
                    ptr--;
                    continue;
                }
                if (tmp > curr_arr)
                {
                    return tmp;
                }

                // return tmp;
            }
            else
            {
                ptr--;
                continue;
            }
        }

        ptr--;
    }

    // nothing found
    ans.PB(elm);

    return ans;
}

void solve()
{
    // trace("new");
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> v;

    for (int i = 0; i < n; i++)
    {
        if (v.size() == 0)
        {
            vi tmp;
            tmp.PB(arr[i]);
            v.PB(tmp);
        }
        else
        {
            // something here
            vi tmp = find(v, arr[i]);
            v.PB(tmp);
        }
    }

    for (auto x : v)
    {
        for (int i = 0; i < x.size(); i++)
        {
            if (i == x.size() - 1)
            {
                cout << x[i] << "\n";
            }
            else
            {
                cout << x[i] << ".";
            }
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