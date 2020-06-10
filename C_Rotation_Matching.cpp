#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int a[N],b[N], pos[N];
int n;
map<int, int> offset;

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        pos[a[i]] = i;
    }

    for(int i=1; i<=n; i++){
        cin>>b[i];
    }

    for(int i=1; i<=n; i++){
        int ind = pos[b[i]] - i;
        if(ind < 0){
            ind+=n;
        }
        offset[ind]++;
    }
    int ans = 0;
    for(auto &it: offset)
        ans = max(ans, it.second);
    
    cout<<ans<<"\n";

    return 0;
}
