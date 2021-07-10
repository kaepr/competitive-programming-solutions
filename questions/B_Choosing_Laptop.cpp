#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef struct laptop
{
    int cost;
    int speed;
    int ram;
    int hdd;
    int old;
} laptop;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    laptop lp[n];

    for (int i = 0; i < n; i++)
    {
        cin >> lp[i].speed >> lp[i].ram >> lp[i].hdd >> lp[i].cost;
        lp[i].old = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (lp[i].speed < lp[j].speed && lp[i].ram < lp[j].ram && lp[i].hdd < lp[j].hdd)
                {
                    lp[i].old = 1;
                }
            }
        }
    }

    int min_cost = 1e9;
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (lp[i].old == 0)
        {
            if (lp[i].cost < min_cost)
            {
                min_cost = lp[i].cost;
                ind = i + 1;
            }
        }
    }
    cout << ind << "\n";
    return 0;
}