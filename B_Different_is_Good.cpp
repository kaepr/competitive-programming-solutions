#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    string s;
    cin>>s;

    set<char> st;
    for(int i=0; i<n; i++){
        st.insert(s[i]);
    }

    if(n>26){
        cout<<-1<<"\n";
    }else{
        cout<<n - st.size()<<"\n";
    }

    return 0;
}