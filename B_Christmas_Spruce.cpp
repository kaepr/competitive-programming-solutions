#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> p(n), deg(n);
    for(int i=1; i<n; i++){
        cin>>p[i];
        p[i]--;
        deg[p[i]]++;
    }

    vector<int> leaves(n);
    for(int i=0; i<n; i++){
        if(deg[i]==0){
            leaves[p[i]]++;
        }
    }
    for(int i=0; i<n; i++){
        if(deg[i] > 0 && leaves[i] < 3){
            cout<<"No\n";
            return 0;
        } 
    }
    cout<<"Yes\n";


    return 0;
}