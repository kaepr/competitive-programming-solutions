#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> pos;
    int f=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        pos.push_back(x);
    }
    int ans = INT_MAX;
    int sol = INT_MAX;
    for(auto x : pos){
        if(k%x==0){
            f=1;
            if(k/x < ans){
                sol = x;
                ans = k/x;
            }
        }
    }
    if(f){
        cout<<sol<<"\n";
    }else{
        cout<<-1<<"\n";
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