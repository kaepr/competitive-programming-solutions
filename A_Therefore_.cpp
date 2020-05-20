#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int t = n % 10;
    if (t == 2 || t == 4 || t == 5 || t == 7 || t == 9)
    {
        cout << "hon";
    }
    else if (t == 0 || t == 1 || t == 6 || t == 8)
        cout << "pon";
    else
    {
        cout << "bon";
    }
    return 0;
}