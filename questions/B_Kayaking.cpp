#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n << 1);
    for(auto &i : v)
        cin>>i;
    
    int ans = INT_MAX;

    sort(v.begin(), v.end());

    for(int i=0; i<2*n; i++){
        for(int j=i +1; j< 2*n; j++){
            int sum = 0;
            int ptr = -1;
            for(int k=0; k<2*n; k++){
                if(k==i || k==j)
                    continue;
                
                sum += v[k]*ptr;
                ptr *= -1;
            }
            ans = min(ans, sum);
        }
    }
    cout<<ans<<"\n";

    return 0;
}