#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int pt[5] = {500, 1000, 1500, 2000, 2500};
int tot = 0;
int m[10], w[10];
int main()
{
    for (int i = 1; i <= 5; ++i)
        cin >> m[i];
    for (int i = 1; i <= 5; ++i)
        cin >> w[i];

    int s, u;
    cin >> s >> u;
    tot = 100 * s - 50 * u;
    for (int i = 1; i <= 5; ++i)
        tot += max(pt[i - 1] - pt[i - 1] * m[i] / 250 - 50 * w[i], pt[i - 1] / 10 * 3);

    cout << tot << endl;
}