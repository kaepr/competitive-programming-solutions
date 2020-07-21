#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;
    vector<int> ans(n);
    map<int,int> cnt;
    int size = 2*n;
    int a[size];
    for(int i=0; i<size; i++){
        cin>>a[i];
    }
    for(int i=0; i<size; i++){
        cnt[a[i]]++;
        if(cnt[a[i]]%2==0){
            ans.push_back(a[i]);
        }
    }
    for(auto it : ans){
        if(it!=0){
            cout<<it<<" ";
        }
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