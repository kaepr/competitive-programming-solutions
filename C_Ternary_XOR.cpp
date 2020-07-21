#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;


void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string a(n, '0'), b(n, '0');
    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            a[i] = '1';
            b[i] = '0';
            for(int j = i+1; j<n; j++){
                b[j] = s[j];
            }
            break;
        }
        else{
            a[i] = b[i] = '0' + (s[i] - '0')/2;
        }
    }
    cout<<a<<"\n"<<b<<"\n";
}

int main()
{
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