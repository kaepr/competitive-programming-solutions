const int maxn = NN;
const int cat = 2;
long long p[cat], hashmod = 1e9 + 7;
long long pp[cat][maxn];
long long invpp[cat][maxn];
bool pcdone = 0;
struct Hash
{
    vector<long long> h[cat], hr[cat];
    static void precalc()
    {
        if (pcdone)
            return;
        pcdone = 1;
        p[0] = 599;
        p[1] = 937;
        for (int i = 0; i < cat; ++i)
        {
            pp[i][0] = 1;
        }
        for (int j = 0; j < cat; ++j)
        {
            for (int i = 1; i < maxn; ++i)
            {
                pp[j][i] = (pp[j][i - 1] * p[j]) % hashmod;
            }
        }
        for (int j = 0; j < cat; ++j)
        {
            for (int i = 0; i < maxn; ++i)
            {
                invpp[j][i] = inv(pp[j][i]);
            }
        }
    }
    Hash(string s)
    {
        build(s);
    }
    void build(string s)
    {
        precalc();
        for (int i = 0; i < cat; ++i)
        {
            h[i].assign(sz(s), 0);
            hr[i].assign(sz(s), 0);
        }
        for (int i = 0; i < cat; ++i)
        {
            h[i][0] = pp[i][0] * s[0];
        }
        for (int j = 0; j < cat; ++j)
        {
            for (int i = 1; i < sz(s); ++i)
            {
                h[j][i] = (h[j][i - 1] + pp[j][i] * s[i]) % hashmod;
            }
        }
        for (int i = 0; i < cat; ++i)
        {
            hr[i][sz(s) - 1] = pp[i][0] * s[sz(s) - 1];
        }
        for (int j = 0; j < cat; ++j)
        {
            for (int i = sz(s) - 2; i >= 0; --i)
            {
                hr[j][i] = (hr[j][i + 1] + pp[j][sz(s) - i - 1] * s[i]) % hashmod;
            }
        }
    }
    vector<ll> subhash(int l, int r)
    {
        if (l < 0 || r >= sz(h[0]))
        {
            vector<ll> dog;
            for (int i = 0; i < cat; ++i)
            {
                dog.pb(-2);
            }
            return dog;
        }
        if (r < l)
        {
            vector<ll> dog;
            for (int i = 0; i < cat; ++i)
            {
                dog.pb(-1);
            }
            return dog;
        }
        if (l == 0)
        {
            vector<ll> dog;
            for (int i = 0; i < cat; ++i)
            {
                dog.pb(h[i][r]);
            }
            return dog;
        }
        vector<ll> dog;
        for (int i = 0; i < cat; ++i)
        {
            dog.pb((h[i][r] - h[i][l - 1] + hashmod) * invpp[i][l] % hashmod);
        }
        return dog;
    }
    vector<ll> subhashrev(int l, int r)
    {
        if (l < 0 || r >= sz(h[0]))
        {
            vector<ll> dog;
            for (int i = 0; i < cat; ++i)
            {
                dog.pb(-2);
            }
            return dog;
        }
        if (r < l)
        {
            vector<ll> dog;
            for (int i = 0; i < cat; ++i)
            {
                dog.pb(-1);
            }
            return dog;
        }
        if (r == sz(hr[0]) - 1)
        {
            vector<ll> dog;
            for (int j = 0; j < cat; ++j)
            {
                dog.pb(hr[j][l]);
            }
            return dog;
        }
        vector<ll> dog;
        for (int i = 0; i < cat; ++i)
        {
            dog.pb((hr[i][l] - hr[i][r + 1] + hashmod) * invpp[i][sz(hr[i]) - r - 1] % hashmod);
        }
        return dog;
    }
    bool ispalindrome(int l, int r)
    {
        return (subhash(l, r) == subhashrev(l, r));
    }
};