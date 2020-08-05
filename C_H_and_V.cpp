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

    int h,w,k;
    cin>>h>>w>>k;
    int ans =0;
    char arr[h][w];
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin>>arr[i][j];
        
    int black;
    for(int i=0; i<(1<<h) - 1; i++){
        for(int j=0; j<(1<<w) - 1; j++){
            black = 0;
            for(int k=0; k<h; k++){
                for(int l =0; l<w; l++){
                    if((i>>k & 1)==0 && (j>>l & 1)==0 && (arr[k][l]=='#'))
                        black++;
                }
            }
            if(black == k)
                ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
