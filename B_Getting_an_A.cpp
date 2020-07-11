#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int sum, int n){
    return sum*10 >= n*45;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int sum = 0;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
        sum+=x;
    }

    sort(v.begin(), v.end());
    int ans = 0;
    while(!check(sum,n)){
        sum += 5 - v[ans];
        ans++;
    }
    cout<<ans<<"\n";

    return 0;
}