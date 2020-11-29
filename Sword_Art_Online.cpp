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

void solve()
{
    int health = 1000, atk = 1000;
    bool possible = false;
    int exp = 5000;

    int n;
    cin >> n;
    vector<pair<int, int>> enemy;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        enemy.pb(mp(x, y));
    }

    // for (auto x : enemy)
    // {
    //     cout << x.first << " " << x.second << "\n";
    // }

    for (int i = 0; i <= 5000; i++)
    {
        int newHealth = health + i;
        int newAtk = atk + exp - i;
        bool currFlag = true;

        for (auto x : enemy)
        {
            if (newHealth <= 0)
            {
                currFlag = false;
                break;
            }
            int enemyHealth, enemyAtk;
            enemyHealth = x.first;
            enemyAtk = x.second;
            // bool flag2 = true;

            while (newHealth >= 0 && enemyHealth >= 0)
            {
                newHealth -= enemyAtk;
                enemyHealth -= newAtk;
            }

            if (newHealth <= 0 && enemyHealth <= 0)
            {
                continue;
            }

            if (newHealth <= 0 && enemyHealth > 0)
            {
                currFlag = false;
            }

            // int minHitsGiven;

            // if (enemyHealth % newAtk == 0)
            // {
            //     minHitsGiven = enemyHealth / newAtk;
            // }
            // else
            // {
            //     minHitsGiven = enemyHealth / newAtk + 1;
            // }

            // // cout<<"Minimum hits given are : "<<minHitsGiven<<"\n";

            // int totalDamageGiven = minHitsGiven * newAtk;
            // int totalDamageTaken = minHitsGiven * enemyAtk;

            // enemyHealth -= totalDamageGiven;
            // newHealth -= totalDamageTaken;
        }

        if (currFlag)
        {
            possible = true;
            break;
        }
    }

    if (possible)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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