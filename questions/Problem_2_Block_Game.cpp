#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    freopen("blocks.in","r",stdin);
    freopen("blocks.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int freq[26] = {0};
    for(int i=0; i<n; i++){
        string a,b;
        cin>>a>>b;
        int freq1[26]= {0};
        int freq2[26] = {0};
        for(int j=0; j<a.length(); j++){
            freq1[a[j] - 'a']++;
        }
        for(int j=0; j<b.length(); j++){
            freq2[b[j] - 'a']++;
        }
        for(int j=0; j<26; j++){
            freq[j] += max(freq1[j], freq2[j]);
        }
    }
    for(int i=0; i<26; i++)
        cout<<freq[i]<<"\n";

    

    return 0;
}