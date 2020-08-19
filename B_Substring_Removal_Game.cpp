#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;


void solve()
{
    string s;
    cin>>s;
    int c1=0,co=0;
    vector<int> len;
    for(int i=0; i<s.length(); i++){
        int j = i;
        if(s[i]=='1')
            co++;
        else if(s[i]=='0'){
            if(co==0){
                //continue
            }else{
                len.push_back(co);
                co=0;
            }
        }
    }
    len.push_back(co);
    int ans = 0;
    sort(len.begin(), len.end());
    reverse(len.begin(), len.end());
    for(int i=0; i<len.size(); i+=2){
        ans += len[i];
    }
    cout<<ans<<"\n";
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