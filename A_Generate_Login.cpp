#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, d;
    cin >> s >> d;
    cout<<s[0];
    for(int i=1; i<s.length(); i++){
        if(s[i] >= d[0])
            break;
        cout<<s[i];
    }
    cout<<d[0];
    return 0;
}