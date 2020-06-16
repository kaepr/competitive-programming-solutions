#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, v, b, w;
    cin >> a >> v >> b >> w;
    int t;
    cin >> t;
    int flag = 0;
    for (int i = 1; i <= t; i++)
    {
        int fa = a + v * i;
        int fb = b + w * i;
        if(fa==fb){
            flag=1;
        }
    }


    if (flag)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}