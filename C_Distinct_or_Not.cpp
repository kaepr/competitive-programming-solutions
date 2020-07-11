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
    set<int> st;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        st.insert(temp);
    }
    if(st.size() == n){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
       
    return 0;
}