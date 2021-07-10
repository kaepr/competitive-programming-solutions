#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int total = a + b + c;
        int change = total % 7;
        int enhanced_shots = total / 7;
        total -= 2;
        int minn = min(a, min(b, c));
        if (change == 2 && enhanced_shots > 0 && minn >= enhanced_shots && total % 7 == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        t--;
    }

    return 0;
}