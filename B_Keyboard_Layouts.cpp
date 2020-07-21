#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1,s2,s3;
    cin>>s1>>s2;
    map<char, char> change;
    for(int i=0; i<s1.length(); i++){
        change[s1[i]] = s2[i];
    }
    cin>>s3;
    char ch;
    for(int i=0; i < s3.length(); i++){
        if(isdigit(s3[i])){
            cout<<s3[i];
            continue;
        }
        if(change[s3[i]]){
            cout<<change[s3[i]];
        }else{
            if(isupper(s3[i])){
                ch = change[s3[i] + 32] - 32;
                cout<<ch;
            }else{
                ch = change[s3[i] - 32] + 32;
                cout<<ch;
            }
        }
    }


    return 0;
}