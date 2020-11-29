#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

#define pb push_back
#define f first
#define s second
#define mp make_pair

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

int Tfinal(int mi, int ci, int y, int amount)
{
    int ans = (mi * ci + amount * y) / (mi + amount);
    return ans;
}

double Krequired(double mi, double ci, double TFinal, double y)
{
    double ans = (mi * ci - TFinal * mi) / (TFinal - y);
    return ans;
}

void solve()
{
    double x, y, Q, n;
    cin >> x >> y >> Q >> n;
    /*

    x : total amount of cold water
    y : current temperature of our water
    Q : target temperature
    n : number of bottles

    <amount of water, temperature>

    */
    vector<pair<double, double>> temp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        temp.pb(mp(x, y));
    }
    vector<double> kreq;
    for (auto bottle : temp)
    {
        double amt = bottle.first;
        double tempC = bottle.second;
        if (tempC <= Q)
        {
            // cout << "This bottle already less than Q\n";
            ans++;
        }
        else
        {
            double kr = Krequired(bottle.first, bottle.second, Q, y);
            
            // cout << "Amount of water : " << kr << "\n";


            kreq.pb(kr);
        }
    }
    sort(kreq.begin(), kreq.end());
    double total = x;
    int cnt = 0;
    for (auto water : kreq)
    {
        total -= water;
        if (total < 0)
        {
            break;
        }
        cnt++;
    }
    cout << ans + cnt << "\n";
}

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