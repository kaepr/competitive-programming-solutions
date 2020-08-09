#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int a, b;
    cin >> a >> b;
    int chef = 0;
    int rick = 0;
    
    if(a%9==0){
        chef += a/9;
    }else{
        chef = a/9 + 1;
    }

    if(b%9==0){
        rick += b/9;
    }else{
        rick = b/9 + 1;
    }


    if (chef == rick)
    {
        cout << 1 << " " << chef << '\n';
    }
    else if (chef > rick)
    {
        cout << 1 << " " << rick << '\n';
    }
    else
    {
        cout << 0 << " " << chef << '\n';
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