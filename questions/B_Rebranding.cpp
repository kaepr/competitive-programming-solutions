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

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    //cout << s << "\n";

    int a[150];
    for(int i=97; i<=122; i++)
        a[i] = i;
    

    for(int i=0; i<m; i++){
        char x,y;
        cin>>x>>y;
        for(int j = 97; j<=122; j++){
            if(a[j]==x)
                a[j] = y;
            else if(a[j]==y)
                a[j] = x;
        }
    }

    for(int i=0; i<n; i++){
        s[i] = a[s[i]];
        cout<<s[i];
    }

    return 0;
}