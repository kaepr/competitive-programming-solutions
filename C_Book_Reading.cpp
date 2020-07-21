#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    cin >> q;
    while (q--)
    {
        ll n, m;
        cin >> n >> m;
        ll k = n / m;
        vector<int> digits(10);
        for (int i = 0; i < 10; i++)
        {
            digits[i] = ((i + 1) * m) % 10;
        }
        for(int i=0; i<10; i++){
            cout<<digits[i]<<" ";
        }
        cout<<"\n";
        ll sum = 0;
        for (int i = 0; i < k % 10; i++)
        {
            sum += digits[i];
        }
        cout << sum + k / 10 * accumulate(digits.begin(), digits.end(), (ll)0) << "\n";
    }

    return 0;
}
/*

1 - 20
3,6,9,12,15,18
3,6,9,2,5,8




*/