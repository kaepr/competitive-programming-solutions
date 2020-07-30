#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int ans = 0;
    for(int x=0; x<=4000; x++)
        for(int y = 0; y<=4000; y++){
            int zc = n - (x*a + y*b);
            if(zc < 0)
                break;
            double z = (zc / (double) c);
            if(z == (int) z)
                ans = max(ans, (int) z + y + x);
        }
    
    cout<<ans<<"\n";

    return 0;
}