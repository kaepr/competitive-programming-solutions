#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    cout << (60 * (h2 - h1) + m2 - m1 - k);

    return 0;
}