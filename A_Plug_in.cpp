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

    string s;
    cin >> s;
    int i=1;
    while(i<s.size()){
        if(s[i] == s[i-1]){
            s.erase(i-1, 2);
            i--;
        }else
            i++;
    }
    cout<<s<<"\n";

    return 0;
}