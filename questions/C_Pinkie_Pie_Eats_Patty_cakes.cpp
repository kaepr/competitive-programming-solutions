#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;
    // cout<<n<<"\n";
    int arr[n] = {0};
    int freq[n+1] = {0};

    for(int i=0; i<n; i++){
        cin>>arr[i];
        freq[arr[i]]++;
        // cout<<arr[i]<<" ";
        // cout<<freq[arr[i]]<<" ";
    }
    // cout<<"\n";
    
    int max = 0;
    int maxfreq = 0;
    for(int i=1; i<=n; i++){
        if(freq[i] > max){
            max = freq[i];
            maxfreq = 1;
        }else if(freq[i] == max){
            maxfreq++;
        }
    }
    // cout<<maxfreq<<" "<<max<<"\n";
     int answer = (n-maxfreq)/(max-1)-1;
     cout<<answer<<"\n";

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