#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    string s;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int freq[26] = {0};
    for(int i=0; i<n; i++){
        freq[s[i] - 'a']++;
    }
    int f=1;
    for(int i=0; i<26; i++)
        if(freq[i]==0)
            f=0;

    if(f)
        cout<<"YES\n";
    else
        cout<<"NO\n";
      
    return 0;
}