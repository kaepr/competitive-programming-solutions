#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t = n;
    int i = 0;
    string decoded;

    while (n)
    {
        if (n % 2 != 0)
        {
            decoded += s[i];
        }
        else
        {
            decoded = s[i] + decoded;
        }

        n -= 1;
        i += 1;
    }
    cout << decoded;
    return 0;
}