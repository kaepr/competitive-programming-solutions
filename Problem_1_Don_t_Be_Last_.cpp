#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

bool cmp(pair<string, int> a,pair<string, int> b)
{
    return a.second < b.second;
}

int main()
{
    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    map<string, int> mp;
    mp["Bessie"] = 0;
    mp["Elsie"] = 0;
    mp["Daisy"] = 0;
    mp["Gertie"] = 0;
    mp["Annabelle"] = 0;
    mp["Maggie"] = 0;
    mp["Henrietta"] = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        int x;
        cin >> s;
        cin >> x;
        if (mp[s] == 0)
        {
            mp[s] = x;
        }
        else
        {
            mp[s] += x;
        }
    }
    
    vector<pair<string, int>> v;
    for (auto i : mp)
    {
        v.push_back(make_pair(i.first, i.second));
    }

    sort(v.begin(), v.end(), cmp);

    set<int> st;
    for(auto it : v){
        st.insert(it.second);
    }
    if(st.size()==1){
        cout<<"Tie\n";
    }else{
        int lowest = *st.begin();
        int num=0;
        int cnt=0;
        string ans;
        for(auto i : v){
            if(i.second > lowest){
                num = i.second;
                ans = i.first;
                break;
            }
        }
        for(auto i : v){
            if(num==i.second){
                cnt++;
            }
        }
        if(cnt == 1){
            cout<<ans<<"\n";
        }else{
            cout<<"Tie\n";
        }
    }


    return 0;
}