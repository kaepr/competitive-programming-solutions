#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<int> st;
    for(int i=0; i<n; i++){
        char a = s[i];
        int elm = 0;
        if(a=='(')
            elm = 1;
        else
            elm = -1;
        
        if(st.empty())
            st.push(elm);
        else if(elm==1){
            st.push(elm);
        }else if(elm==-1){
            int high = st.top();
            if(high == 1){
                st.pop();
            }else{
                st.push(elm);
            }
        }
    }
    cout<<st.size()/2<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }   
    return 0;
}