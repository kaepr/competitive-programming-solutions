#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, n;
    cin >> x >> n;
    int p[105];
    fill(p, p+105, 0);
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        p[a] = 1;
    }

    int ans;
    int diff = 1e9;
    for(int i=0; i<105; i++){
        if(diff > abs(i-x) && p[i]==0){
            ans =i;
            diff = abs(i-x);
        }
    }
    cout<<ans<<"\n";

    return 0;
}