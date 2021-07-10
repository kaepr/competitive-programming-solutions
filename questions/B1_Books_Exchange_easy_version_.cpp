#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;


void solve()
{
    int n;
    cin>>n;
    vector<int> p(n);
    for(int i=0; i<n; i++)
        cin>>p[i], p[i]--;
    
    for(int i=0; i<n; i++){
        int cnt = 0;
        int k = i;
        do{
            ++cnt;
            k = p[k];
        }while(k!=i);
        cout<<cnt<<" ";
    }
    cout<<"\n";
    

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