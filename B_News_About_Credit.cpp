#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,j,k,n;
    cin>>n;
    int a[n];
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        cin>>a[i];
        v.push_back(make_pair(a[i], i));
    }
    sort(v.begin() + 1,v.end());
    reverse(v.begin() + 1, v.end());
    vector<pair<int,int>> v1;
    int cnt = 0;
    queue<int> q;
    q.push(0);
    i = 1;
    while(q.size() && i < n){
        int x = q.front();
        q.pop();
        int x1 = v[x].first;
        while(x1--){
            q.push(i++);
            cnt++;
            v1.push_back(make_pair(v[x].second+1, v[i-1].second + 1));
            if(i==n)
                break;
        }
    }
    if(cnt < n-1){
        cout<<-1<<"\n";
        return 0;
    }else{
        cout<<v1.size()<<"\n";
        for(i=0; i<v1.size(); i++){
            cout<<v1[i].first<<" "<<v1[i].second<<"\n";
        }
    }

    return 0;
}