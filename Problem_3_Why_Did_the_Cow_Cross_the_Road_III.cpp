#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    freopen("cowqueue.in","r",stdin);
    freopen("cowqueue.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int enter[n];
    int dur[n];
    bool processed[n];

    for (int i = 0; i < n; i++)
    {
        cin >> enter[i] >> dur[i];
        processed[i] = false;
    }

    int nextAvailableTime = 0;
    for (int i = 0; i < n; i++)
    {
        int nextToEnter = -1;
        for (int j = 0; j < n; j++)
        {
            if (!processed[j] && (nextToEnter == -1 || enter[j] < enter[nextToEnter]))
            {
                nextToEnter = j;
            }
        }

        processed[nextToEnter] = true;
        if (enter[nextToEnter] > nextAvailableTime)
        {
            nextAvailableTime = enter[nextToEnter] + dur[nextToEnter];
        }
        else
        {
            nextAvailableTime = nextAvailableTime + dur[nextToEnter];
        }
    }
    cout << nextAvailableTime << "\n";

    return 0;
}